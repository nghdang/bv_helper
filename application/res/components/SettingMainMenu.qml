import QtQuick
import QtQuick.Controls

Column {
    property var getCategoryModel: function () {}

    Row {
        width: parent ? parent.width - 20 : -1
        height: 40
        anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined
        spacing: 10

        Label {
            width: parent.width - expandButton.width - parent.spacing
            height: parent.height
            verticalAlignment: Text.AlignVCenter
            text: category
            font.pixelSize: 24
            font.bold: true
        }

        Button {
            id: expandButton
            width: parent.width * 0.2
            height: parent.height
            state: "expanded"
            states: [
                State {
                    name: "expanded"
                    PropertyChanges {
                        target: expandButton
                        text: qsTr("Collapse")
                    }
                },
                State {
                    name: "collapsed"
                    PropertyChanges {
                        target: expandButton
                        text: qsTr("Expand")
                    }
                }
            ]
            onClicked: {
                if (state === "expanded") {
                    state = "collapsed"
                    categoryLoader.visible = false
                } else {
                    state = "expanded"
                    categoryLoader.visible = true
                }
            }
        }
    }

    Loader {
        id: categoryLoader
        width: parent.width
        active: true
        sourceComponent: SettingSubMenu {}
    }
}
