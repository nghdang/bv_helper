#include "Framework/ViewManagement/AppWindowConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

QUrl AppWindowConfiguration::getQmlUrl() const
{
    return m_qmlUrl;
}

void AppWindowConfiguration::setQmlUrl(const QUrl& newQmlUrl)
{
    m_qmlUrl = newQmlUrl;
}

QString AppWindowConfiguration::getStackViewObjectName() const
{
    return m_stackViewObjectName;
}

void AppWindowConfiguration::setStackViewObjectName(const QString& newStackViewObjectName)
{
    m_stackViewObjectName = newStackViewObjectName;
}

QString AppWindowConfiguration::getViewModelName() const
{
    return m_viewModelName;
}

void AppWindowConfiguration::setViewModelName(const QString& newViewModelName)
{
    m_viewModelName = newViewModelName;
}

std::function<std::unique_ptr<ViewModel>()> AppWindowConfiguration::getViewModelInstantiator() const
{
    return m_viewModelInstantiator;
}

void AppWindowConfiguration::setViewModelInstantiator(const std::function<std::unique_ptr<ViewModel>()>& newViewModelInstantiator)
{
    m_viewModelInstantiator = newViewModelInstantiator;
}

} // namespace ViewManagement
} // namespace Framework
