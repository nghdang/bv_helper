#include "Application/ViewManagement/ViewContext.hpp"

#include <QQmlContext>
#include "Application/MainWindow/MainWindowViewModel.hpp"
#include "Application/TeamProfile/TeamProfileViewModel.hpp"
#include "Application/UserProfile/UserProfileViewModel.hpp"

namespace Application {
namespace ViewManagement {

ViewContext::ViewContext(const std::shared_ptr<ViewManager>& viewManager)
{
    m_baseViewModelDependencies = std::make_shared<Common::BaseViewModelDependencies>(viewManager);

    viewManager->initializeWindow([&](Framework::ViewManagement::MainWindowConfiguration& mainWindowConfiguration) {
        mainWindowConfiguration.setQmlUrl(QUrl("qrc:/views/MainWindow.qml"));
        mainWindowConfiguration.setStackViewObjectName("app-content");
        mainWindowConfiguration.setViewModelName("mainWindowViewModel");
        mainWindowConfiguration.setViewModelInstantiator(
          [&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> { return std::make_unique<MainWindow::MainWindowViewModel>(); });
    });

    viewManager->registerView([&](Framework::ViewManagement::ViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/UserProfile.qml"));
        viewConfiguration.setFsmStateName("UserProfile");
        viewConfiguration.setViewModelName("userProfileViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<UserProfile::UserProfileViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::ViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/TeamProfile.qml"));
        viewConfiguration.setFsmStateName("TeamProfile");
        viewConfiguration.setViewModelName("teamProfileViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<TeamProfile::TeamProfileViewModel>(m_baseViewModelDependencies);
        });
    });
}

} // namespace ViewManagement
} // namespace Application
