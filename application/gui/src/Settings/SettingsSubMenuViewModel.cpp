#include "Application/Gui/Settings/SettingsSubMenuViewModel.hpp"

namespace Application {
namespace Gui {
namespace Settings {

SettingsSubMenuViewModel::SettingsSubMenuViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

} // namespace Settings
} // namespace Gui
} // namespace Application
