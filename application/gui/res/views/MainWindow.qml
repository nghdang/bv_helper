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

    Drawer {
        id: drawer
        width: window.width * 2 / 3
        height: window.height

        ListView {
            focus: true
            anchors.fill: parent
            delegate: ItemDelegate {
                width: parent.width
                text: model.text
                highlighted: ListView.isCurrentItem
                onClicked: drawer.close()
            }
            model: ListModel {
                ListElement {
                    text: qsTr("User Profile")
                }
                ListElement {
                    text: qsTr("Team Profile")
                }
            }
        }
    }
}
