// © 2016 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html
/*
********************************************************************************
*   Copyright (C) 2005-2015, International Business Machines
*   Corporation and others.  All Rights Reserved.
********************************************************************************
*
* File WINTZ.CPP
*
********************************************************************************
*/

#include "unicode/utypes.h"

#if U_PLATFORM_USES_ONLY_WIN32_API

#include "wintz.h"
#include "charstr.h"
#include "cmemory.h"
#include "cstring.h"

#include "unicode/ures.h"
#include "unicode/unistr.h"
#include "unicode/ustring.h"
#include "uresimp.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define VC_EXTRALEAN
#define NOUSER
#define NOSERVICE
#define NOIME
#define NOMCX
#include <windows.h>

U_NAMESPACE_BEGIN

// Note these constants and the struct are only used when dealing with the fallback path for RDP sessions.

// This is the location of the time zones in the registry on Vista+ systems.
// See: https://docs.microsoft.com/windows/win32/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information
#define WINDOWS_TIMEZONES_REG_KEY_PATH L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones"

// Max length for a registry key is 255. +1 for null.
// See: https://docs.microsoft.com/windows/win32/sysinfo/registry-element-size-limits
#define WINDOWS_MAX_REG_KEY_LENGTH 256

#if U_PLATFORM_HAS_WINUWP_API == 0

// This is the layout of the TZI binary value in the registry.
// See: https://docs.microsoft.com/windows/win32/api/timezoneapi/ns-timezoneapi-time_zone_information
typedef struct _REG_TZI_FORMAT {
    LONG Bias;
    LONG StandardBias;
    LONG DaylightBias;
    SYSTEMTIME StandardDate;
    SYSTEMTIME DaylightDate;
} REG_TZI_FORMAT;

#endif // U_PLATFORM_HAS_WINUWP_API

#ifdef SUPPORT_XP_CODE

#define MAX_LENGTH_ID 40

/* The layout of the Tzi value in the registry */
typedef struct {
    int32_t bias;
    int32_t standardBias;
    int32_t daylightBias;
    SYSTEMTIME standardDate;
    SYSTEMTIME daylightDate;
} TZI;

/**
 * Various registry keys and key fragments.
 */
static const char CURRENT_ZONE_REGKEY[] = "SYSTEM\\CurrentControlSet\\Control\\TimeZoneInformation\\";
static const char STANDARD_NAME_REGKEY[] = "StandardName";
static const char STANDARD_TIME_REGKEY[] = " Standard Time";
static const char TZI_REGKEY[] = "TZI";
static const char STD_REGKEY[] = "Std";

/**
 * HKLM subkeys used to probe for the flavor of Windows.  Note that we
 * specifically check for the "GMT" zone subkey; this is present on
 * NT, but on XP has become "GMT Standard Time".  We need to
 * discriminate between these cases.
 */
static const char* const WIN_TYPE_PROBE_REGKEY[] = {
    /* WIN_9X_ME_TYPE */
    "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Time Zones",

    /* WIN_NT_TYPE */
    "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones\\GMT"

    /* otherwise: WIN_2K_XP_TYPE */
};

/**
 * The time zone root subkeys (under HKLM) for different flavors of
 * Windows.
 */
static const char* const TZ_REGKEY[] = {
    /* WIN_9X_ME_TYPE */
    "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Time Zones\\",

    /* WIN_NT_TYPE | WIN_2K_XP_TYPE */
    "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones\\"
};

/**
 * Flavor of Windows, from our perspective.  Not a real OS version,
 * but rather the flavor of the layout of the time zone information in
 * the registry.
 */
enum { WIN_9X_ME_TYPE = 1, WIN_NT_TYPE = 2, WIN_2K_XP_TYPE = 3 };

static int32_t gWinType = 0;

