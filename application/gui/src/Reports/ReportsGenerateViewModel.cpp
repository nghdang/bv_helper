#include "Application/Gui/Reports/ReportsGenerateViewModel.hpp"

namespace Application {
namespace Gui {
namespace Reports {

Application::Gui::Reports::ReportsGenerateViewModel::ReportsGenerateViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

} // namespace Reports
} // namespace Gui
} // namespace Application
