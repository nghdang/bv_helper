#pragma once

#include <memory>

namespace Application {
namespace Gui {
namespace Common {
class BaseViewModelDependencies;
} // namespace Common
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
namespace ViewManagement {

class ViewManager;

class ViewContext
{
public:
    ViewContext(const std::shared_ptr<ViewManager>& viewManager,
                const std::shared_ptr<Domain::SettingsManagement::SettingsManager>& settingsManager);

protected:
    std::shared_ptr<Common::BaseViewModelDependencies> m_baseViewModelDependencies;
};

} // namespace ViewManagement
} // namespace Gui
} // namespace Application
