#include "Application/Gui/Activities/ActivitiesJiraViewModel.hpp"

namespace Application {
namespace Gui {
namespace Activities {

ActivitiesJiraViewModel::ActivitiesJiraViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

} // namespace Activities
} // namespace Gui
} // namespace Application
