#include "Application/Common/BaseViewModel.hpp"

#include <iostream>
#include "Application/ViewManagement/ViewManager.hpp"

namespace Application {
namespace Common {

BaseViewModel::BaseViewModel(const std::shared_ptr<BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : m_viewManager{baseViewModelDependencies->viewManager}
    , m_headerBarModel{baseViewModelDependencies->headerBarModel}
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
} // namespace Application
