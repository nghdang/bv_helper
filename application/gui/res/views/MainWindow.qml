import QtQuick
import QtQuick.Controls

import "../components"

ApplicationWindow {
    id: window
    width: 480
    height: 640
    visible: true
    title: qsTr("BV Helper")

    header: HeaderBar {
        id: headerBar
        height: 60
        model: mainWindowViewModel.headerBarModel
        onMenuButtonClicked: drawer.open()
    }

    StackView {
        id: stackView
        objectName: "app-content"
        anchors.fill: parent
    }
}
