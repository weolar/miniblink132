/// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_HTML_PERMISSION_ELEMENT_STRINGS_MAP_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_HTML_PERMISSION_ELEMENT_STRINGS_MAP_H_

#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hash.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/public/strings/grit/permission_element_generated_strings.h"
#include "third_party/blink/public/strings/grit/permission_element_strings.h"

namespace blink {
static void FillInPermissionElementTranslationsMap(HashMap<String, HashMap<int, int>>& strings_map)
{
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_af);
    if (!strings_map.Contains(String("af")))
        strings_map.insert(String("af"), HashMap<int, int>());
    strings_map.find(String("af"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_af);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_am);
    if (!strings_map.Contains(String("am")))
        strings_map.insert(String("am"), HashMap<int, int>());
    strings_map.find(String("am"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_am);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ar);
    if (!strings_map.Contains(String("ar")))
        strings_map.insert(String("ar"), HashMap<int, int>());
    strings_map.find(String("ar"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ar);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_as);
    if (!strings_map.Contains(String("as")))
        strings_map.insert(String("as"), HashMap<int, int>());
    strings_map.find(String("as"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_as);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_az);
    if (!strings_map.Contains(String("az")))
        strings_map.insert(String("az"), HashMap<int, int>());
    strings_map.find(String("az"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_az);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_be);
    if (!strings_map.Contains(String("be")))
        strings_map.insert(String("be"), HashMap<int, int>());
    strings_map.find(String("be"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_be);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_bg);
    if (!strings_map.Contains(String("bg")))
        strings_map.insert(String("bg"), HashMap<int, int>());
    strings_map.find(String("bg"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_bg);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_bn);
    if (!strings_map.Contains(String("bn")))
        strings_map.insert(String("bn"), HashMap<int, int>());
    strings_map.find(String("bn"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_bn);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_bs);
    if (!strings_map.Contains(String("bs")))
        strings_map.insert(String("bs"), HashMap<int, int>());
    strings_map.find(String("bs"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_bs);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ca);
    if (!strings_map.Contains(String("ca")))
        strings_map.insert(String("ca"), HashMap<int, int>());
    strings_map.find(String("ca"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ca);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_cs);
    if (!strings_map.Contains(String("cs")))
        strings_map.insert(String("cs"), HashMap<int, int>());
    strings_map.find(String("cs"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_cs);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_cy);
    if (!strings_map.Contains(String("cy")))
        strings_map.insert(String("cy"), HashMap<int, int>());
    strings_map.find(String("cy"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_cy);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_da);
    if (!strings_map.Contains(String("da")))
        strings_map.insert(String("da"), HashMap<int, int>());
    strings_map.find(String("da"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_da);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_de);
    if (!strings_map.Contains(String("de")))
        strings_map.insert(String("de"), HashMap<int, int>());
    strings_map.find(String("de"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_de);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_el);
    if (!strings_map.Contains(String("el")))
        strings_map.insert(String("el"), HashMap<int, int>());
    strings_map.find(String("el"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_el);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_en_GB);
    if (!strings_map.Contains(String("en")))
        strings_map.insert(String("en"), HashMap<int, int>());
    strings_map.find(String("en"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_en_GB);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))
        ->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_es_419);
    if (!strings_map.Contains(String("es-419")))
        strings_map.insert(String("es-419"), HashMap<int, int>());
    strings_map.find(String("es-419"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_es_419);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_es);
    if (!strings_map.Contains(String("es")))
        strings_map.insert(String("es"), HashMap<int, int>());
    strings_map.find(String("es"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_es);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_et);
    if (!strings_map.Contains(String("et")))
        strings_map.insert(String("et"), HashMap<int, int>());
    strings_map.find(String("et"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_et);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_eu);
    if (!strings_map.Contains(String("eu")))
        strings_map.insert(String("eu"), HashMap<int, int>());
    strings_map.find(String("eu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_eu);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_fa);
    if (!strings_map.Contains(String("fa")))
        strings_map.insert(String("fa"), HashMap<int, int>());
    strings_map.find(String("fa"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_fa);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_fi);
    if (!strings_map.Contains(String("fi")))
        strings_map.insert(String("fi"), HashMap<int, int>());
    strings_map.find(String("fi"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_fi);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_fil);
    if (!strings_map.Contains(String("fil")))
        strings_map.insert(String("fil"), HashMap<int, int>());
    strings_map.find(String("fil"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_fil);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))
        ->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_fr_CA);
    if (!strings_map.Contains(String("fr-ca")))
        strings_map.insert(String("fr-ca"), HashMap<int, int>());
    strings_map.find(String("fr-ca"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_fr_CA);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_fr);
    if (!strings_map.Contains(String("fr")))
        strings_map.insert(String("fr"), HashMap<int, int>());
    strings_map.find(String("fr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_fr);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_gl);
    if (!strings_map.Contains(String("gl")))
        strings_map.insert(String("gl"), HashMap<int, int>());
    strings_map.find(String("gl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_gl);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_gu);
    if (!strings_map.Contains(String("gu")))
        strings_map.insert(String("gu"), HashMap<int, int>());
    strings_map.find(String("gu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_gu);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_hi);
    if (!strings_map.Contains(String("hi")))
        strings_map.insert(String("hi"), HashMap<int, int>());
    strings_map.find(String("hi"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_hi);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_hr);
    if (!strings_map.Contains(String("hr")))
        strings_map.insert(String("hr"), HashMap<int, int>());
    strings_map.find(String("hr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_hr);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_hu);
    if (!strings_map.Contains(String("hu")))
        strings_map.insert(String("hu"), HashMap<int, int>());
    strings_map.find(String("hu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_hu);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_hy);
    if (!strings_map.Contains(String("hy")))
        strings_map.insert(String("hy"), HashMap<int, int>());
    strings_map.find(String("hy"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_hy);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_id);
    if (!strings_map.Contains(String("id")))
        strings_map.insert(String("id"), HashMap<int, int>());
    strings_map.find(String("id"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_id);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_is);
    if (!strings_map.Contains(String("is")))
        strings_map.insert(String("is"), HashMap<int, int>());
    strings_map.find(String("is"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_is);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_it);
    if (!strings_map.Contains(String("it")))
        strings_map.insert(String("it"), HashMap<int, int>());
    strings_map.find(String("it"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_it);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_iw);
    if (!strings_map.Contains(String("iw")))
        strings_map.insert(String("iw"), HashMap<int, int>());
    strings_map.find(String("iw"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_iw);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ja);
    if (!strings_map.Contains(String("ja")))
        strings_map.insert(String("ja"), HashMap<int, int>());
    strings_map.find(String("ja"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ja);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ka);
    if (!strings_map.Contains(String("ka")))
        strings_map.insert(String("ka"), HashMap<int, int>());
    strings_map.find(String("ka"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ka);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_kk);
    if (!strings_map.Contains(String("kk")))
        strings_map.insert(String("kk"), HashMap<int, int>());
    strings_map.find(String("kk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_kk);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_km);
    if (!strings_map.Contains(String("km")))
        strings_map.insert(String("km"), HashMap<int, int>());
    strings_map.find(String("km"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_km);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_kn);
    if (!strings_map.Contains(String("kn")))
        strings_map.insert(String("kn"), HashMap<int, int>());
    strings_map.find(String("kn"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_kn);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ko);
    if (!strings_map.Contains(String("ko")))
        strings_map.insert(String("ko"), HashMap<int, int>());
    strings_map.find(String("ko"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ko);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ky);
    if (!strings_map.Contains(String("ky")))
        strings_map.insert(String("ky"), HashMap<int, int>());
    strings_map.find(String("ky"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ky);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_lo);
    if (!strings_map.Contains(String("lo")))
        strings_map.insert(String("lo"), HashMap<int, int>());
    strings_map.find(String("lo"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_lo);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_lt);
    if (!strings_map.Contains(String("lt")))
        strings_map.insert(String("lt"), HashMap<int, int>());
    strings_map.find(String("lt"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_lt);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_lv);
    if (!strings_map.Contains(String("lv")))
        strings_map.insert(String("lv"), HashMap<int, int>());
    strings_map.find(String("lv"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_lv);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_mk);
    if (!strings_map.Contains(String("mk")))
        strings_map.insert(String("mk"), HashMap<int, int>());
    strings_map.find(String("mk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_mk);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ml);
    if (!strings_map.Contains(String("ml")))
        strings_map.insert(String("ml"), HashMap<int, int>());
    strings_map.find(String("ml"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ml);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_mn);
    if (!strings_map.Contains(String("mn")))
        strings_map.insert(String("mn"), HashMap<int, int>());
    strings_map.find(String("mn"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_mn);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_mr);
    if (!strings_map.Contains(String("mr")))
        strings_map.insert(String("mr"), HashMap<int, int>());
    strings_map.find(String("mr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_mr);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ms);
    if (!strings_map.Contains(String("ms")))
        strings_map.insert(String("ms"), HashMap<int, int>());
    strings_map.find(String("ms"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ms);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_my);
    if (!strings_map.Contains(String("my")))
        strings_map.insert(String("my"), HashMap<int, int>());
    strings_map.find(String("my"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_my);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ne);
    if (!strings_map.Contains(String("ne")))
        strings_map.insert(String("ne"), HashMap<int, int>());
    strings_map.find(String("ne"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ne);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_nl);
    if (!strings_map.Contains(String("nl")))
        strings_map.insert(String("nl"), HashMap<int, int>());
    strings_map.find(String("nl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_nl);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_no);
    if (!strings_map.Contains(String("no")))
        strings_map.insert(String("no"), HashMap<int, int>());
    strings_map.find(String("no"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_no);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_or);
    if (!strings_map.Contains(String("or")))
        strings_map.insert(String("or"), HashMap<int, int>());
    strings_map.find(String("or"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_or);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_pa);
    if (!strings_map.Contains(String("pa")))
        strings_map.insert(String("pa"), HashMap<int, int>());
    strings_map.find(String("pa"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_pa);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_pl);
    if (!strings_map.Contains(String("pl")))
        strings_map.insert(String("pl"), HashMap<int, int>());
    strings_map.find(String("pl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_pl);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))
        ->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_pt_BR);
    if (!strings_map.Contains(String("pt-br")))
        strings_map.insert(String("pt-br"), HashMap<int, int>());
    strings_map.find(String("pt-br"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_pt_BR);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_pt_PT);
    if (!strings_map.Contains(String("pt")))
        strings_map.insert(String("pt"), HashMap<int, int>());
    strings_map.find(String("pt"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_pt_PT);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ro);
    if (!strings_map.Contains(String("ro")))
        strings_map.insert(String("ro"), HashMap<int, int>());
    strings_map.find(String("ro"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ro);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ru);
    if (!strings_map.Contains(String("ru")))
        strings_map.insert(String("ru"), HashMap<int, int>());
    strings_map.find(String("ru"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ru);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_si);
    if (!strings_map.Contains(String("si")))
        strings_map.insert(String("si"), HashMap<int, int>());
    strings_map.find(String("si"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_si);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_sk);
    if (!strings_map.Contains(String("sk")))
        strings_map.insert(String("sk"), HashMap<int, int>());
    strings_map.find(String("sk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_sk);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_sl);
    if (!strings_map.Contains(String("sl")))
        strings_map.insert(String("sl"), HashMap<int, int>());
    strings_map.find(String("sl"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_sl);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_sq);
    if (!strings_map.Contains(String("sq")))
        strings_map.insert(String("sq"), HashMap<int, int>());
    strings_map.find(String("sq"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_sq);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))
        ->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))
        ->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_sr_Latn);
    if (!strings_map.Contains(String("sr-latn")))
        strings_map.insert(String("sr-latn"), HashMap<int, int>());
    strings_map.find(String("sr-latn"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_sr_Latn);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_sr);
    if (!strings_map.Contains(String("sr")))
        strings_map.insert(String("sr"), HashMap<int, int>());
    strings_map.find(String("sr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_sr);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_sv);
    if (!strings_map.Contains(String("sv")))
        strings_map.insert(String("sv"), HashMap<int, int>());
    strings_map.find(String("sv"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_sv);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_sw);
    if (!strings_map.Contains(String("sw")))
        strings_map.insert(String("sw"), HashMap<int, int>());
    strings_map.find(String("sw"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_sw);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ta);
    if (!strings_map.Contains(String("ta")))
        strings_map.insert(String("ta"), HashMap<int, int>());
    strings_map.find(String("ta"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ta);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_te);
    if (!strings_map.Contains(String("te")))
        strings_map.insert(String("te"), HashMap<int, int>());
    strings_map.find(String("te"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_te);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_th);
    if (!strings_map.Contains(String("th")))
        strings_map.insert(String("th"), HashMap<int, int>());
    strings_map.find(String("th"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_th);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_tr);
    if (!strings_map.Contains(String("tr")))
        strings_map.insert(String("tr"), HashMap<int, int>());
    strings_map.find(String("tr"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_tr);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_uk);
    if (!strings_map.Contains(String("uk")))
        strings_map.insert(String("uk"), HashMap<int, int>());
    strings_map.find(String("uk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_uk);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ur);
    if (!strings_map.Contains(String("ur")))
        strings_map.insert(String("ur"), HashMap<int, int>());
    strings_map.find(String("ur"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ur);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_uz);
    if (!strings_map.Contains(String("uz")))
        strings_map.insert(String("uz"), HashMap<int, int>());
    strings_map.find(String("uz"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_uz);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_vi);
    if (!strings_map.Contains(String("vi")))
        strings_map.insert(String("vi"), HashMap<int, int>());
    strings_map.find(String("vi"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_vi);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_zh_CN);
    if (!strings_map.Contains(String("zh")))
        strings_map.insert(String("zh"), HashMap<int, int>());
    strings_map.find(String("zh"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_zh_CN);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))
        ->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_zh_HK);
    if (!strings_map.Contains(String("zh-hk")))
        strings_map.insert(String("zh-hk"), HashMap<int, int>());
    strings_map.find(String("zh-hk"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_zh_HK);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))
        ->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_zh_TW);
    if (!strings_map.Contains(String("zh-tw")))
        strings_map.insert(String("zh-tw"), HashMap<int, int>());
    strings_map.find(String("zh-tw"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_zh_TW);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA, IDS_PERMISSION_REQUEST_CAMERA_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_ALLOWED_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_ALLOWED_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED, IDS_PERMISSION_REQUEST_MICROPHONE_ALLOWED_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_ALLOWED, IDS_PERMISSION_REQUEST_CAMERA_ALLOWED_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_MICROPHONE, IDS_PERMISSION_REQUEST_MICROPHONE_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED, IDS_PERMISSION_REQUEST_GEOLOCATION_ALLOWED_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_GEOLOCATION, IDS_PERMISSION_REQUEST_GEOLOCATION_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE, IDS_PERMISSION_REQUEST_CAMERA_MICROPHONE_zu);
    if (!strings_map.Contains(String("zu")))
        strings_map.insert(String("zu"), HashMap<int, int>());
    strings_map.find(String("zu"))->value.insert(IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION, IDS_PERMISSION_REQUEST_PRECISE_GEOLOCATION_zu);
}
} // namespace blink
#endif // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_HTML_PERMISSION_ELEMENT_STRINGS_MAP_H_
