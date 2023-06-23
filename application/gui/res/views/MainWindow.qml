import QtQuick
import QtQuick.Controls

import "../components"

ApplicationWindow {
    id: window
    width: 375
    height: 812
    visible: true
    title: qsTr("BV Helper")

    header: HeaderBar {
        id: headerBar
        height: 60
        model: mainWindowViewModel.headerBarModel
    }

    StackView {
        id: stackView
        objectName: "app-content"
        anchors.fill: parent
    }
}
