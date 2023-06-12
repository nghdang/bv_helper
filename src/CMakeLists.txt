set(SOURCES
    Appliance/Main.cpp
    Common/ProfileListModel.cpp
    Common/ProfileCategoryListModel.cpp
    MainWindow/MainWindowViewModel.cpp
    UserProfile/UserProfileViewModel.cpp
    TeamProfile/TeamProfileViewModel.cpp
    GithubActivities/GithubActivitiesViewModel.cpp
    JiraActivites/JiraActivitesViewModel.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
