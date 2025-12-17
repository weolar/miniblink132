/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include "internal/cryptlib.h"

//#include "buildinf.h"
#define PLATFORM "platform: "
#define DATE "built on: Wed Jan 31 13:07:51 2024 UTC"

/*
 * Generate compiler_flags as an array of individual characters. This is a
 * workaround for the situation where CFLAGS gets too long for a C90 string
 * literal
 */
const char compiler_flags[] = { 'c', 'o', 'm', 'p', 'i', 'l', 'e', 'r', ':', ' ', 'c', 'c', ' ', '/', 'Z', 'i', ' ', '/', 'F', 'd', 'o', 's', 's', 'l', '_',
    's', 't', 'a', 't', 'i', 'c', '.', 'p', 'd', 'b', ' ', ' ', '-', 'D', 'O', 'P', 'E', 'N', 'S', 'S', 'L', '_', 'I', 'A', '3', '2', '_', 'S', 'S', 'E', '2',
    ' ', '-', 'D', 'L', '_', 'E', 'N', 'D', 'I', 'A', 'N', ' ', '-', 'D', 'O', 'P', 'E', 'N', 'S', 'S', 'L', '_', 'P', 'I', 'C', ' ', '-', 'D', 'O', 'P', 'E',
    'N', 'S', 'S', 'L', '_', 'C', 'P', 'U', 'I', 'D', '_', 'O', 'B', 'J', ' ', '-', 'D', 'O', 'P', 'E', 'N', 'S', 'S', 'L', '_', 'B', 'N', '_', 'A', 'S', 'M',
    '_', 'P', 'A', 'R', 'T', '_', 'W', 'O', 'R', 'D', 'S', ' ', '-', 'D', 'O', 'P', 'E', 'N', 'S', 'S', 'L', '_', 'I', 'A', '3', '2', '_', 'S', 'S', 'E', '2',
    ' ', '-', 'D', 'O', 'P', 'E', 'N', 'S', 'S', 'L', '_', 'B', 'N', '_', 'A', 'S', 'M', '_', 'M', 'O', 'N', 'T', ' ', '-', 'D', 'O', 'P', 'E', 'N', 'S', 'S',
    'L', '_', 'B', 'N', '_', 'A', 'S', 'M', '_', 'G', 'F', '2', 'm', ' ', '-', 'D', 'S', 'H', 'A', '1', '_', 'A', 'S', 'M', ' ', '-', 'D', 'S', 'H', 'A', '2',
    '5', '6', '_', 'A', 'S', 'M', ' ', '-', 'D', 'S', 'H', 'A', '5', '1', '2', '_', 'A', 'S', 'M', ' ', '-', 'D', 'R', 'C', '4', '_', 'A', 'S', 'M', ' ', '-',
    'D', 'M', 'D', '5', '_', 'A', 'S', 'M', ' ', '-', 'D', 'R', 'M', 'D', '1', '6', '0', '_', 'A', 'S', 'M', ' ', '-', 'D', 'A', 'E', 'S', '_', 'A', 'S', 'M',
    ' ', '-', 'D', 'V', 'P', 'A', 'E', 'S', '_', 'A', 'S', 'M', ' ', '-', 'D', 'W', 'H', 'I', 'R', 'L', 'P', 'O', 'O', 'L', '_', 'A', 'S', 'M', ' ', '-', 'D',
    'G', 'H', 'A', 'S', 'H', '_', 'A', 'S', 'M', ' ', '-', 'D', 'E', 'C', 'P', '_', 'N', 'I', 'S', 'T', 'Z', '2', '5', '6', '_', 'A', 'S', 'M', ' ', '-', 'D',
    'P', 'A', 'D', 'L', 'O', 'C', 'K', '_', 'A', 'S', 'M', ' ', '-', 'D', 'P', 'O', 'L', 'Y', '1', '3', '0', '5', '_', 'A', 'S', 'M', '\0' };

unsigned long OpenSSL_version_num(void)
{
    return OPENSSL_VERSION_NUMBER;
}

unsigned int OPENSSL_version_major(void)
{
    return OPENSSL_VERSION_MAJOR;
}

unsigned int OPENSSL_version_minor(void)
{
    return OPENSSL_VERSION_MINOR;
}

unsigned int OPENSSL_version_patch(void)
{
    return OPENSSL_VERSION_PATCH;
}

const char* OPENSSL_version_pre_release(void)
{
    return OPENSSL_VERSION_PRE_RELEASE;
}

const char* OPENSSL_version_build_metadata(void)
{
    return OPENSSL_VERSION_BUILD_METADATA;
}

extern char ossl_cpu_info_str[];

const char* OpenSSL_version(int t)
{
    switch (t) {
    case OPENSSL_VERSION:
        return OPENSSL_VERSION_TEXT;
    case OPENSSL_VERSION_STRING:
        return OPENSSL_VERSION_STR;
    case OPENSSL_FULL_VERSION_STRING:
        return OPENSSL_FULL_VERSION_STR;
    case OPENSSL_BUILT_ON:
        return DATE;
    case OPENSSL_CFLAGS:
        return compiler_flags;
    case OPENSSL_PLATFORM:
        return PLATFORM;
    case OPENSSL_DIR:
#ifdef OPENSSLDIR
        return "OPENSSLDIR: \"" OPENSSLDIR "\"";
#else
        return "OPENSSLDIR: N/A";
#endif
    case OPENSSL_ENGINES_DIR:
#ifdef ENGINESDIR
        return "ENGINESDIR: \"" ENGINESDIR "\"";
#else
        return "ENGINESDIR: N/A";
#endif
    case OPENSSL_MODULES_DIR:
#ifdef MODULESDIR
        return "MODULESDIR: \"" MODULESDIR "\"";
#else
        return "MODULESDIR: N/A";
#endif
    case OPENSSL_CPU_INFO:
        if (OPENSSL_info(OPENSSL_INFO_CPU_SETTINGS) != NULL)
            return ossl_cpu_info_str;
        else
            return "CPUINFO: N/A";
    }
    return "not available";
}
