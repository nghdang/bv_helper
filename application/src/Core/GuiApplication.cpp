#include "Application/Core/GuiApplication.hpp"

#include <iostream>
#include "Application/Core/HeaderBarModel.hpp"
#include "Application/Services/SettingsManager.hpp"
#include "Application/ViewManagement/ViewContext.hpp"
#include "Application/ViewManagement/ViewManager.hpp"

namespace Application {
namespace Core {

GuiApplication::GuiApplication(int& argc, char** argv)
    : QGuiApplication(argc, argv)
{
    init();
}

void GuiApplication::init()
{
    qRegisterMetaType<HeaderBarModel*>();

    m_viewManager = std::make_shared<ViewManagement::ViewManager>();
    m_settingsManager = std::make_shared<Services::SettingsManager>();
}

void GuiApplication::prepareExec()
{
    m_viewContext = std::make_shared<ViewManagement::ViewContext>(m_viewManager, m_settingsManager);
}

} // namespace Core
} // namespace Application
