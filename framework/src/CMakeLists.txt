set(FW_SOURCES
    ViewManagement/ViewManager.cpp
    ViewManagement/ViewManagerConfiguration.cpp
    StateMachine/GuiStateMachine.cpp
    StateMachine/DataModel.cpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_SOURCES})
