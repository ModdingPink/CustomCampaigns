#pragma once

#include "HMUI/ViewController.hpp"
#include "custom-types/shared/coroutine.hpp"
#include "custom-types/shared/macros.hpp" 

#define DECLARE_OVERRIDE_METHOD_MATCH(retval, name, mptr, ...) \
DECLARE_OVERRIDE_METHOD(retval, name, il2cpp_utils::il2cpp_type_check::MetadataGetter<mptr>::get(), __VA_ARGS__)

DECLARE_CLASS_CODEGEN(CustomCampaigns::UI::ViewControllers, CampaignTotalLeaderboardViewController, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD_MATCH(void, DidActivate, &HMUI::ViewController::DidActivate, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD_MATCH(void, DidDeactivate, &HMUI::ViewController::DidDeactivate);
)