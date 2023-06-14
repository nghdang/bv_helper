#include "Framework/ViewManagement/StackViewDriver.hpp"

#include <QMetaObject>
#include <QQmlComponent>
#include <QQmlProperty>
#include <iostream>

namespace Framework {
namespace ViewManagement {

StackViewDriver::StackViewDriver(QQmlEngine* qmlEngine, QQuickItem* stackView)
    : m_stackView(stackView)
{
    m_stackView->setProperty("focus", true);

    auto stackViewBridgeComp = QQmlComponent(qmlEngine);
    stackViewBridgeComp.loadUrl(QUrl("qrc:/StackViewBridge.qml"));
    m_stackViewBridge = stackViewBridgeComp.create();
    QQmlProperty::write(m_stackViewBridge, QString("stackView"), QVariant::fromValue(m_stackView));
}

void StackViewDriver::pushView(QQuickItem* srcView, QQuickItem* desView)
{
    QMetaObject::invokeMethod(m_stackViewBridge, "pushView", Q_ARG(QVariant, QVariant::fromValue(srcView)), Q_ARG(QVariant, QVariant::fromValue(desView)));
}

void StackViewDriver::popView(QQuickItem* srcView, QQuickItem* desView)
{
    QMetaObject::invokeMethod(m_stackViewBridge, "popView", Q_ARG(QVariant, QVariant::fromValue(srcView)), Q_ARG(QVariant, QVariant::fromValue(desView)));
}

} // namespace ViewManagement
} // namespace Framework
