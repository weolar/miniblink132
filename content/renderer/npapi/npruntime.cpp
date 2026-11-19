// Copyright (C) 2004, 2006 Apple Computer, Inc. All rights reserved.
// Copyright (C) 2007-2009 Google, Inc. All rights reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/npruntime_priv.h"

#include <cstring>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "base/synchronization/lock.h"

namespace {

base::Lock& identifierMapLock()
{
    static auto* s_lock = new base::Lock();
    return *s_lock;
}

std::unordered_map<std::string, content::PrivateIdentifier*>& stringIdentifierMap()
{
    static auto* s_map = new std::unordered_map<std::string, content::PrivateIdentifier*>();
    return *s_map;
}

std::unordered_map<int32_t, content::PrivateIdentifier*>& intIdentifierMap()
{
    static auto* s_map = new std::unordered_map<int32_t, content::PrivateIdentifier*>();
    return *s_map;
}

using NPObjectSet = std::unordered_set<NPObject*>;
using NPObjectMap = std::unordered_map<NPObject*, NPObject*>;
using NPRootObjectMap = std::unordered_map<NPObject*, NPObjectSet*>;

NPObjectMap& liveObjectMap()
{
    static auto* s_map = new NPObjectMap();
    return *s_map;
}

NPRootObjectMap& rootObjectMap()
{
    static auto* s_map = new NPRootObjectMap();
    return *s_map;
}

} // namespace

