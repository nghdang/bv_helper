#include "Framework/ViewManagement/MainWindowConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

MainWindowConfiguration::MainWindowConfiguration() {}

QUrl MainWindowConfiguration::getQmlUrl() const
{
    return m_qmlUrl;
}

void MainWindowConfiguration::setQmlUrl(const QUrl& newQmlUrl)
{
    m_qmlUrl = newQmlUrl;
}

QString MainWindowConfiguration::getStackViewObjectName() const
{
    return m_stackViewObjectName;
}

void MainWindowConfiguration::setStackViewObjectName(const QString& newStackViewObjectName)
{
    m_stackViewObjectName = newStackViewObjectName;
}

QString MainWindowConfiguration::getViewModelName() const
{
    return m_viewModelName;
}

void MainWindowConfiguration::setViewModelName(const QString& newViewModelName)
{
    m_viewModelName = newViewModelName;
}

std::function<std::unique_ptr<ViewModel>()> MainWindowConfiguration::getViewModelInstantiator() const
{
    return m_viewModelInstantiator;
}

void MainWindowConfiguration::setViewModelInstantiator(const std::function<std::unique_ptr<ViewModel>()>& newViewModelInstantiator)
{
    m_viewModelInstantiator = newViewModelInstantiator;
}

} // namespace ViewManagement
} // namespace Framework
