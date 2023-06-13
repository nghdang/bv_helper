import QtQuick
import QtQuick.Controls

import "../components"

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("BV Helper")

    header: HeaderBar {
        id: headerBar
        height: 60
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: mainWindowViewModel.isFirstUse ? userProfileContainer : githubActivitiesContainer
    }

    Component {
        id: userProfileContainer

        UserProfile {
            id: userProfileView
            onNext: {
                //                userProfileListModel.saveToJson()
                stackView.push(teamProfileContainer)
            }
        }
    }

    Component {
        id: teamProfileContainer

        TeamProfile {
            id: teamProfileView
            onBack: {
                stackView.pop()
            }
            onNext: {
                //                teamProfileListModel.saveToJson()
                stackView.push(githubActivitiesContainer)
            }
        }
    }

    Component {
        id: githubActivitiesContainer

        GithubActivities {
            id: githubActivitiesView
        }
    }
}
