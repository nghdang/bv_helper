set(FW_SOURCES
    StateMachine/GuiStateMachine.cpp
    StateMachine/DataModel.cpp
    ViewManagement/ViewManager.cpp
    ViewManagement/ViewManagerConfiguration.cpp
    ViewManagement/Window.cpp
    ViewManagement/WindowConfiguration.cpp
    ViewManagement/View.cpp
    ViewManagement/ViewConfiguration.cpp
    ViewManagement/ViewModel.cpp
    ViewManagement/StackViewDriver.cpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_SOURCES})
