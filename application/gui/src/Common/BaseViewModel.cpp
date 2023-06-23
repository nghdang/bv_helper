#include "Application/Gui/Common/BaseViewModel.hpp"

#include <iostream>
#include "Application/Gui/Common/BaseViewModelDependencies.hpp"
#include "Application/Gui/ViewManagement/ViewManager.hpp"

namespace Application {
namespace Gui {
namespace Common {

BaseViewModel::BaseViewModel(const std::shared_ptr<BaseViewModelDependencies>& baseViewModelDependencies,
                             QObject* parent)
    : m_headerBarModel{baseViewModelDependencies->headerBarModel}
    , m_viewManager{baseViewModelDependencies->viewManager}
    , m_settingsManager{baseViewModelDependencies->settingsManager}
    , ViewModel{parent}
{
}

void BaseViewModel::submitFsmEvent(const QString& fsmEvent)
{
    m_viewManager->getGuiStateMachine()->submitEvent(fsmEvent);
}

HeaderBarModel* BaseViewModel::getHeaderBarModel() const
{
    return m_headerBarModel.get();
}

} // namespace Common
} // namespace Gui
} // namespace Application
