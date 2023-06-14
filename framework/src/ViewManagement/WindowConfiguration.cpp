#include "Framework/ViewManagement/WindowConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

WindowConfiguration::WindowConfiguration() {}

QUrl WindowConfiguration::getQmlUrl() const
{
    return m_qmlUrl;
}

void WindowConfiguration::setQmlUrl(const QUrl& newQmlUrl)
{
    m_qmlUrl = newQmlUrl;
}

QString WindowConfiguration::getStackViewObjectName() const
{
    return m_stackViewObjectName;
}

void WindowConfiguration::setStackViewObjectName(const QString& newStackViewObjectName)
{
    m_stackViewObjectName = newStackViewObjectName;
}

QString WindowConfiguration::getViewModelName() const
{
    return m_viewModelName;
}

void WindowConfiguration::setViewModelName(const QString& newViewModelName)
{
    m_viewModelName = newViewModelName;
}

std::function<std::unique_ptr<ViewModel>()> WindowConfiguration::getViewModelInstantiator() const
{
    return m_viewModelInstantiator;
}

void WindowConfiguration::setViewModelInstantiator(const std::function<std::unique_ptr<ViewModel>()>& newViewModelInstantiator)
{
    m_viewModelInstantiator = newViewModelInstantiator;
}

} // namespace ViewManagement
} // namespace Framework
