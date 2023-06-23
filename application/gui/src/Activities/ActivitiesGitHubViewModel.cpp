#include "Application/Gui/Activities/ActivitiesGitHubViewModel.hpp"

namespace Application {
namespace Gui {
namespace Activities {

ActivitiesGitHubViewModel::ActivitiesGitHubViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

} // namespace Activities
} // namespace Gui
} // namespace Application
