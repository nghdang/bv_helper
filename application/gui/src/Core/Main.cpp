#include "Application/Gui/Core/GuiApplication.hpp"

int main(int argc, char* argv[])
{
    Application::Gui::Core::GuiApplication app(argc, argv);
    app.prepareExec();

    return app.exec();
}
