set(SOURCES
    Common/ProfileListModel.cpp
    Common/ProfileCategoryListModel.cpp
    Common/BaseViewModel.cpp
    Common/BaseViewModelDependencies.cpp
    Appliance/Main.cpp
    Appliance/HeaderBarModel.cpp
    MainWindow/MainWindowViewModel.cpp
    UserProfile/UserProfileViewModel.cpp
    TeamProfile/TeamProfileViewModel.cpp
    GithubActivities/GithubActivitiesViewModel.cpp
    JiraActivites/JiraActivitesViewModel.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
