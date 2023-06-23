import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    Rectangle {
        id: background
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: "#B0A3E5"
            }
            GradientStop {
                position: 1.0
                color: "#7661C5"
            }
        }
    }

    Rectangle {
        id: firstUseSelection
        width: 345
        height: 244
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: (parent.width - width) / 2
        color: "#FFFFFF"
        radius: 20

        Label {
            id: welcomeLabel
            width: 261
            height: 28
            anchors.top: parent.top
            anchors.topMargin: 25
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Welcome to BV Helper")
            font.pixelSize: 25
            font.bold: true
            color: "#1D1E20"
        }

        Label {
            id: detailLabel
            width: 294
            height: 42
            anchors.top: welcomeLabel.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Set up your personal information and\n your current project.")
            font.pixelSize: 15
            color: "#8F959E"
        }

        Row {
            height: 60
            anchors.bottom: skipLabel.top
            anchors.bottomMargin: 20
            leftPadding: 15
            rightPadding: 15
            spacing: 10

            RoundButton {
                id: noButton
                width: 152
                height: 60
                text: qsTr("No")
                background: Rectangle {
                    id: noButtonBackground
                    color: "#F5F6FA"
                    radius: 10
                }
                contentItem: Label {
                    id: noButtonLabel
                    text: noButton.text
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "#8F959E"
                    font.pixelSize: 17
                }
                onClicked: {
                    noButtonBackground.color = "#9775FA"
                    noButtonLabel.color = "#FFFFFF"
                    yesButtonBackground.color = "#F5F6FA"
                    yesButtonLabel.color = "#8F959E"
                }
            }

            RoundButton {
                id: yesButton
                width: 152
                height: 60
                text: qsTr("Yes")
                background: Rectangle {
                    id: yesButtonBackground
                    color: "#9775FA"
                    radius: 10
                }
                contentItem: Label {
                    id: yesButtonLabel
                    text: yesButton.text
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "#FFFFFF"
                    font.pixelSize: 17
                }
                onClicked: {
                    noButtonBackground.color = "#F5F6FA"
                    noButtonLabel.color = "#8F959E"
                    yesButtonBackground.color = "#9775FA"
                    yesButtonLabel.color = "#FFFFFF"
                }
            }
        }

        Label {
            id: skipLabel
            width: 36
            height: 19
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Skip")
            color: "#8F959E"
            font.pixelSize: 17
            font.underline: true

            MouseArea {
                anchors.fill: parent
            }
        }
    }
}
