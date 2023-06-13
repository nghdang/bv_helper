#include "ViewManagement/ViewManagerConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

ViewManagerConfiguration::ViewManagerConfiguration() {}

QUrl ViewManagerConfiguration::getStateMachineUrl() const
{
    return m_stateMachineUrl;
}

void ViewManagerConfiguration::setStateMachineUrl(const QUrl& newStateMachineUrl)
{
    m_stateMachineUrl = newStateMachineUrl;
}

} // namespace ViewManagement
} // namespace Framework
