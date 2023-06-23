#include "Application/Gui/ViewManagement/ViewContext.hpp"

#include <QQmlContext>
#include "Application/Gui/Common/BaseViewModelDependencies.hpp"
#include "Application/Gui/GithubActivities/GithubActivitiesViewModel.hpp"
#include "Application/Gui/MainWindow/MainWindowViewModel.hpp"
#include "Application/Gui/TeamProfile/TeamProfileViewModel.hpp"
#include "Application/Gui/UserProfile/UserProfileViewModel.hpp"
#include "Application/Gui/ViewManagement/ViewManager.hpp"

namespace Application {
namespace Gui {
namespace ViewManagement {

ViewContext::ViewContext(const std::shared_ptr<ViewManager>& viewManager,
                         const std::shared_ptr<Domain::SettingsManagement::SettingsManager>& settingsManager)
{
    m_baseViewModelDependencies = std::make_shared<Common::BaseViewModelDependencies>(viewManager, settingsManager);

    viewManager->initializeWindow([&](Framework::ViewManagement::AppViewConfiguration& windowConfiguration) {
        windowConfiguration.setQmlUrl(QUrl("qrc:/views/MainWindow.qml"));
        windowConfiguration.setStackViewObjectName("app-content");
        windowConfiguration.setViewModelName("mainWindowViewModel");
        windowConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Window::MainWindowViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/UserProfile.qml"));
        viewConfiguration.setFsmStateName("UserProfile");
        viewConfiguration.setViewModelName("userProfileViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<UserProfile::UserProfileViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/TeamProfile.qml"));
        viewConfiguration.setFsmStateName("TeamProfile");
        viewConfiguration.setViewModelName("teamProfileViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<TeamProfile::TeamProfileViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/GithubActivities.qml"));
        viewConfiguration.setFsmStateName("GithubActivities");
        viewConfiguration.setViewModelName("githubActivitiesViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<GithubActivities::GithubActivitiesViewModel>(m_baseViewModelDependencies);
        });
    });
}

} // namespace ViewManagement
} // namespace Gui
} // namespace Application
