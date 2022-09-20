#include "include/UI/CustomCampaignsFlowCoordinator.hpp"

DEFINE_TYPE(CustomCampaigns::UI, CustomCampaignsFlowCoordinator);

namespace CustomCampaigns::UI {
    void CustomCampaignsFlowCoordinator::Inject(CustomCampaigns::UI::ViewControllers::CampaignSelectionViewController* selectionViewController,
                                                CustomCampaigns::UI::ViewControllers::CampaignTotalLeaderboardViewController* totalLeaderboardViewController) {
        this->selectionViewController = selectionViewController;
        this->totalLeaderboardViewController = totalLeaderboardViewController;

    }

    void CustomCampaignsFlowCoordinator::Initialize() {
        ShowViewControllers();
        showBackButton = true;

    }

    void CustomCampaignsFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy,
                                                     bool screenSystemEnabling) {

    }

    void CustomCampaignsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController) {

    }

    void CustomCampaignsFlowCoordinator::ShowViewControllers() {
        ProvideInitialViewControllers(selectionViewController,  nullptr, totalLeaderboardViewController, nullptr, nullptr);
    }
}