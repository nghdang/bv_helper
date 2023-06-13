import QtQuick
import QtQuick.Controls

import "../components"

ProfileListView {
    id: userProfileView
    hasBackButton: false
    profileListModel: userProfileViewModel.profileListModel
    Component.onCompleted: {

        //                userProfileListModel.loadFromJson()
    }
}
