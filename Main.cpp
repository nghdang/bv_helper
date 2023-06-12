#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "inc/MainWindowViewModel.hpp"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    MainWindowViewModel mainWindowViewModel;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("mainWindowViewModel", &mainWindowViewModel);

    const QUrl url("qrc:/MainWindow.qml");
    QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
