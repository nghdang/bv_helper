#include "Framework/ViewManagement/ViewManager.hpp"

namespace Framework {
namespace ViewManagement {

ViewManager::ViewManager(ViewManagerConfigurator viewManagerConfigurator, QObject* parent)
    : QObject{parent}
{
    m_engine = QSharedPointer<QQmlApplicationEngine>::create();

    ViewManagerConfiguration viewManagerConfiguration;
    if (viewManagerConfigurator)
    {
        viewManagerConfigurator(viewManagerConfiguration);
    }

    m_guiStateMachine = std::make_unique<StateMachine::GuiStateMachine>(viewManagerConfiguration.getStateMachineUrl().path());
}

StateMachine::GuiStateMachine* ViewManager::getGuiStateMachine() const
{
    return m_guiStateMachine.get();
}

QSharedPointer<QQmlApplicationEngine> ViewManager::getEngine() const
{
    return m_engine;
}

} // namespace ViewManagement
} // namespace Framework
