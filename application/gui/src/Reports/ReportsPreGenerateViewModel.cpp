#include "Application/Gui/Reports/ReportsPreGenerateViewModel.hpp"

namespace Application {
namespace Gui {
namespace Reports {

Application::Gui::Reports::ReportsPreGenerateViewModel::ReportsPreGenerateViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

} // namespace Reports
} // namespace Gui
} // namespace Application
