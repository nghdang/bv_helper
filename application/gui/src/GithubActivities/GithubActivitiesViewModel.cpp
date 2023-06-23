#include "Application/Gui/GithubActivities/GithubActivitiesViewModel.hpp"

namespace Application {
namespace Gui {
namespace GithubActivities {

GithubActivitiesViewModel::GithubActivitiesViewModel(
  const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

void GithubActivitiesViewModel::activating()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_headerBarModel->setHeaderText(QStringLiteral("GitHub Activities"));
}

void GithubActivitiesViewModel::activated()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::deactivating()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::deactivated()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::enterBack()
{
    submitFsmEvent(FSM_EVENT_ENTER_BACK);
}

} // namespace GithubActivities
} // namespace Gui
} // namespace Application
