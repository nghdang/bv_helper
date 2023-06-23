#pragma once

#include <memory>

namespace Application {
namespace Gui {
class HeaderBarModel;
} // namespace Gui
} // namespace Application

namespace Application {
namespace Gui {
namespace ViewManagement {
class ViewManager;
} // namespace ViewManagement
} // namespace Gui
} // namespace Application

namespace Application {
namespace Domain {
namespace SettingsManagement {
class SettingsManager;
} // namespace SettingsManagement
} // namespace Domain
} // namespace Application

namespace Application {
namespace Gui {
namespace Common {

class BaseViewModelDependencies
{
public:
    BaseViewModelDependencies(const std::shared_ptr<ViewManagement::ViewManager>& viewManager,
                              const std::shared_ptr<Domain::SettingsManagement::SettingsManager>& settingsManager);

    std::shared_ptr<Domain::SettingsManagement::SettingsManager> settingsManager;

    std::shared_ptr<ViewManagement::ViewManager> viewManager;

    std::shared_ptr<HeaderBarModel> headerBarModel;
};

} // namespace Common
} // namespace Gui
} // namespace Application
