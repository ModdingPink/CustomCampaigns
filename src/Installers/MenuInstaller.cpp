#include "Installers/MenuInstaller.hpp"
#include "lapiz/shared/utilities/ZenjectExtensions.hpp"
#include "Utils/logger.hpp"

#include "Zenject/Installer.hpp"
#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/DiContainer.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"

#include "UI/ViewControllers/CampaignTotalLeaderboardViewController.hpp"
#include "UI/ViewControllers/CampaignSelectionViewController.hpp"
#include "UI/ReplacementFlowController.hpp"
#include "UI/CustomCampaignsFlowCoordinator.hpp"

DEFINE_TYPE(CustomCampaigns, MenuInstaller);

using namespace Lapiz::Zenject::ZenjectExtensions;

namespace CustomCampaigns {
    void MenuInstaller::InstallBindings() {
        auto container = get_Container();

        INFO("got container");
        FromNewComponentOnNewGameObject(
                container->Bind<CustomCampaigns::UI::MainMenuReplacementFlowCoordinator*>()
        )->AsSingle();
        INFO("installed replacement FlowCoordinator");
        FromNewComponentOnNewGameObject(
                container->Bind<CustomCampaigns::UI::CustomCampaignsFlowCoordinator*>()
        )->AsSingle();
        INFO("installed flowcoordinator");
        FromNewComponentAsViewController(
                container->Bind<CustomCampaigns::UI::ViewControllers::CampaignSelectionViewController*>()
        )->AsSingle();
        INFO("Installed Selection ViewController");
        FromNewComponentAsViewController(
                container->Bind<CustomCampaigns::UI::ViewControllers::CampaignTotalLeaderboardViewController*>()
        )->AsSingle();
        INFO("installed leaderboard viewcontroller");
    }
}