#pragma once

#include <QQmlContext>
#include <QQuickItem>
#include "ViewConfiguration.hpp"
#include "ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

class View
{
public:
    View(const ViewConfiguration& configuration, QQuickItem* quickItem, std::unique_ptr<QQmlContext> m_qmlContext, std::unique_ptr<ViewModel> m_viewModel);

    QQuickItem* getQuickItem() const;

    QQmlContext* getQmlContext() const;

    ViewModel* getViewModel() const;

protected:
    const ViewConfiguration m_configuration;
    std::unique_ptr<QQuickItem> m_quickItem;
    std::unique_ptr<QQmlContext> m_qmlContext;
    std::unique_ptr<ViewModel> m_viewModel;
};

} // namespace ViewManagement
} // namespace Framework
