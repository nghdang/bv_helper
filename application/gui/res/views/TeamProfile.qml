import QtQuick
import QtQuick.Controls

import "../components"

ProfileListView {
    id: teamProfileView
    hasBackButton: true
    profileListModel: teamProfileViewModel.profileListModel
    onNext: teamProfileViewModel.enterGitHubActivities()
    onBack: teamProfileViewModel.enterBack()
}
