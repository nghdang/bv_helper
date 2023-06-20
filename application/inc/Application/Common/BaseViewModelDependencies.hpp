#pragma once

#include <memory>

class HeaderBarModel;

namespace Application {
namespace ViewManagement {
class ViewManager;
} // namespace ViewManagement
} // namespace Application

namespace Application {
namespace SettingsManagement {
class SettingsManager;
} // namespace SettingsManagement
} // namespace Application

namespace Application {
namespace Common {

class BaseViewModelDependencies
{
public:
    BaseViewModelDependencies(const std::shared_ptr<ViewManagement::ViewManager>& viewManager,
                              const std::shared_ptr<SettingsManagement::SettingsManager>& settingsManager);

    std::shared_ptr<SettingsManagement::SettingsManager> settingsManager;

    std::shared_ptr<ViewManagement::ViewManager> viewManager;

    std::shared_ptr<HeaderBarModel> headerBarModel;
};

} // namespace Common
} // namespace Application
