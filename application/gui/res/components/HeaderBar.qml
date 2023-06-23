import QtQuick
import QtQuick.Controls

import "../components"

ToolBar {
    property var model

    signal menuButtonClicked
    signal backButtonClicked
    signal nextButtonClicked

    ToolButton {
        id: toolBarMenuButton
        width: 80
        height: 40
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
        }
        text: qsTr("Menu")
        onClicked: menuButtonClicked()
    }

    ToolButton {
        id: backButton
        width: 80
        height: 40
        anchors {
            left: toolBarMenuButton.right
            verticalCenter: parent.verticalCenter
        }
        visible: model.hasBackButton
        text: qsTr("Back")
        onClicked: backButtonClicked()
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

    ToolButton {
        id: nextButton
        width: 80
        height: 40
        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
        }
        visible: model.hasNextButton
        text: qsTr("Next")
        onClicked: backButtonClicked()
    }
}
