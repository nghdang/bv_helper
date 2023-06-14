#pragma once

#include <QQmlEngine>
#include <QQuickItem>
#include <memory>

namespace Framework {
namespace ViewManagement {

class StackViewDriver
{
public:
    explicit StackViewDriver(QQmlEngine* qmlEngine, QQuickItem* stackView);

    void pushView(QQuickItem* srcView, QQuickItem* desView);
    void popView(QQuickItem* srcView, QQuickItem* desView);

protected:
    QObject* m_stackViewBridge;
    QQuickItem* m_stackView;
};

} // namespace ViewManagement
} // namespace Framework
