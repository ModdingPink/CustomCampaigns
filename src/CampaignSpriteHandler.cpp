#include "Utils/CampaignSpriteHandler.hpp"

#include "questui/shared/ArrayUtil.hpp" //cope
#include "questui/shared/BeatSaberUI.hpp" //cope

#include "bsml/shared/Helpers/utilities.hpp"

#include "UnityEngine/Resources.hpp"

#include "Utils/SpriteRepository.hpp" 

DEFINE_TYPE(CustomCampaigns, CampaignSpriteHandler);

void CustomCampaigns::CampaignSpriteHandler::ctor() {
    buttonNormal = QuestUI::BeatSaberUI::Base64ToSprite(Sprites::buttonNormal);
    buttonHighlighted = QuestUI::BeatSaberUI::Base64ToSprite(Sprites::buttonHighlighted);
    auto images = this->GetComponentsInChildren<HMUI::ImageView*>();
    foreground = images[1];
    background = images[0];
    auto* prefab = QuestUI::ArrayUtil::First(UnityEngine::Resources::FindObjectsOfTypeAll<HMUI::ImageView*>(), [](HMUI::ImageView* x){return x->get_name() == "BG";});
    background->set_color(prefab->get_color());
    background->set_overrideSprite(prefab->get_overrideSprite());
    background->set_type(prefab->get_type());
    auto sizeDelta = background->get_rectTransform()->get_sizeDelta();
    background->get_rectTransform()->set_sizeDelta({sizeDelta.x, sizeDelta.y - 3.4f});
    foreground->set_sprite(buttonNormal);
}

void CustomCampaigns::CampaignSpriteHandler::OnPointerEnter(UnityEngine::EventSystems::PointerEventData* eventData) {
    foreground->set_sprite(buttonHighlighted);
    background->get_gameObject()->SetActive(false);
}

void CustomCampaigns::CampaignSpriteHandler::OnPointerExit(UnityEngine::EventSystems::PointerEventData* eventData) {
    foreground->set_sprite(buttonNormal);
    background->get_gameObject()->SetActive(true);
}