static int32_t detectWindowsType()
{
    int32_t winType;
    LONG result;
    HKEY hkey;

    /* Detect the version of windows by trying to open a sequence of
    probe keys.  We don't use the OS version API because what we
    really want to know is how the registry is laid out.
    Specifically, is it 9x/Me or not, and is it "GMT" or "GMT
    Standard Time". */
    for (winType = 0; winType < 2; winType++) {
        result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, WIN_TYPE_PROBE_REGKEY[winType], 0, KEY_QUERY_VALUE, &hkey);
        RegCloseKey(hkey);

        if (result == ERROR_SUCCESS) {
            break;
        }
    }

    return winType + 1; /* +1 to bring it inline with the enum */
}

static LONG openTZRegKey(HKEY* hkey, const char* winid)
{
    char subKeyName[110]; /* TODO: why 96?? */
    char* name;
    LONG result;

    /* This isn't thread safe, but it's good enough because the result should be constant per system. */
    if (gWinType <= 0) {
        gWinType = detectWindowsType();
    }

    uprv_strcpy(subKeyName, TZ_REGKEY[(gWinType != WIN_9X_ME_TYPE)]);
    name = &subKeyName[strlen(subKeyName)];
    uprv_strcat(subKeyName, winid);

    if (gWinType == WIN_9X_ME_TYPE) {
        /* Remove " Standard Time" */
        char* pStd = uprv_strstr(subKeyName, STANDARD_TIME_REGKEY);
        if (pStd) {
            *pStd = 0;
        }
    }

    result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKeyName, 0, KEY_QUERY_VALUE, hkey);
    return result;
}

static LONG getTZI(const char* winid, TZI* tzi)
{
    DWORD cbData = sizeof(TZI);
    LONG result;
    HKEY hkey;

    result = openTZRegKey(&hkey, winid);

    if (result == ERROR_SUCCESS) {
        result = RegQueryValueExA(hkey, TZI_REGKEY, NULL, NULL, (LPBYTE)tzi, &cbData);
    }

    RegCloseKey(hkey);

    return result;
}

static LONG getSTDName(const char* winid, char* regStdName, int32_t length)
{
    DWORD cbData = length;
    LONG result;
    HKEY hkey;

    result = openTZRegKey(&hkey, winid);

    if (result == ERROR_SUCCESS) {
        result = RegQueryValueExA(hkey, STD_REGKEY, NULL, NULL, (LPBYTE)regStdName, &cbData);
    }

    RegCloseKey(hkey);

    return result;
}

static LONG getTZKeyName(char* tzKeyName, int32_t length)
{
    HKEY hkey;
    LONG result = FALSE;
    DWORD cbData = length;

    if (ERROR_SUCCESS == RegOpenKeyExA(HKEY_LOCAL_MACHINE, CURRENT_ZONE_REGKEY, 0, KEY_QUERY_VALUE, &hkey)) {
        result = RegQueryValueExA(hkey, "TimeZoneKeyName", NULL, NULL, (LPBYTE)tzKeyName, &cbData);
    }

    return result;
}

