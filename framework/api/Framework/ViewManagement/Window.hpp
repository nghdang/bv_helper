#pragma once

#include <QQmlContext>
#include <QQuickWindow>
#include "ViewModel.hpp"
#include "WindowConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

class Window
{
public:
    Window(const WindowConfiguration& configuration, QQuickWindow* quickWindow, std::unique_ptr<QQmlContext> m_qmlContext,
           std::unique_ptr<ViewModel> m_viewModel);

    QQuickWindow* getQuickWindow() const;

    QQmlContext* getQmlContext() const;

    ViewModel* getViewModel() const;

protected:
    const WindowConfiguration m_configuration;
    std::unique_ptr<QQuickWindow> m_quickWindow;
    std::unique_ptr<QQmlContext> m_qmlContext;
    std::unique_ptr<ViewModel> m_viewModel;
};

} // namespace ViewManagement
} // namespace Framework
