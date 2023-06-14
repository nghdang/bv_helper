#pragma once

#include <QQmlContext>
#include <QQuickWindow>
#include "MainWindowConfiguration.hpp"
#include "ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

class MainWindow
{
public:
    MainWindow(const MainWindowConfiguration& configuration, QQuickWindow* quickWindow, std::unique_ptr<QQmlContext> m_qmlContext,
               std::unique_ptr<ViewModel> m_viewModel);

    QQuickWindow* getQuickWindow() const;

    QQmlContext* getQmlContext() const;

    ViewModel* getViewModel() const;

protected:
    const MainWindowConfiguration m_configuration;
    std::unique_ptr<QQuickWindow> m_quickWindow;
    std::unique_ptr<QQmlContext> m_qmlContext;
    std::unique_ptr<ViewModel> m_viewModel;
};

} // namespace ViewManagement
} // namespace Framework
