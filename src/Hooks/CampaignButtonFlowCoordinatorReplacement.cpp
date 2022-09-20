#include "Utils/hooking.hpp"
#include "Utils/Logger.hpp"

#include "GlobalNamespace/MainMenuViewController.hpp"
#include "UnityEngine/UI/Button.hpp"
#include "UnityEngine/Events/UnityEventBase.hpp"
#include "UnityEngine/Events/InvokableCallList.hpp"
#include "UnityEngine/UI/Button_ButtonClickedEvent.hpp"
#include "bsml/shared/Helpers/creation.hpp"
#include "System/Collections/Generic/List_1.hpp"
#include "UnityEngine/Resources.hpp"
#include "GlobalNamespace/MainFlowCoordinator.hpp"
#include "UnityEngine/Events/BaseInvokableCall.hpp"
#include "custom-types/shared/delegate.hpp"
#include "UnityEngine/Events/UnityAction.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "UnityEngine/EventSystems/PointerEventData.hpp"

#include "UI/ReplacementFlowController.hpp"
#include "Utils/CampaignSpriteHandler.hpp"

MAKE_AUTO_HOOK_MATCH(CampaignButton_mainMenu, &GlobalNamespace::MainMenuViewController::DidActivate, void, GlobalNamespace::MainMenuViewController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    CampaignButton_mainMenu(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    if (firstActivation) {
        DEBUG("shit1");
        auto campaignButton = self->campaignButton;
        DEBUG("shit2");
        campaignButton->get_gameObject()->AddComponent<CustomCampaigns::CampaignSpriteHandler*>();
        DEBUG("shit3");
        // HMUI::FlowCoordinator* newFlow = BSML::Helpers::CreateFlowCoordinator<CustomCampaigns::UI::MainMenuReplacementFlowCoordinator*>();
        DEBUG("shit4");
        campaignButton->get_onClick()->m_Calls->m_RuntimeCalls->Clear();
        DEBUG("shit5");
        auto* mainFlow = UnityEngine::Resources::FindObjectsOfTypeAll<GlobalNamespace::MainFlowCoordinator*>().get(0);
        DEBUG("shit6");
        using namespace UnityEngine::Events;
        self->campaignButton->get_onClick()->AddListener(custom_types::MakeDelegate<UnityAction*>(classof(UnityAction*), static_cast<std::function<void()>>([=](){
            DEBUG("shit7");
            mainFlow->PresentFlowCoordinator(newFlow, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, false, false);
        })));
        DEBUG("shit8");
    }
}
