#include "Application/ViewManagement/ViewManager.hpp"

namespace Application {
namespace ViewManagement {

ViewManager::ViewManager(QObject* parent)
    : Framework::ViewManagement::ViewManager(
        [](Framework::ViewManagement::ViewManagerConfiguration& viewManagerConfiguration) {
            viewManagerConfiguration.setStateMachineUrl(QUrl(":/stateMachine/GuiStateMachine.scxml"));
        },
        parent)
{
}

} // namespace ViewManagement
} // namespace Application
