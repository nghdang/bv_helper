import QtQuick
import QtQuick.Controls

Item {
    readonly property string header: "Team Profile"

    signal back
    signal next

    TeamProfileListModel {
        id: teamProfileListModel
    }

    ListView {
        id: teamProfileListView
        width: parent.width
        anchors {
            top: parent.top
            bottom: footer.top
            horizontalCenter: parent.horizontalCenter
        }
        focus: true
        spacing: 10
        clip: true
        model: teamProfileListModel.categoryListModel
        delegate: ListViewCategoryDelegate {
            width: parent ? parent.width : -1
            getCategoryModel: function () {
                return teamProfileListModel.categoryModels[category]
            }
        }
        ScrollBar.vertical: ScrollBar {
            height: 3
        }
    }

    Row {
        id: footer
        width: parent.width
        height: 40
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        layoutDirection: Qt.RightToLeft
        spacing: 10

        Button {
            id: nextButton
            width: 120
            height: 40
            text: "Next"
            onClicked: {}
        }

        Button {
            id: backButton
            width: 120
            height: 40
            text: "Back"
            onClicked: stackView.pop()
        }
    }

}
