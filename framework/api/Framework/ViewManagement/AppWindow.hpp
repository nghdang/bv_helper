#pragma once

#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickWindow>
#include "AppView.hpp"

namespace Framework {
namespace ViewManagement {

class ViewModel;
class StackViewDriver;

class AppWindow : public AppView
{
public:
    AppWindow(const AppViewConfiguration& configuration);

    void init(QQmlEngine* engine) override;

    std::shared_ptr<QQuickWindow> getQuickWindow() const;

    std::shared_ptr<StackViewDriver> getStackViewDriver() const;

protected:
    std::shared_ptr<QQuickWindow> m_quickWindow;
    std::shared_ptr<StackViewDriver> m_stackViewDriver;
};

} // namespace ViewManagement
} // namespace Framework