U_INTERNAL const char* U_EXPORT2 uprv_detectWindowsTimeZone()
{
    UErrorCode status = U_ZERO_ERROR;
    UResourceBundle* bundle = NULL;
    char* icuid = NULL;
    char apiStdName[MAX_LENGTH_ID];
    char regStdName[MAX_LENGTH_ID];
    char tmpid[MAX_LENGTH_ID];
    int32_t len;
    int id;
    int errorCode;
    UChar ISOcodeW[3]; /* 2 letter iso code in UTF-16*/
    char ISOcodeA[3]; /* 2 letter iso code in ansi */

    LONG result;
    TZI tziKey;
    TZI tziReg;
    TIME_ZONE_INFORMATION apiTZI;

    BOOL isVistaOrHigher;
    BOOL tryPreVistaFallback;
    OSVERSIONINFO osVerInfo;

    /* Obtain TIME_ZONE_INFORMATION from the API, and then convert it
    to TZI.  We could also interrogate the registry directly; we do
    this below if needed. */
    uprv_memset(&apiTZI, 0, sizeof(apiTZI));
    uprv_memset(&tziKey, 0, sizeof(tziKey));
    uprv_memset(&tziReg, 0, sizeof(tziReg));
    GetTimeZoneInformation(&apiTZI);
    tziKey.bias = apiTZI.Bias;
    uprv_memcpy((char*)&tziKey.standardDate, (char*)&apiTZI.StandardDate, sizeof(apiTZI.StandardDate));
    uprv_memcpy((char*)&tziKey.daylightDate, (char*)&apiTZI.DaylightDate, sizeof(apiTZI.DaylightDate));

    /* Convert the wchar_t* standard name to char* */
    uprv_memset(apiStdName, 0, sizeof(apiStdName));
    wcstombs(apiStdName, apiTZI.StandardName, MAX_LENGTH_ID);

    tmpid[0] = 0;

    id = GetUserGeoID(GEOCLASS_NATION);
    errorCode = GetGeoInfoW(id, GEO_ISO2, (LPWSTR)ISOcodeW, 3, 0);
    u_strToUTF8(ISOcodeA, 3, NULL, ISOcodeW, 3, &status);

    bundle = ures_openDirect(NULL, "windowsZones", &status);
    ures_getByKey(bundle, "mapTimezones", bundle, &status);

    /*
    Windows Vista+ provides us with a "TimeZoneKeyName" that is not localized
    and can be used to directly map a name in our bundle. Try to use that first
    if we're on Vista or higher
    */
    uprv_memset(&osVerInfo, 0, sizeof(osVerInfo));
    osVerInfo.dwOSVersionInfoSize = sizeof(osVerInfo);
    GetVersionEx(&osVerInfo);
    isVistaOrHigher = osVerInfo.dwMajorVersion >= 6; /* actually includes Windows Server 2008 as well, but don't worry about it */
    tryPreVistaFallback = TRUE;
    if (isVistaOrHigher) {
        result = getTZKeyName(regStdName, sizeof(regStdName));
        if (ERROR_SUCCESS == result) {
            UResourceBundle* winTZ = ures_getByKey(bundle, regStdName, NULL, &status);
            if (U_SUCCESS(status)) {
                const UChar* icuTZ = NULL;
                if (errorCode != 0) {
                    icuTZ = ures_getStringByKey(winTZ, ISOcodeA, &len, &status);
                }
                if (errorCode == 0 || icuTZ == NULL) {
                    /* fallback to default "001" and reset status */
                    status = U_ZERO_ERROR;
                    icuTZ = ures_getStringByKey(winTZ, "001", &len, &status);
                }

                if (U_SUCCESS(status)) {
                    int index = 0;
                    while (!(*icuTZ == '\0' || *icuTZ == ' ')) {
                        tmpid[index++] = (char)(*icuTZ++); /* safe to assume 'char' is ASCII compatible on windows */
                    }
                    tmpid[index] = '\0';
                    tryPreVistaFallback = FALSE;
                }
            }
        }
    }

    if (tryPreVistaFallback) {

        /* Note: We get the winid not from static tables but from resource bundle. */
        while (U_SUCCESS(status) && ures_hasNext(bundle)) {
            UBool idFound = FALSE;
            const char* winid;
            UResourceBundle* winTZ = ures_getNextResource(bundle, NULL, &status);
            if (U_FAILURE(status)) {
                break;
            }
            winid = ures_getKey(winTZ);
            result = getTZI(winid, &tziReg);

            if (result == ERROR_SUCCESS) {
                /* Windows alters the DaylightBias in some situations.
                Using the bias and the rules suffices, so overwrite
                these unreliable fields. */
                tziKey.standardBias = tziReg.standardBias;
                tziKey.daylightBias = tziReg.daylightBias;

                if (uprv_memcmp((char*)&tziKey, (char*)&tziReg, sizeof(tziKey)) == 0) {
                    const UChar* icuTZ = NULL;
                    if (errorCode != 0) {
                        icuTZ = ures_getStringByKey(winTZ, ISOcodeA, &len, &status);
                    }
                    if (errorCode == 0 || icuTZ == NULL) {
                        /* fallback to default "001" and reset status */
                        status = U_ZERO_ERROR;
                        icuTZ = ures_getStringByKey(winTZ, "001", &len, &status);
                    }

                    if (U_SUCCESS(status)) {
                        /* Get the standard name from the registry key to compare with
                        the one from Windows API call. */
                        uprv_memset(regStdName, 0, sizeof(regStdName));
                        result = getSTDName(winid, regStdName, sizeof(regStdName));
                        if (result == ERROR_SUCCESS) {
                            if (uprv_strcmp(apiStdName, regStdName) == 0) {
                                idFound = TRUE;
                            }
                        }

                        /* tmpid buffer holds the ICU timezone ID corresponding to the timezone ID from Windows.
                         * If none is found, tmpid buffer will contain a fallback ID (i.e. the time zone ID matching
                         * the current time zone information)
                         */
                        if (idFound || tmpid[0] == 0) {
                            /* if icuTZ has more than one city, take only the first (i.e. terminate icuTZ at first space) */
                            int index = 0;
                            while (!(*icuTZ == '\0' || *icuTZ == ' ')) {
                                tmpid[index++] = (char)(*icuTZ++); /* safe to assume 'char' is ASCII compatible on windows */
                            }
                            tmpid[index] = '\0';
                        }
                    }
                }
            }
            ures_close(winTZ);
            if (idFound) {
                break;
            }
        }
    }

    /*
     * Copy the timezone ID to icuid to be returned.
     */
    if (tmpid[0] != 0) {
        len = uprv_strlen(tmpid);
        icuid = (char*)uprv_calloc(len + 1, sizeof(char));
        if (icuid != NULL) {
            uprv_strcpy(icuid, tmpid);
        }
    }

    ures_close(bundle);

    return icuid;
}

