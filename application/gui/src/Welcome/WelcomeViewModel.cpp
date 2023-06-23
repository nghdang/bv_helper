#include "Application/Gui/Welcome/WelcomeViewModel.hpp"

namespace Application {
namespace Gui {
namespace Welcome {

WelcomeViewModel::WelcomeViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies,
                                   QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

void WelcomeViewModel::activating()
{
    m_headerBarModel->setIsShowHeaderBar(false);
}

void WelcomeViewModel::enterNext()
{
    submitFsmEvent(FSM_EVENT_ENTER_NEXT);
}

} // namespace Welcome
} // namespace Gui
} // namespace Application
