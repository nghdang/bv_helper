#pragma once

#include <QQmlContext>
#include <QQuickWindow>
#include "AppWindowConfiguration.hpp"
#include "ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

class AppWindow
{
public:
    AppWindow(const AppWindowConfiguration& configuration, QQuickWindow* quickWindow, std::unique_ptr<QQmlContext> m_qmlContext,
              std::unique_ptr<ViewModel> m_viewModel);

    QQuickWindow* getQuickWindow() const;

    QQmlContext* getQmlContext() const;

    ViewModel* getViewModel() const;

protected:
    const AppWindowConfiguration m_configuration;
    std::unique_ptr<QQuickWindow> m_quickWindow;
    std::unique_ptr<QQmlContext> m_qmlContext;
    std::unique_ptr<ViewModel> m_viewModel;
};

} // namespace ViewManagement
} // namespace Framework
