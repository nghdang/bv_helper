#include "Application/Gui/Settings/SettingsMainMenuViewModel.hpp"

namespace Application {
namespace Gui {
namespace Settings {

SettingsMainMenuViewModel::SettingsMainMenuViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

} // namespace Settings
} // namespace Gui
} // namespace Application
