#pragma once

#include <QQmlEngine>
#include <QQuickItem>

namespace Framework {
namespace ViewManagement {

class StackViewDriver
{
public:
    explicit StackViewDriver(QQmlEngine* qmlEngine);

    void init(QQuickItem* stackViewReal);

    void pushView(QQuickItem* viewToPush);

    void popView();

protected:
    QObject* m_stackViewFake;
};

} // namespace ViewManagement
} // namespace Framework
