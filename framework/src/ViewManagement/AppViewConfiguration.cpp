#include "Framework/ViewManagement/AppViewConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

QUrl AppViewConfiguration::getQmlUrl() const
{
    return m_qmlUrl;
}

void AppViewConfiguration::setQmlUrl(const QUrl& newQmlUrl)
{
    m_qmlUrl = newQmlUrl;
}

QString AppViewConfiguration::getFsmStateName() const
{
    return m_fsmStateName;
}

void AppViewConfiguration::setFsmStateName(const QString& newFsmStateName)
{
    m_fsmStateName = newFsmStateName;
}

QString AppViewConfiguration::getViewModelName() const
{
    return m_viewModelName;
}

void AppViewConfiguration::setViewModelName(const QString& newViewModelName)
{
    m_viewModelName = newViewModelName;
}

std::function<std::unique_ptr<ViewModel>()> AppViewConfiguration::getViewModelInstantiator() const
{
    return m_viewModelInstantiator;
}

void AppViewConfiguration::setViewModelInstantiator(const std::function<std::unique_ptr<ViewModel>()>& newViewModelInstantiator)
{
    m_viewModelInstantiator = newViewModelInstantiator;
}

} // namespace ViewManagement
} // namespace Framework
