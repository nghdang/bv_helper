import QtQuick
import QtQuick.Controls

import "../components"

ProfileListView {
    id: teamProfileView
    hasBackButton: true
    profileListModel: teamProfileViewModel.profileListModel
    //            Component.onCompleted: teamProfileListModel.loadFromJson()
}
