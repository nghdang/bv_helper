#include "Application/ViewManagement/ViewContext.hpp"

#include <QQmlContext>

namespace Application {
namespace ViewManagement {

ViewContext::ViewContext(const std::shared_ptr<ViewManager>& viewManager)
{
    m_baseViewModelDependencies = std::make_shared<Common::BaseViewModelDependencies>();

    m_mainWindowViewModel = std::make_shared<MainWindow::MainWindowViewModel>();
    m_userProfileViewModel = std::make_shared<UserProfile::UserProfileViewModel>(m_baseViewModelDependencies);
    m_teamProfileViewModel = std::make_shared<TeamProfile::TeamProfileViewModel>(m_baseViewModelDependencies);

    auto rootContext = viewManager->getEngine()->rootContext();
    rootContext->setContextProperty("mainWindowViewModel", m_mainWindowViewModel.get());
    rootContext->setContextProperty("userProfileViewModel", m_userProfileViewModel.get());
    rootContext->setContextProperty("teamProfileViewModel", m_teamProfileViewModel.get());
}

} // namespace ViewManagement
} // namespace Application
