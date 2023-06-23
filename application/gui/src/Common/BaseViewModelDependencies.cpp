#include "Application/Gui/Common/BaseViewModelDependencies.hpp"

#include "Application/Gui/Core/HeaderBarModel.hpp"

namespace Application {
namespace Gui {
namespace Common {

BaseViewModelDependencies::BaseViewModelDependencies(
  const std::shared_ptr<ViewManagement::ViewManager>& viewManager,
  const std::shared_ptr<Domain::SettingsManagement::SettingsManager>& settingsManager)
    : viewManager{viewManager}
    , settingsManager{settingsManager}
{
    headerBarModel = std::make_shared<HeaderBarModel>();
}

} // namespace Common
} // namespace Gui
} // namespace Application
