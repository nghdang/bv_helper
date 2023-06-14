#include "Framework/ViewManagement/Window.hpp"

namespace Framework {
namespace ViewManagement {

Window::Window(const WindowConfiguration& configuration, QQuickWindow* quickWindow, std::unique_ptr<QQmlContext> qmlContext,
                       std::unique_ptr<ViewModel> viewModel)
    : m_configuration(configuration)
    , m_quickWindow(std::unique_ptr<QQuickWindow>(quickWindow))
    , m_qmlContext(std::move(qmlContext))
    , m_viewModel(std::move(viewModel))
{
}

QQuickWindow* Window::getQuickWindow() const
{
    return m_quickWindow.get();
}

QQmlContext* Window::getQmlContext() const
{
    return m_qmlContext.get();
}

ViewModel* Window::getViewModel() const
{
    return m_viewModel.get();
}

} // namespace ViewManagement
} // namespace Framework
