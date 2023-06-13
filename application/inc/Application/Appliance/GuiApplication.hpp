#pragma once

#include <QGuiApplication>
#include "Application/ViewManagement/ViewContext.hpp"
#include "Application/ViewManagement/ViewManager.hpp"

namespace Application {
namespace Appliance {

class GuiApplication : public QGuiApplication
{
public:
    GuiApplication(int& argc, char** argv);

    void init();
    void prepareExec();

protected:
    std::shared_ptr<ViewManagement::ViewContext> m_viewContext;
    std::shared_ptr<ViewManagement::ViewManager> m_viewManager;
};

} // namespace Appliance
} // namespace Application
