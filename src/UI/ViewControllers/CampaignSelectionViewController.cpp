#include "UI/ViewControllers/CampaignSelectionViewController.hpp"
#include "Utils/logger.hpp"

DEFINE_TYPE(CustomCampaigns::UI::ViewControllers, CampaignSelectionViewController)

namespace CustomCampaigns::UI::ViewControllers {
    void CampaignSelectionViewController::Inject(CustomCampaigns::UI::MainMenuReplacementFlowCoordinator* baseFCs) {
        DEBUG("Inject Method fired");
        baseFC = baseFCs;
    }

    void CampaignSelectionViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (firstActivation) {

        }
    }

    void CampaignSelectionViewController::Awake() {
        fileWatcher->filePath = "/sdcard/CampaignSelectionView.bsml";
    }
}