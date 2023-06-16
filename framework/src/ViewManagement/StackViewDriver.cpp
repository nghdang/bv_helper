#include "Framework/ViewManagement/StackViewDriver.hpp"

#include <QMetaObject>
#include <QQmlComponent>
#include <QQmlProperty>

namespace Framework {
namespace ViewManagement {

StackViewDriver::StackViewDriver(QQmlEngine* qmlEngine)
{
    auto stackViewFakeComp = QQmlComponent(qmlEngine);
    stackViewFakeComp.loadUrl(QUrl("qrc:/StackViewFake.qml"));
    m_stackViewFake = stackViewFakeComp.create();
}

void StackViewDriver::init(QQuickItem* stackViewReal)
{
    QQmlProperty::write(m_stackViewFake, QString("stackView"), QVariant::fromValue(stackViewReal));
}

void StackViewDriver::pushView(QQuickItem* viewToPush)
{
    QMetaObject::invokeMethod(m_stackViewFake, "pushView", Q_ARG(QVariant, QVariant::fromValue(viewToPush)));
}

void StackViewDriver::popView()
{
    QMetaObject::invokeMethod(m_stackViewFake, "popView");
}

} // namespace ViewManagement
} // namespace Framework
