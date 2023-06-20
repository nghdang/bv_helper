#pragma once

#include <memory>

namespace Application {
namespace Common {
class BaseViewModelDependencies;
} // namespace Common
} // namespace Application

namespace Application {
namespace SettingsManagement {
class SettingsManager;
} // namespace SettingsManagement
} // namespace Application

namespace Application {
namespace ViewManagement {

class ViewManager;

class ViewContext
{
public:
    ViewContext(const std::shared_ptr<ViewManager>& viewManager, const std::shared_ptr<SettingsManagement::SettingsManager>& settingsManager);

protected:
    std::shared_ptr<Common::BaseViewModelDependencies> m_baseViewModelDependencies;
};

} // namespace ViewManagement
} // namespace Application
