#pragma once

#include "Framework/ViewManagement/ViewManager.hpp"

namespace Application {
namespace Gui {
namespace ViewManagement {

class ViewManager : public Framework::ViewManagement::ViewManager
{
public:
    ViewManager(QObject* parent = nullptr);
};

} // namespace ViewManagement
} // namespace Gui
} // namespace Application
