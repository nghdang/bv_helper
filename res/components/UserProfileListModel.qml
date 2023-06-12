import QtQuick

ProfileListModel {
    jsonPath: "user_profile.json"

    categoryListModel: ListModel {
        ListElement {
            category: qsTr("Personal")
        }
        ListElement {
            category: qsTr("Contact")
        }
        ListElement {
            category: qsTr("Project")
        }
    }

    categoryModels: {
        "Personal": personalListModel,
        "Contact": contactListModel,
        "Project": projectListModel
    }

    ListModel {
        id: personalListModel

        ListElement {
            key: qsTr("Role")
            value: qsTr("")
        }
        ListElement {
            key: qsTr("First Name")
            value: qsTr("")
        }
        ListElement {
            key: qsTr("Last Name")
            value: qsTr("")
        }
    }

    ListModel {
        id: contactListModel

        ListElement {
            key: qsTr("BSH Username")
            value: qsTr("")
        }
        ListElement {
            key: qsTr("BSH Email")
            value: qsTr("")
        }
    }

    ListModel {
        id: projectListModel

        ListElement {
            key: qsTr("Project full name")
            value: qsTr("")
        }
        ListElement {
            key: qsTr("Project short name")
            value: qsTr("")
        }
    }
}