#else

/**
 * This is main Windows time zone detection function.
 *
 * It returns the Windows time zone converted to an ICU time zone as a heap-allocated buffer, or nullptr upon failure.
 *
 * We use the Win32 API GetDynamicTimeZoneInformation (which is available since Vista) to get the current time zone info,
 * as this API returns a non-localized time zone name which can be then mapped to an ICU time zone.
 *
 * However, in some RDP/terminal services situations, this struct isn't always fully complete, and the TimeZoneKeyName
 * field of the struct might be NULL. This can happen with some 3rd party RDP clients, and also when using older versions
 * of the RDP protocol, which don't send the newer TimeZoneKeyNamei information and only send the StandardName and DaylightName.
 *
 * Since these 3rd party clients and older RDP clients only send the pre-Vista time zone information to the server, this means that we
 * need to fallback on using the pre-Vista methods to determine the time zone. This unfortunately requires examining the registry directly
 * in order to try and determine the current time zone.
 *
 * Note that this can however still fail in some cases though if the client and server are using different languages, as the StandardName
 * that is sent by client is localized in the client's language. However, we must compare this to the names that are on the server, which
 * are localized in registry using the server's language. Despite that, this is the best we can do.
 *
 * Note: This fallback method won't work for the UWP version though, as we can't use the registry APIs in UWP.
 *
 * Once we have the current Windows time zone, then we can then map it to an ICU time zone ID (~ Olsen ID).
 */
