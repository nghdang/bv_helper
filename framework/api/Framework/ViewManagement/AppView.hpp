#pragma once

#include <QQmlContext>
#include <QQuickItem>
#include "AppViewConfiguration.hpp"
#include "ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

class AppView
{
public:
    AppView(const AppViewConfiguration& configuration, QQuickItem* quickItem, std::unique_ptr<QQmlContext> m_qmlContext,
            std::unique_ptr<ViewModel> m_viewModel);

    QQuickItem* getQuickItem() const;

    QQmlContext* getQmlContext() const;

    ViewModel* getViewModel() const;

protected:
    const AppViewConfiguration m_configuration;
    std::unique_ptr<QQuickItem> m_quickItem;
    std::unique_ptr<QQmlContext> m_qmlContext;
    std::unique_ptr<ViewModel> m_viewModel;
};

} // namespace ViewManagement
} // namespace Framework
