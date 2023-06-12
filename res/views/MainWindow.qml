import QtQuick
import QtQuick.Controls

import "../components"

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("BV Helper")

    header: ToolBar {
        height: 60
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
            text: qsTr("User Profile")
            font {
                bold: true
                pixelSize: 32
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: mainWindowViewModel.isFirstUse ? userProfileContainer : githubActivitiesContainer
        onCurrentItemChanged: toolBarHeader.text = currentItem.header
    }

    TeamProfileListModel {
        id: teamProfileListModel
    }

    Component {
        id: userProfileContainer

        ProfileListView {
            id: userProfileView
            header: userProfileViewModel.headerText
            hasBackButton: false
            profileListModel: userProfileViewModel.profileListModel
            onNext: {
                //                userProfileListModel.saveToJson()
                stackView.push(teamProfileContainer)
            }
            Component.onCompleted: {

                //                userProfileListModel.loadFromJson()
            }
        }
    }

    Component {
        id: teamProfileContainer

        ProfileListView {
            id: teamProfileView
            header: teamProfileViewModel.headerText
            hasBackButton: true
            profileListModel: teamProfileViewModel.profileListModel
            onBack: {
                stackView.pop()
            }
            onNext: {
                //                teamProfileListModel.saveToJson()
                stackView.push(githubActivitiesContainer)
            }
            //            Component.onCompleted: teamProfileListModel.loadFromJson()
        }
    }

    Component {
        id: githubActivitiesContainer

        GithubActivities {
            id: githubActivitiesView
        }
    }
}
