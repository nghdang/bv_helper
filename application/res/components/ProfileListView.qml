import QtQuick
import QtQuick.Controls

Item {
    property bool hasBackButton: false
    property var profileListModel

    signal next
    signal back

    ListView {
        id: profileListView
        width: parent.width
        anchors {
            top: parent.top
            bottom: footer.top
            horizontalCenter: parent.horizontalCenter
        }
        model: profileListModel
        delegate: SettingMainMenu {
            width: parent ? parent.width : -1
            getCategoryModel: function () {
                return categoryListModel
            }
        }
        ScrollBar.vertical: ScrollBar {
            height: 3
        }
    }

    Row {
        id: footer
        width: parent.width - 20
        height: 60
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        layoutDirection: Qt.RightToLeft
        spacing: 10

        Button {
            id: nextButton
            width: 120
            height: 40
            text: "Next"
            onClicked: next()
        }

        Button {
            id: backButton
            width: 120
            height: 40
            visible: hasBackButton
            text: "Back"
            onClicked: back()
        }
    }
}
