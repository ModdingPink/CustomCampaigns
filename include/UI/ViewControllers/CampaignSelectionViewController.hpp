#pragma once

#include "HMUI/ViewController.hpp"
#include "UnityEngine/MonoBehaviour.hpp"
#include "custom-types/shared/coroutine.hpp"
#include "custom-types/shared/macros.hpp"
#include "bsml/shared/BSML/Components/HotReloadFileWatcher.hpp"
#include "UI/ReplacementFlowController.hpp"
#include "lapiz/shared/macros.hpp"

#define DECLARE_OVERRIDE_METHOD_MATCH(retval, name, mptr, ...) \
DECLARE_OVERRIDE_METHOD(retval, name, il2cpp_utils::il2cpp_type_check::MetadataGetter<mptr>::get(), __VA_ARGS__)

DECLARE_CLASS_CODEGEN(CustomCampaigns::UI::ViewControllers, CampaignSelectionViewController, HMUI::ViewController,
                        DECLARE_OVERRIDE_METHOD_MATCH(void, DidActivate, &HMUI::ViewController::DidActivate, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

                        DECLARE_INJECT_METHOD(void, Inject, CustomCampaigns::UI::MainMenuReplacementFlowCoordinator* baseFCs);
                        DECLARE_INJECT_FIELD(HMUI::FlowCoordinator*, baseFC);

                        DECLARE_INSTANCE_FIELD(BSML::HotReloadFileWatcher*, fileWatcher);
                        DECLARE_INSTANCE_METHOD(void, Awake);
                        DECLARE_DEFAULT_CTOR();
)