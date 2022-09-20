#include "main.hpp"
#include "Utils/logger.hpp"
#include "Utils/hooking.hpp"

#include "custom-types/shared/register.hpp"

#include "lapiz/shared/zenject/Zenjector.hpp"
#include "lapiz/shared/zenject/Location.hpp"
#include "lapiz/shared/AttributeRegistration.hpp"

#include "Installers/MenuInstaller.hpp"
#include "Installers/CoreInstaller.hpp"

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
// other config tools such as config-utils don't use this config, so it can be removed if those are in use
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    INFO("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    custom_types::Register::AutoRegister();
    Lapiz::Attributes::AutoRegister();

    // QuestUI::Register::RegisterAllModSettingsFlowCoordinator<CustomCampaigns::UI::CampaignSelectionFlowCoordinator*>(modInfo, "Custom Campaigns");
    INFO("Installing hooks and zenject bindings..");
    Hooks::InstallHooks(CustomCampaigns::Logging::getLogger());

    auto zenjector = ::Lapiz::Zenject::Zenjector::Get();
    zenjector->Install<CustomCampaigns::CoreInstaller*>(Lapiz::Zenject::Location::App);
    zenjector->Install<CustomCampaigns::MenuInstaller*>(Lapiz::Zenject::Location::Menu);
}