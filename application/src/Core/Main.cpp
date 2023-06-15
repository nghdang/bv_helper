#include "Application/Core/GuiApplication.hpp"

int main(int argc, char* argv[])
{
    Application::Core::GuiApplication app(argc, argv);
    app.prepareExec();

    return app.exec();
}
