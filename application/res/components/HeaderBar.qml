import QtQuick
import QtQuick.Controls

import "../components"

ToolBar {
    property var model

    ToolButton {
        id: toolBarMenuButton
        width: 80
        height: 40
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
        }
        text: qsTr("Menu")
    }
    Label {
        id: toolBarHeader
        width: parent.width - 3 * toolBarMenuButton.width
        height: 40
        anchors.centerIn: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: model.headerText
        font {
            bold: true
            pixelSize: 32
        }
    }
}
