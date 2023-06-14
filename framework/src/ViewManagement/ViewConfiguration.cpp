#include "Framework/ViewManagement/ViewConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

ViewConfiguration::ViewConfiguration() {}

QUrl ViewConfiguration::getQmlUrl() const
{
    return m_qmlUrl;
}

void ViewConfiguration::setQmlUrl(const QUrl &newQmlUrl)
{
    m_qmlUrl = newQmlUrl;
}

QString ViewConfiguration::getFsmStateName() const
{
    return m_fsmStateName;
}

void ViewConfiguration::setFsmStateName(const QString &newFsmStateName)
{
    m_fsmStateName = newFsmStateName;
}

QString ViewConfiguration::getViewModelName() const
{
    return m_viewModelName;
}

void ViewConfiguration::setViewModelName(const QString &newViewModelName)
{
    m_viewModelName = newViewModelName;
}

std::function<std::unique_ptr<ViewModel> ()> ViewConfiguration::getViewModelInstantiator() const
{
    return m_viewModelInstantiator;
}

void ViewConfiguration::setViewModelInstantiator(const std::function<std::unique_ptr<ViewModel> ()> &newViewModelInstantiator)
{
    m_viewModelInstantiator = newViewModelInstantiator;
}

} // namespace ViewManagement
} // namespace Framework
