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

QString AppViewConfiguration::getViewName() const
{
    return m_viewName;
}

void AppViewConfiguration::setViewName(const QString& newViewName)
{
    m_viewName = newViewName;
}

ViewId AppViewConfiguration::getViewId() const
{
    return m_viewId;
}

void AppViewConfiguration::setViewId(ViewId newViewId)
{
    m_viewId = newViewId;
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

std::function<std::shared_ptr<ViewModel>()> AppViewConfiguration::getViewModelInstantiator() const
{
    return m_viewModelInstantiator;
}

void AppViewConfiguration::setViewModelInstantiator(const std::function<std::shared_ptr<ViewModel>()>& newViewModelInstantiator)
{
    m_viewModelInstantiator = newViewModelInstantiator;
}

QString AppViewConfiguration::getStackViewObjectName() const
{
    return m_stackViewObjectName;
}

void AppViewConfiguration::setStackViewObjectName(const QString& newStackViewObjectName)
{
    m_stackViewObjectName = newStackViewObjectName;
}

} // namespace ViewManagement
} // namespace Framework
