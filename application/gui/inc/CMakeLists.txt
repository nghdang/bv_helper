set(HEADERS
    Application/Gui/Common/BaseViewModel.hpp
    Application/Gui/Common/BaseViewModelDependencies.hpp
    Application/Gui/Helper/SharedConstants.hpp
    Application/Gui/Helper/SettingIds.hpp
    Application/Gui/Core/HeaderBarModel.hpp
    Application/Gui/Core/GuiApplication.hpp
    Application/Gui/ViewManagement/ViewManager.hpp
    Application/Gui/ViewManagement/ViewContext.hpp
    Application/Gui/MainWindow/MainWindowViewModel.hpp
    Application/Gui/Welcome/WelcomeViewModel.hpp
    Application/Gui/Settings/SettingsMainMenuViewModel.hpp
    Application/Gui/Settings/SettingsSubMenuViewModel.hpp
    Application/Gui/Activities/ActivitiesGitHubViewModel.hpp
    Application/Gui/Activities/ActivitiesJiraViewModel.hpp
    Application/Gui/Reports/ReportsPreGenerateViewModel.hpp
    Application/Gui/Reports/ReportsGenerateViewModel.hpp)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
