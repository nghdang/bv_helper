#include "Application/GithubActivities/GithubActivitiesViewModel.hpp"

namespace Application {
namespace GithubActivities {

GithubActivitiesViewModel::GithubActivitiesViewModel(const std::shared_ptr<Common::BaseViewModelDependencies>& baseViewModelDependencies, QObject* parent)
    : Common::BaseViewModel{baseViewModelDependencies, parent}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

GithubActivitiesViewModel::~GithubActivitiesViewModel()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::activated()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::activating()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::deactivated()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::deactivating()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void GithubActivitiesViewModel::enterBack()
{
    submitFsmEvent(FSM_EVENT_ENTER_BACK);
}

} // namespace GithubActivities
} // namespace Application
