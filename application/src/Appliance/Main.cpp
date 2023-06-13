#include "Application/Appliance/GuiApplication.hpp"

int main(int argc, char* argv[])
{
    Application::Appliance::GuiApplication app(argc, argv);
    app.prepareExec();

    return app.exec();
}
