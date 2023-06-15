#include "Application/Core/GuiApplication.hpp"

#include <iostream>

namespace Application {
namespace Core {

GuiApplication::GuiApplication(int& argc, char** argv)
    : QGuiApplication(argc, argv)
{
    init();
}

void GuiApplication::init()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    qRegisterMetaType<HeaderBarModel*>();

    m_viewManager = std::make_shared<ViewManagement::ViewManager>();
}

void GuiApplication::prepareExec()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    m_viewContext = std::make_shared<ViewManagement::ViewContext>(m_viewManager);
}

} // namespace Core
} // namespace Application
