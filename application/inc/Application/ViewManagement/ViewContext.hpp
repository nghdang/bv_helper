#pragma once

#include "Application/Common/BaseViewModelDependencies.hpp"
#include "Application/MainWindow/MainWindowViewModel.hpp"
#include "Application/TeamProfile/TeamProfileViewModel.hpp"
#include "Application/UserProfile/UserProfileViewModel.hpp"
#include "Application/ViewManagement/ViewManager.hpp"

namespace Application {
namespace ViewManagement {

class ViewContext
{
public:
    ViewContext(const std::shared_ptr<ViewManager>& viewManager);

protected:
    std::shared_ptr<Common::BaseViewModelDependencies> m_baseViewModelDependencies;
    std::shared_ptr<MainWindow::MainWindowViewModel> m_mainWindowViewModel;
    std::shared_ptr<UserProfile::UserProfileViewModel> m_userProfileViewModel;
    std::shared_ptr<TeamProfile::TeamProfileViewModel> m_teamProfileViewModel;
};

} // namespace ViewManagement
} // namespace Application
