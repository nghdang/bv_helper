#include "Application/GithubActivities/GithubActivitiesViewModel.hpp"

namespace Application {
namespace GithubActivities {

GithubActivitiesViewModel::GithubActivitiesViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
}

void GithubActivitiesViewModel::enterBack()
{
    submitFsmEvent(FSM_EVENT_BACK);
}

} // namespace GithubActivities
} // namespace Application
