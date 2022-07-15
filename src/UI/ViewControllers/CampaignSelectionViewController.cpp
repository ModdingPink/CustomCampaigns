#include "logger.hpp"

#include "UI/ViewControllers/CampaignSelectionViewController.hpp"

#include "FlowCoordinatorRegister_Internal.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "questui/shared/BeatSaberUI.hpp"

namespace CustomCampaigns::UI::ViewControllers {
    void CampaignSelectionViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (firstActivation) {
            auto horizontals = CreateHorizontalLayoutGroup(get_transform());

            
        }
    }
}