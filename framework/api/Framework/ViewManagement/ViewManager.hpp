#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>
#include "Framework/StateMachine/GuiStateMachine.hpp"
#include "StackViewDriver.hpp"
#include "View.hpp"
#include "ViewConfiguration.hpp"
#include "ViewManagerConfiguration.hpp"
#include "Window.hpp"
#include "WindowConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

class ViewManager : public QObject
{
    Q_OBJECT

public:
    using ViewManagerConfigurator = std::function<void(ViewManagerConfiguration& viewManagerConfiguration)>;
    using MainWindowConfigurator = std::function<void(WindowConfiguration& mainWindowConfiguration)>;
    using ViewConfigurator = std::function<void(ViewConfiguration& viewConfiguration)>;

    explicit ViewManager(ViewManagerConfigurator viewManagerConfigurator, QObject* parent = nullptr);

    StateMachine::GuiStateMachine* getGuiStateMachine() const;

    QSharedPointer<QQmlApplicationEngine> getEngine() const;

    void initializeWindow(MainWindowConfigurator mainWindowConfigurator);

    void registerView(ViewConfigurator viewConfigurator);

public slots:
    void onStateChanged(const QString& stateName, bool active);

signals:

protected:
    std::unique_ptr<StateMachine::GuiStateMachine> m_guiStateMachine;

    QSharedPointer<QQmlApplicationEngine> m_engine;

    std::unique_ptr<Window> m_mainWindow;

    std::shared_ptr<StackViewDriver> m_stackViewDriver;

    std::map<QString, std::unique_ptr<View>> m_views;
};

} // namespace ViewManagement
} // namespace Framework
