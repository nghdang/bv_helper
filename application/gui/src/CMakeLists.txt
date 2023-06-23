set(SOURCES
    Common/BaseViewModel.cpp
    Common/BaseViewModelDependencies.cpp
    Core/Main.cpp
    Core/HeaderBarModel.cpp
    Core/GuiApplication.cpp
    ViewManagement/ViewManager.cpp
    ViewManagement/ViewContext.cpp
    MainWindow/MainWindowViewModel.cpp
    Welcome/WelcomeViewModel.cpp
    Settings/SettingsMainMenuViewModel.cpp
    Settings/SettingsSubMenuViewModel.cpp
    Activities/ActivitiesGitHubViewModel.cpp
    Activities/ActivitiesJiraViewModel.cpp
    Reports/ReportsPreGenerateViewModel.cpp
    Reports/ReportsGenerateViewModel.cpp)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
