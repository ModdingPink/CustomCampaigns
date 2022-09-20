#pragma once

#include "custom-types/shared/macros.hpp"

#include "UnityEngine/EventSystems/IPointerEnterHandler.hpp"
#include "UnityEngine/EventSystems/IPointerExitHandler.hpp"

#include "UnityEngine/EventSystems/IEventSystemHandler.hpp"
#include "UnityEngine/Sprite.hpp"

#include "HMUI/ImageView.hpp"

#define CampaignButtonInterfaces \
{ \
    classof(UnityEngine::EventSystems::IPointerEnterHandler*), classof(UnityEngine::EventSystems::IPointerExitHandler*), classof(UnityEngine::EventSystems::IEventSystemHandler*) \
} \

___DECLARE_TYPE_WRAPPER_INHERITANCE(CustomCampaigns, CampaignSpriteHandler, Il2CppTypeEnum::IL2CPP_TYPE_CLASS, UnityEngine::MonoBehaviour, "CustomCampaigns", CampaignButtonInterfaces, 0, nullptr,

    DECLARE_OVERRIDE_METHOD(void, OnPointerEnter, il2cpp_utils::il2cpp_type_check::MetadataGetter<&UnityEngine::EventSystems::IPointerEnterHandler::OnPointerEnter>::get(), 
            UnityEngine::EventSystems::PointerEventData* eventData);
    DECLARE_OVERRIDE_METHOD(void, OnPointerExit, il2cpp_utils::il2cpp_type_check::MetadataGetter<&UnityEngine::EventSystems::IPointerExitHandler::OnPointerExit>::get(), 
            UnityEngine::EventSystems::PointerEventData* eventData);
    DECLARE_CTOR(ctor);
    DECLARE_INSTANCE_FIELD(UnityEngine::Sprite*, buttonNormal);
    DECLARE_INSTANCE_FIELD(UnityEngine::Sprite*, buttonHighlighted);
    DECLARE_INSTANCE_FIELD(HMUI::ImageView*, foreground);
    DECLARE_INSTANCE_FIELD(HMUI::ImageView*, background);
)