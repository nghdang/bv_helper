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
        }
    }

    Component {
        id: teamProfileContainer

        TeamProfile {
            id: teamProfileView
        }
    }

    Component {
        id: githubActivitiesContainer

        GithubActivities {
            id: githubActivitiesView
        }
    }
}
