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
            font.pixelSize: 28
            font.bold: true
        }

        Button {
            id: expandButton
            width: 80
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
        sourceComponent: Column {
            Repeater {
                anchors.fill: parent
                model: getCategoryModel()
                delegate: Row {
                    width: parent ? parent.width - 20 : -1
                    height: 50
                    anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined
                    spacing: 10

                    Label {
                        id: infoKey
                        width: 120
                        height: 40
                        anchors.verticalCenter: parent.verticalCenter
                        verticalAlignment: Text.AlignVCenter
                        text: key
                        font.pixelSize: 20
                    }

                    Loader {
                        width: parent.width - infoKey.width - parent.spacing
                        anchors.verticalCenter: parent.verticalCenter
                        height: 40
                        active: true
                        sourceComponent: {
                            if (key === qsTr("Role")) {
                                return infoValueRoleContainer
                            } else {
                                return infoValueTextContainer
                            }
                        }
                    }

                    Component {
                        id: infoValueTextContainer

                        TextField {
                            anchors.fill: parent
                            text: value
                            onEditingFinished: value = text
                        }
                    }

                    Component {
                        id: infoValueRoleContainer

                        Row {
                            anchors.fill: parent
                            RadioButton {
                                checked: !mainWindowViewModel.isLeader
                                text: qsTr("Member")
                            }
                            RadioButton {
                                checked: mainWindowViewModel.isLeader
                                text: qsTr("Leader")
                                onCheckedChanged: mainWindowViewModel.isLeader = checked
                            }
                        }
                    }
                }
            }
        }
    }
}
