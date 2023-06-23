#include "Application/Gui/ViewManagement/ViewContext.hpp"

#include <QQmlContext>
#include "Application/Gui/Activities/ActivitiesGitHubViewModel.hpp"
#include "Application/Gui/Activities/ActivitiesJiraViewModel.hpp"
#include "Application/Gui/Common/BaseViewModelDependencies.hpp"
#include "Application/Gui/MainWindow/MainWindowViewModel.hpp"
#include "Application/Gui/Reports/ReportsGenerateViewModel.hpp"
#include "Application/Gui/Reports/ReportsPreGenerateViewModel.hpp"
#include "Application/Gui/Settings/SettingsMainMenuViewModel.hpp"
#include "Application/Gui/Settings/SettingsSubMenuViewModel.hpp"
#include "Application/Gui/ViewManagement/ViewManager.hpp"
#include "Application/Gui/Welcome/WelcomeViewModel.hpp"

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
            return std::make_unique<MainWindow::MainWindowViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/Welcome.qml"));
        viewConfiguration.setFsmStateName("Welcome");
        viewConfiguration.setViewModelName("welcomeViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Welcome::WelcomeViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/SettingsMainMenu.qml"));
        viewConfiguration.setFsmStateName("SettingsMainMenu");
        viewConfiguration.setViewModelName("settingsMainMenuViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Settings::SettingsMainMenuViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/SettingsSubMenu.qml"));
        viewConfiguration.setFsmStateName("SettingsSubMenu");
        viewConfiguration.setViewModelName("settingsSubMenuViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Settings::SettingsSubMenuViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/ActivitiesGitHub.qml"));
        viewConfiguration.setFsmStateName("ActivitiesGitHub");
        viewConfiguration.setViewModelName("activitiesGitHubViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Activities::ActivitiesGitHubViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/ActivitiesJira.qml"));
        viewConfiguration.setFsmStateName("ActivitiesJira");
        viewConfiguration.setViewModelName("activitiesJiraViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Activities::ActivitiesJiraViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/ReportsPreGenerate.qml"));
        viewConfiguration.setFsmStateName("ReportsPreGenerate");
        viewConfiguration.setViewModelName("reportsPreGenerateViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Reports::ReportsPreGenerateViewModel>(m_baseViewModelDependencies);
        });
    });

    viewManager->registerView([&](Framework::ViewManagement::AppViewConfiguration& viewConfiguration) {
        viewConfiguration.setQmlUrl(QUrl("qrc:/views/ReportsGenerate.qml"));
        viewConfiguration.setFsmStateName("ReportsGenerate");
        viewConfiguration.setViewModelName("reportsGenerateViewModel");
        viewConfiguration.setViewModelInstantiator([&]() -> std::unique_ptr<Framework::ViewManagement::ViewModel> {
            return std::make_unique<Reports::ReportsGenerateViewModel>(m_baseViewModelDependencies);
        });
    });
}

} // namespace ViewManagement
} // namespace Gui
} // namespace Application
