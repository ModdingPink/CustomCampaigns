#pragma once

#include "custom-types/shared/macros.hpp"
#include "lapiz/shared/macros.hpp"
#include "UI/ViewControllers/CampaignSelectionViewController.hpp"
#include "UI/ViewControllers/CampaignTotalLeaderboardViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"
#include "Zenject/IInitializable.hpp"

#define DECLARE_OVERRIDE_METHOD_MATCH(retval, name, mptr, ...) \
DECLARE_OVERRIDE_METHOD(retval, name, il2cpp_utils::il2cpp_type_check::MetadataGetter<mptr>::get(), __VA_ARGS__)

DECLARE_CLASS_CODEGEN_INTERFACES(CustomCampaigns::UI, CustomCampaignsFlowCoordinator, HMUI::FlowCoordinator, classof(::Zenject::IInitializable*),

                                DECLARE_INSTANCE_FIELD(CustomCampaigns::UI::ViewControllers::CampaignSelectionViewController*, selectionViewController);
                                DECLARE_INSTANCE_FIELD(CustomCampaigns::UI::ViewControllers::CampaignTotalLeaderboardViewController*, totalLeaderboardViewController);

                                DECLARE_INJECT_METHOD(void, Inject, CustomCampaigns::UI::ViewControllers::CampaignSelectionViewController*, CustomCampaigns::UI::ViewControllers::CampaignTotalLeaderboardViewController*);
                                DECLARE_OVERRIDE_METHOD_MATCH(void, Initialize, &::Zenject::IInitializable::Initialize);
                                DECLARE_OVERRIDE_METHOD_MATCH(void, DidActivate, &HMUI::FlowCoordinator::DidActivate, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
                                DECLARE_OVERRIDE_METHOD_MATCH(void, BackButtonWasPressed, &HMUI::FlowCoordinator::BackButtonWasPressed, HMUI::ViewController* topViewController);

                                void ShowViewControllers();
        )
