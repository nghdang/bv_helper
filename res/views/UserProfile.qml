import QtQuick
import QtQuick.Controls

import "../components"

ProfileListView {
    id: userProfileView
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
