#include "Installers/CoreInstaller.hpp"
#include "lapiz/shared/utilities/ZenjectExtensions.hpp"

#include "Zenject/Installer.hpp"

#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/DiContainer.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"

DEFINE_TYPE(CustomCampaigns, CoreInstaller);

namespace CustomCampaigns {
    void CoreInstaller::InstallBindings() {

        auto container = get_Container();
    }
}