#include "Framework/ViewManagement/AppWindow.hpp"

namespace Framework {
namespace ViewManagement {

AppWindow::AppWindow(const AppWindowConfiguration& configuration, QQuickWindow* quickWindow, std::unique_ptr<QQmlContext> qmlContext,
                     std::unique_ptr<ViewModel> viewModel)
    : m_configuration(configuration)
    , m_quickWindow(std::unique_ptr<QQuickWindow>(quickWindow))
    , m_qmlContext(std::move(qmlContext))
    , m_viewModel(std::move(viewModel))
{
}

QQuickWindow* AppWindow::getQuickWindow() const
{
    return m_quickWindow.get();
}

QQmlContext* AppWindow::getQmlContext() const
{
    return m_qmlContext.get();
}

ViewModel* AppWindow::getViewModel() const
{
    return m_viewModel.get();
}

} // namespace ViewManagement
} // namespace Framework
