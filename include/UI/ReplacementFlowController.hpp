#pragma once

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"
#include "UnityEngine/Sprite.hpp"
#include "beatsaber-hook/shared/utils/typedefs.h"
#include "custom-types/shared/macros.hpp"

#define DECLARE_OVERRIDE_METHOD_MATCH(retval, name, mptr, ...) \
DECLARE_OVERRIDE_METHOD(retval, name, il2cpp_utils::il2cpp_type_check::MetadataGetter<mptr>::get(), __VA_ARGS__)

DECLARE_CLASS_CODEGEN(CustomCampaigns::UI, MainMenuReplacementFlowCoordinator, HMUI::FlowCoordinator,
    DECLARE_CTOR(ctor);

    DECLARE_INSTANCE_FIELD(StringW, name);
    DECLARE_INSTANCE_FIELD(UnityEngine::Sprite*, activeSprite);
    DECLARE_INSTANCE_FIELD(UnityEngine::Sprite*, inactiveSprite);

    DECLARE_OVERRIDE_METHOD(void, DidActivate_Base, il2cpp_utils::il2cpp_type_check::MetadataGetter<&::HMUI::FlowCoordinator::DidActivate>::get(), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)