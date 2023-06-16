#pragma once

#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>
#include "AppViewConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

class ViewModel;

class AppView
{
public:
    AppView(const AppViewConfiguration& configuration);

    virtual void init(QQmlEngine* engine);

    AppViewConfiguration getConfiguration() const;

    std::shared_ptr<QQuickItem> getQuickItem() const;

    std::shared_ptr<QQmlContext> getQmlContext() const;

    std::shared_ptr<ViewModel> getViewModel() const;

protected:
    const AppViewConfiguration m_configuration;
    std::shared_ptr<QQuickItem> m_quickItem;
    std::shared_ptr<QQmlContext> m_qmlContext;
    std::shared_ptr<ViewModel> m_viewModel;
};

} // namespace ViewManagement
} // namespace Framework