extern "C" {

NPIdentifier _NPN_GetStringIdentifier(const NPUTF8* name)
{
    if (!name)
        return nullptr;

    base::AutoLock lock(identifierMapLock());
    std::string key(name);
    auto& identMap = stringIdentifierMap();
    auto it = identMap.find(key);
    if (it != identMap.end())
        return static_cast<NPIdentifier>(it->second);

    size_t nameLen = key.size();
    auto* identifier = static_cast<content::PrivateIdentifier*>(malloc(sizeof(content::PrivateIdentifier) + nameLen + 1));
    if (!identifier)
        return nullptr;
    char* nameStorage = reinterpret_cast<char*>(identifier + 1);
    memcpy(nameStorage, name, nameLen + 1);
    identifier->isString = true;
    identifier->value.string = reinterpret_cast<const NPUTF8*>(nameStorage);
    identMap.emplace(std::move(key), identifier);
    return static_cast<NPIdentifier>(identifier);
}

void _NPN_GetStringIdentifiers(const NPUTF8** names, int32_t nameCount, NPIdentifier* identifiers)
{
    if (!names || !identifiers)
        return;
    for (int32_t i = 0; i < nameCount; ++i)
        identifiers[i] = _NPN_GetStringIdentifier(names[i]);
}

NPIdentifier _NPN_GetIntIdentifier(int32_t intId)
{
    base::AutoLock lock(identifierMapLock());
    auto& identMap = intIdentifierMap();
    auto it = identMap.find(intId);
    if (it != identMap.end())
        return static_cast<NPIdentifier>(it->second);

    auto* identifier = static_cast<content::PrivateIdentifier*>(malloc(sizeof(content::PrivateIdentifier)));
    if (!identifier)
        return nullptr;
    identifier->isString = false;
    identifier->value.number = intId;
    identMap.emplace(intId, identifier);
    return static_cast<NPIdentifier>(identifier);
}

bool _NPN_IdentifierIsString(NPIdentifier identifier)
{
    if (!identifier)
        return false;
    return reinterpret_cast<content::PrivateIdentifier*>(identifier)->isString;
}

NPUTF8* _NPN_UTF8FromIdentifier(NPIdentifier identifier)
{
    if (!identifier)
        return nullptr;
    auto* priv = reinterpret_cast<content::PrivateIdentifier*>(identifier);
    if (!priv->isString || !priv->value.string)
        return nullptr;
    size_t len = strlen(priv->value.string);
    auto* copy = static_cast<NPUTF8*>(malloc(len + 1));
    if (!copy)
        return nullptr;
    memcpy(copy, priv->value.string, len + 1);
    return copy;
}

int32_t _NPN_IntFromIdentifier(NPIdentifier identifier)
{
    if (!identifier)
        return 0;
    auto* priv = reinterpret_cast<content::PrivateIdentifier*>(identifier);
    return priv->isString ? 0 : priv->value.number;
}

void _NPN_ReleaseVariantValue(NPVariant* variant)
{
    if (!variant)
        return;

    if (variant->type == NPVariantType_Object) {
        if (variant->value.objectValue)
            _NPN_ReleaseObject(variant->value.objectValue);
        variant->value.objectValue = nullptr;
    } else if (variant->type == NPVariantType_String) {
        free(const_cast<NPUTF8*>(variant->value.stringValue.UTF8Characters));
        variant->value.stringValue.UTF8Characters = nullptr;
        variant->value.stringValue.UTF8Length = 0;
    }
    variant->type = NPVariantType_Void;
}

NPObject* _NPN_CreateObject(NPP npp, NPClass* npClass)
{
    if (!npClass)
        return nullptr;

    NPObject* npObject = npClass->allocate
        ? npClass->allocate(npp, npClass)
        : static_cast<NPObject*>(malloc(sizeof(NPObject)));
    if (!npObject)
        return nullptr;

    npObject->_class = npClass;
    npObject->referenceCount = 1;
    return npObject;
}

NPObject* _NPN_RetainObject(NPObject* npObject)
{
    if (npObject)
        ++npObject->referenceCount;
    return npObject;
}

void _NPN_DeallocateObject(NPObject* npObject)
{
    if (!npObject)
        return;

    if (_NPN_IsAlive(npObject))
        _NPN_UnregisterObject(npObject);

    npObject->referenceCount = 0;
    if (npObject->_class && npObject->_class->deallocate)
        npObject->_class->deallocate(npObject);
    else
        free(npObject);
}

void _NPN_ReleaseObject(NPObject* npObject)
{
    if (npObject && npObject->referenceCount >= 1) {
        if (--npObject->referenceCount == 0)
            _NPN_DeallocateObject(npObject);
    }
}

void _NPN_InitializeVariantWithStringCopy(NPVariant* variant, const NPString* value)
{
    if (!variant || !value)
        return;
    auto* copy = static_cast<NPUTF8*>(malloc(value->UTF8Length + 1));
    if (!copy) {
        VOID_TO_NPVARIANT(*variant);
        return;
    }
    variant->type = NPVariantType_String;
    variant->value.stringValue.UTF8Length = value->UTF8Length;
    if (value->UTF8Length > 0 && value->UTF8Characters)
        memcpy(copy, value->UTF8Characters, value->UTF8Length);
    copy[value->UTF8Length] = '\0';
    variant->value.stringValue.UTF8Characters = copy;
}

void _NPN_RegisterObject(NPObject* npObject, NPObject* owner)
{
    if (!npObject)
        return;

    if (liveObjectMap().find(npObject) != liveObjectMap().end())
        return;

    if (!owner) {
        rootObjectMap()[npObject] = new NPObjectSet();
    } else {
        auto ownerEntry = liveObjectMap().find(owner);
        if (ownerEntry != liveObjectMap().end() && ownerEntry->second)
            owner = ownerEntry->second;

        auto rootEntry = rootObjectMap().find(owner);
        if (rootEntry != rootObjectMap().end())
            rootEntry->second->insert(npObject);
    }

    liveObjectMap()[npObject] = owner;
}

void _NPN_UnregisterObject(NPObject* npObject)
{
    if (!npObject)
        return;

    auto liveIt = liveObjectMap().find(npObject);
    if (liveIt == liveObjectMap().end())
        return;

    NPObject* owner = liveIt->second;
    liveObjectMap().erase(liveIt);

    if (!owner) {
        auto rootIt = rootObjectMap().find(npObject);
        if (rootIt != rootObjectMap().end()) {
            NPObjectSet* set = rootIt->second;
            rootObjectMap().erase(rootIt);
            while (!set->empty()) {
                NPObject* subObject = *set->begin();
                set->erase(subObject);
                liveObjectMap().erase(subObject);

                content::disposeV8NPObject(subObject);
                content::forgetV8ObjectForNPObject(subObject);
            }
            delete set;
        }
    } else {
        auto rootIt = rootObjectMap().find(owner);
        if (rootIt != rootObjectMap().end())
            rootIt->second->erase(npObject);
    }

    content::disposeV8NPObject(npObject);
    content::forgetV8ObjectForNPObject(npObject);
}

bool _NPN_IsAlive(NPObject* npObject)
{
    return npObject && liveObjectMap().find(npObject) != liveObjectMap().end();
}

} // extern "C"
