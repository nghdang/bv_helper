#include "Framework/ViewManagement/MainWindow.hpp"

namespace Framework {
namespace ViewManagement {

MainWindow::MainWindow(const MainWindowConfiguration& configuration, QQuickWindow* quickWindow, std::unique_ptr<QQmlContext> qmlContext,
                       std::unique_ptr<ViewModel> viewModel)
    : m_configuration(configuration)
    , m_quickWindow(std::unique_ptr<QQuickWindow>(quickWindow))
    , m_qmlContext(std::move(qmlContext))
    , m_viewModel(std::move(viewModel))
{
}

QQuickWindow* MainWindow::getQuickWindow() const
{
    return m_quickWindow.get();
}

QQmlContext* MainWindow::getQmlContext() const
{
    return m_qmlContext.get();
}

ViewModel* MainWindow::getViewModel() const
{
    return m_viewModel.get();
}

} // namespace ViewManagement
} // namespace Framework