U_CAPI const char* U_EXPORT2 uprv_detectWindowsTimeZone()
{
    // We first try to obtain the time zone directly by using the TimeZoneKeyName field of the DYNAMIC_TIME_ZONE_INFORMATION struct.
    DYNAMIC_TIME_ZONE_INFORMATION dynamicTZI;
    uprv_memset(&dynamicTZI, 0, sizeof(dynamicTZI));
    SYSTEMTIME systemTimeAllZero;
    uprv_memset(&systemTimeAllZero, 0, sizeof(systemTimeAllZero));

    if (GetDynamicTimeZoneInformation(&dynamicTZI) == TIME_ZONE_ID_INVALID) {
        return nullptr;
    }

    // If the DST setting has been turned off in the Control Panel, then return "Etc/GMT<offset>".
    //
    // Note: This logic is based on how the Control Panel itself determines if DST is 'off' on Windows.
    // The code is somewhat convoluted; in a sort of pseudo-code it looks like this:
    //
    //   IF (GetDynamicTimeZoneInformation != TIME_ZONE_ID_INVALID) && (DynamicDaylightTimeDisabled != 0) &&
    //      (StandardDate == DaylightDate) &&
    //      (
    //       (TimeZoneKeyName != Empty && StandardDate == 0) ||
    //       (TimeZoneKeyName == Empty && StandardDate != 0)
    //      )
    //   THEN
    //     DST setting is "Disabled".
    //
    if (dynamicTZI.DynamicDaylightTimeDisabled != 0 && uprv_memcmp(&dynamicTZI.StandardDate, &dynamicTZI.DaylightDate, sizeof(dynamicTZI.StandardDate)) == 0
        && ((dynamicTZI.TimeZoneKeyName[0] != L'\0' && uprv_memcmp(&dynamicTZI.StandardDate, &systemTimeAllZero, sizeof(systemTimeAllZero)) == 0)
            || (dynamicTZI.TimeZoneKeyName[0] == L'\0' && uprv_memcmp(&dynamicTZI.StandardDate, &systemTimeAllZero, sizeof(systemTimeAllZero)) != 0))) {
        LONG utcOffsetMins = dynamicTZI.Bias;
        if (utcOffsetMins == 0) {
            return uprv_strdup("Etc/UTC");
        }

        // No way to support when DST is turned off and the offset in minutes is not a multiple of 60.
        if (utcOffsetMins % 60 == 0) {
            char gmtOffsetTz[11] = {}; // "Etc/GMT+dd" is 11-char long with a terminal null.
            // Important note on the sign convention for zones:
            //
            // From https://en.wikipedia.org/wiki/Tz_database#Area
            //   "In order to conform with the POSIX style, those zone names beginning with "Etc/GMT" have their sign reversed
            //   from the standard ISO 8601 convention. In the "Etc" area, zones west of GMT have a positive sign and those
            //   east have a negative sign in their name (e.g "Etc/GMT-14" is 14 hours ahead of GMT)."
            //
            // Regarding the POSIX style, from https://www.gnu.org/software/libc/manual/html_node/TZ-Variable.html
            //   "The offset specifies the time value you must add to the local time to get a Coordinated Universal Time value."
            //
            // However, the Bias value in DYNAMIC_TIME_ZONE_INFORMATION *already* follows the POSIX convention.
            //
            // From https://docs.microsoft.com/en-us/windows/win32/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information
            //   "The bias is the difference, in minutes, between Coordinated Universal Time (UTC) and
            //   local time. All translations between UTC and local time are based on the following formula:
            //      UTC = local time + bias"
            //
            // For example, a time zone that is 3 hours ahead of UTC (UTC+03:00) would have a Bias value of -180, and the
            // corresponding time zone ID would be "Etc/GMT-3". (So there is no need to negate utcOffsetMins below.)
            int ret = snprintf(gmtOffsetTz, UPRV_LENGTHOF(gmtOffsetTz), "Etc/GMT%+ld", utcOffsetMins / 60);
            if (ret > 0 && ret < UPRV_LENGTHOF(gmtOffsetTz)) {
                return uprv_strdup(gmtOffsetTz);
            }
        }
    }

    // If DST is NOT disabled, but the TimeZoneKeyName field of the struct is NULL, then we may be dealing with a
    // RDP/terminal services session where the 'Time Zone Redirection' feature is enabled. However, either the RDP
    // client sent the server incomplete info (some 3rd party RDP clients only send the StandardName and  DaylightName,
    // but do not send the important TimeZoneKeyName), or if the RDP server has not appropriately populated the struct correctly.
    //
    // In this case we unfortunately have no choice but to fallback to using the pre-Vista method of determining the
    // time zone, which requires examining the registry directly.
    //
    // Note that this can however still fail though if the client and server are using different languages, as the StandardName
    // that is sent by client is *localized* in the client's language. However, we must compare this to the names that are
    // on the server, which are *localized* in registry using the server's language.
    //
    // One other note is that this fallback method doesn't work for the UWP version, as we can't use the registry APIs.

    // windowsTimeZoneName will point at timezoneSubKeyName if we had to fallback to using the registry, and we found a match.
    WCHAR timezoneSubKeyName[WINDOWS_MAX_REG_KEY_LENGTH];
    WCHAR* windowsTimeZoneName = dynamicTZI.TimeZoneKeyName;

    if (dynamicTZI.TimeZoneKeyName[0] == 0) {

// We can't use the registry APIs in the UWP version.
#if U_PLATFORM_HAS_WINUWP_API == 1
        (void)timezoneSubKeyName; // suppress unused variable warnings.
        return nullptr;
#else
        // Open the path to the time zones in the Windows registry.
        LONG ret;
        HKEY hKeyAllTimeZones = nullptr;
        ret = RegOpenKeyExW(HKEY_LOCAL_MACHINE, WINDOWS_TIMEZONES_REG_KEY_PATH, 0, KEY_READ, reinterpret_cast<PHKEY>(&hKeyAllTimeZones));

        if (ret != ERROR_SUCCESS) {
            // If we can't open the key, then we can't do much, so fail.
            return nullptr;
        }

        // Read the number of subkeys under the time zone registry path.
        DWORD numTimeZoneSubKeys;
        ret = RegQueryInfoKeyW(hKeyAllTimeZones, nullptr, nullptr, nullptr, &numTimeZoneSubKeys, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);

        if (ret != ERROR_SUCCESS) {
            RegCloseKey(hKeyAllTimeZones);
            return nullptr;
        }

        // Examine each of the subkeys to try and find a match for the localized standard name ("Std").
        //
        // Note: The name of the time zone subkey itself is not localized, but the "Std" name is localized. This means
        // that we could fail to find a match if the RDP client and RDP server are using different languages, but unfortunately
        // there isn't much we can do about it.
        HKEY hKeyTimeZoneSubKey = nullptr;
        ULONG registryValueType;
        WCHAR registryStandardName[WINDOWS_MAX_REG_KEY_LENGTH];

        for (DWORD i = 0; i < numTimeZoneSubKeys; i++) {
            // Note: RegEnumKeyExW wants the size of the buffer in characters.
            DWORD size = UPRV_LENGTHOF(timezoneSubKeyName);
            ret = RegEnumKeyExW(hKeyAllTimeZones, i, timezoneSubKeyName, &size, nullptr, nullptr, nullptr, nullptr);

            if (ret != ERROR_SUCCESS) {
                RegCloseKey(hKeyAllTimeZones);
                return nullptr;
            }

            ret = RegOpenKeyExW(hKeyAllTimeZones, timezoneSubKeyName, 0, KEY_READ, reinterpret_cast<PHKEY>(&hKeyTimeZoneSubKey));

            if (ret != ERROR_SUCCESS) {
                RegCloseKey(hKeyAllTimeZones);
                return nullptr;
            }

            // Note: RegQueryValueExW wants the size of the buffer in bytes.
            size = sizeof(registryStandardName);
            ret = RegQueryValueExW(hKeyTimeZoneSubKey, L"Std", nullptr, &registryValueType, reinterpret_cast<LPBYTE>(registryStandardName), &size);

            if (ret != ERROR_SUCCESS || registryValueType != REG_SZ) {
                RegCloseKey(hKeyTimeZoneSubKey);
                RegCloseKey(hKeyAllTimeZones);
                return nullptr;
            }

            // Note: wcscmp does an ordinal (byte) comparison.
            if (wcscmp(reinterpret_cast<WCHAR*>(registryStandardName), dynamicTZI.StandardName) == 0) {
                // Since we are comparing the *localized* time zone name, it's possible that some languages might use
                // the same string for more than one time zone. Thus we need to examine the TZI data in the registry to
                // compare the GMT offset (the bias), and the DST transition dates, to ensure it's the same time zone
                // as the currently reported one.
                REG_TZI_FORMAT registryTziValue;
                uprv_memset(&registryTziValue, 0, sizeof(registryTziValue));

                // Note: RegQueryValueExW wants the size of the buffer in bytes.
                DWORD timezoneTziValueSize = sizeof(registryTziValue);
                ret = RegQueryValueExW(
                    hKeyTimeZoneSubKey, L"TZI", nullptr, &registryValueType, reinterpret_cast<LPBYTE>(&registryTziValue), &timezoneTziValueSize);

                if (ret == ERROR_SUCCESS) {
                    if ((dynamicTZI.Bias == registryTziValue.Bias)
                        && (memcmp((const void*)&dynamicTZI.StandardDate, (const void*)&registryTziValue.StandardDate, sizeof(SYSTEMTIME)) == 0)
                        && (memcmp((const void*)&dynamicTZI.DaylightDate, (const void*)&registryTziValue.DaylightDate, sizeof(SYSTEMTIME)) == 0)) {
                        // We found a matching time zone.
                        windowsTimeZoneName = timezoneSubKeyName;
                        break;
                    }
                }
            }
            RegCloseKey(hKeyTimeZoneSubKey);
            hKeyTimeZoneSubKey = nullptr;
        }

        if (hKeyTimeZoneSubKey != nullptr) {
            RegCloseKey(hKeyTimeZoneSubKey);
        }
        if (hKeyAllTimeZones != nullptr) {
            RegCloseKey(hKeyAllTimeZones);
        }
#endif // U_PLATFORM_HAS_WINUWP_API
    }

    CharString winTZ;
    UErrorCode status = U_ZERO_ERROR;
    winTZ.appendInvariantChars(UnicodeString(TRUE, windowsTimeZoneName, -1), status);

    // Map Windows Timezone name (non-localized) to ICU timezone ID (~ Olson timezone id).
    StackUResourceBundle winTZBundle;
    ures_openDirectFillIn(winTZBundle.getAlias(), nullptr, "windowsZones", &status);
    ures_getByKey(winTZBundle.getAlias(), "mapTimezones", winTZBundle.getAlias(), &status);
    ures_getByKey(winTZBundle.getAlias(), winTZ.data(), winTZBundle.getAlias(), &status);

    if (U_FAILURE(status)) {
        return nullptr;
    }

    // Note: Since the ISO 3166 country/region codes are all invariant ASCII chars, we can
    // directly downcast from wchar_t to do the conversion.
    // We could call the A version of the GetGeoInfo API, but that would be slightly slower than calling the W API,
    // as the A version of the API will end up calling MultiByteToWideChar anyways internally.
    wchar_t regionCodeW[3] = {};
    char regionCode[3] = {}; // 2 letter ISO 3166 country/region code made entirely of invariant chars.
    int geoId = GetUserGeoID(GEOCLASS_NATION);
    int regionCodeLen = GetGeoInfoW(geoId, GEO_ISO2, regionCodeW, UPRV_LENGTHOF(regionCodeW), 0);

    const UChar* icuTZ16 = nullptr;
    int32_t tzListLen = 0;

    if (regionCodeLen != 0) {
        for (int i = 0; i < UPRV_LENGTHOF(regionCodeW); i++) {
            regionCode[i] = static_cast<char>(regionCodeW[i]);
        }
        icuTZ16 = ures_getStringByKey(winTZBundle.getAlias(), regionCode, &tzListLen, &status);
    }
    if (regionCodeLen == 0 || U_FAILURE(status)) {
        // fallback to default "001" (world)
        status = U_ZERO_ERROR;
        icuTZ16 = ures_getStringByKey(winTZBundle.getAlias(), "001", &tzListLen, &status);
    }

    // Note: We want the first entry in the string returned by ures_getStringByKey.
    // However this string can be a space delimited list of timezones:
    //  Ex: "America/New_York America/Detroit America/Indiana/Petersburg ..."
    // We need to stop at the first space, so we pass tzLen (instead of tzListLen) to appendInvariantChars below.
    int32_t tzLen = 0;
    if (tzListLen > 0) {
        while (!(icuTZ16[tzLen] == u'\0' || icuTZ16[tzLen] == u' ')) {
            tzLen++;
        }
    }

    // Note: cloneData returns nullptr if the status is a failure, so this
    // will return nullptr if the above look-up fails.
    CharString icuTZStr;
    return icuTZStr.appendInvariantChars(icuTZ16, tzLen, status).cloneData(status);
}

#endif // SUPPORT_XP_CODE

U_NAMESPACE_END
#endif /* U_PLATFORM_USES_ONLY_WIN32_API  */
