#pragma once

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"
#include "beatsaber-hook/shared/utils/typedefs.h"
#include "custom-types/shared/macros.hpp"

#define DECLARE_OVERRIDE_METHOD_MATCH(retval, name, mptr, ...) \
DECLARE_OVERRIDE_METHOD(retval, name, il2cpp_utils::il2cpp_type_check::MetadataGetter<mptr>::get(), __VA_ARGS__)

DECLARE_CLASS_CODEGEN(CustomCampaigns, CustomCampaignsFlowCoordinator, HMUI::FlowController,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, selectionViewController);
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, settingsViewController);
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, leaderboardViewController);

    DECLARE_OVERRIDE_METHOD_MATCH(void, 
        DidActivate, &HMUI::FlowCoordinator::DidActivate, 
        bool firstActivation, 
        bool addedToHierarchy, 
        bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD_MATCH(void, 
        BackButtonWasPressed, &HMUI::FlowCoordinator::BackButtonWasPressed, 
        HMUI::ViewController* topViewController);
)