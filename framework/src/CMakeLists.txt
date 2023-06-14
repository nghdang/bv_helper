set(FW_SOURCES
    ViewManagement/ViewManager.cpp
    ViewManagement/ViewManagerConfiguration.cpp
    StateMachine/GuiStateMachine.cpp
    StateMachine/DataModel.cpp
    ViewManagement/MainWindowConfiguration.cpp
    ViewManagement/StackViewDriver.cpp
    ViewManagement/MainWindow.cpp
    ViewManagement/ViewModel.cpp
    ViewManagement/ViewConfiguration.cpp
    ViewManagement/View.cpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_SOURCES})
