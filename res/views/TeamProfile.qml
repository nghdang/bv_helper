import QtQuick
import QtQuick.Controls

import "../components"

ProfileListView {
    id: teamProfileView
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
