set(FW_SOURCES
    StateMachine/GuiStateMachine.cpp
    StateMachine/DataModel.cpp
    ViewManagement/ViewManager.cpp
    ViewManagement/ViewManagerConfiguration.cpp
    ViewManagement/AppWindow.cpp
    ViewManagement/AppWindowConfiguration.cpp
    ViewManagement/AppView.cpp
    ViewManagement/AppViewConfiguration.cpp
    ViewManagement/ViewModel.cpp
    ViewManagement/StackViewDriver.cpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_SOURCES})
