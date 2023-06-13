#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>
#include "Appliance/HeaderBarModel.hpp"
#include "Common/BaseViewModelDependencies.hpp"
#include "MainWindow/MainWindowViewModel.hpp"
#include "TeamProfile/TeamProfileViewModel.hpp"
#include "UserProfile/UserProfileViewModel.hpp"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    qRegisterMetaType<HeaderBarModel*>();

    auto headerBarModel = std::make_shared<HeaderBarModel>();
    auto baseViewModelDependencies = std::make_shared<Common::BaseViewModelDependencies>(headerBarModel);

    MainWindow::MainWindowViewModel mainWindowViewModel;
    UserProfile::UserProfileViewModel userProfileViewModel{baseViewModelDependencies};
    TeamProfile::TeamProfileViewModel teamProfileViewModel;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("mainWindowViewModel", &mainWindowViewModel);
    engine.rootContext()->setContextProperty("userProfileViewModel", &userProfileViewModel);
    engine.rootContext()->setContextProperty("teamProfileViewModel", &teamProfileViewModel);

    const QUrl url("qrc:/views/MainWindow.qml");
    QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
