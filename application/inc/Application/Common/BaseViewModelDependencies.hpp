#pragma once

#include <memory>

class HeaderBarModel;

namespace Application {
namespace ViewManagement {
class ViewManager;
} // namespace ViewManagement
} // namespace Application

namespace Application {
namespace Services {
class SettingsManager;
} // namespace Services
} // namespace Application

namespace Application {
namespace Common {

class BaseViewModelDependencies
{
public:
    BaseViewModelDependencies(const std::shared_ptr<ViewManagement::ViewManager>& viewManager,
                              const std::shared_ptr<Services::SettingsManager>& settingsManager);

    std::shared_ptr<Services::SettingsManager> settingsManager;

    std::shared_ptr<ViewManagement::ViewManager> viewManager;

    std::shared_ptr<HeaderBarModel> headerBarModel;
};

} // namespace Common
} // namespace Application
