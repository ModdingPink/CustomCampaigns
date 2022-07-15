#include "include/UI/CampaignSelectionFlowCoordinator.hpp"

namespace CustomCampaigns::UI {
    void CampaignSelectionFlowController(bool firstActivation, bool, addedToHierarchy, bool screenSystemEnabling) {
        if (firstActivation) {
            selectionViewController = CreateViewController<>()
        }
    }
}