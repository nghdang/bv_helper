#include "Application/Gui/Welcome/WelcomeViewModel.hpp"

namespace Application {
namespace Gui {
namespace Welcome {

WelcomeViewModel::WelcomeViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                                   QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

} // namespace Welcome
} // namespace Gui
} // namespace Application
