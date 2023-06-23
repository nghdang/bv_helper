set(FRAMEWORK_SOURCES
    StateMachine/GuiStateMachine.cpp
    StateMachine/DataModel.cpp
    ViewManagement/ViewManager.cpp
    ViewManagement/ViewManagerConfiguration.cpp
    ViewManagement/AppView.cpp
    ViewManagement/AppWindow.cpp
    ViewManagement/AppViewConfiguration.cpp
    ViewManagement/ViewModel.cpp
    ViewManagement/StackViewDriver.cpp)

target_sources(${LIB_FRAMEWORK} PRIVATE ${FRAMEWORK_SOURCES})
