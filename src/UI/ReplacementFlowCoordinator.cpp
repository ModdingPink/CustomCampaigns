
#include "UI/ReplacementFlowController.hpp"

DEFINE_TYPE(CustomCampaigns::UI, MainMenuReplacementFlowCoordinator);

namespace CustomCampaigns::UI {
    void MainMenuReplacementFlowCoordinator::ctor() {
        static auto baseKlass = classof(HMUI::FlowCoordinator*);
        custom_types::InvokeBaseCtor(baseKlass, this);
    }

    void MainMenuReplacementFlowCoordinator::DidActivate_Base(bool firstActivation, bool addedToHierarchy,
                                                         bool screenSystemEnabling) {
        auto didActivate = il2cpp_utils::FindMethodUnsafe(this, "DidActivate", 2);
        if (didActivate)
            il2cpp_utils::RunMethod(this, didActivate, firstActivation, addedToHierarchy, screenSystemEnabling);
    }
}
