import QtQuick
import QtQuick.Controls

import "../components"

Item {
    readonly property string header: "User Profile"

    signal next

    ListView {
        id: userProfileListView
        width: parent.width
        anchors {
            top: parent.top
            bottom: footer.top
            horizontalCenter: parent.horizontalCenter
        }
        model: userProfileListModel.categoryListModel
        delegate: ListViewCategoryDelegate {
            width: parent ? parent.width : -1
            getCategoryModel: function () {
                return userProfileListModel.categoryModels[category]
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
            onClicked: next()
        }
    }
}
