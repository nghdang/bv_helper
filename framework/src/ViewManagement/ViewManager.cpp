#include "ViewManagement/ViewManager.hpp"

namespace Framework {
namespace ViewManagement {

ViewManager::ViewManager(ViewManagerConfigurator viewManagerConfigurator, QObject* parent)
    : QObject{parent}
{
    ViewManagerConfiguration viewManagerConfiguration;
    if (viewManagerConfigurator)
    {
        viewManagerConfigurator(viewManagerConfiguration);
    }

    m_guiStateMachine = std::make_unique<StateMachine::GuiStateMachine>(viewManagerConfiguration.getStateMachineUrl().path());
}

} // namespace ViewManagement
} // namespace Framework
