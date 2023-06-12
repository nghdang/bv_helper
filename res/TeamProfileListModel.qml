import QtQuick

ProfileListModel {
    jsonPath: "team_profile.json"

    categoryListModel: ListModel {
        ListElement {
            category: qsTr("Leader")
        }
        ListElement {
            category: qsTr("Reporter")
        }
        ListElement {
            category: qsTr("Coordinator")
        }
        ListElement {
            category: qsTr("Manager")
        }
    }

    categoryModels: {
        "Leader": reporterListModel,
        "Reporter": leaderListModel,
        "Coordinator": coordinatorListModel,
        "Manager": managerListModel
    }

    ListModel {
        id: reporterListModel
        ListElement {
            key: qsTr("First Name")
            value: qsTr("Long")
        }
        ListElement {
            key: qsTr("Last Name")
            value: qsTr("Le")
        }
        ListElement {
            key: qsTr("Bosch Email")
            value: qsTr("external.Long.LePhi@bcn.bosch.com")
        }
    }

    ListModel {
        id: leaderListModel
        ListElement {
            key: qsTr("First Name")
            value: qsTr("Dang")
        }
        ListElement {
            key: qsTr("Last Name")
            value: qsTr("Nguyen")
        }
        ListElement {
            key: qsTr("BSH Email")
            value: qsTr("Dang.Nguyen-ext@bshg.com")
        }
    }

    ListModel {
        id: coordinatorListModel
        ListElement {
            key: qsTr("First Name")
            value: qsTr("Thuong")
        }
        ListElement {
            key: qsTr("Last Name")
            value: qsTr("Nguyen")
        }
        ListElement {
            key: qsTr("BV Email")
            value: qsTr("thuong.nguyen-hoai@banvien.com.vn")
        }
    }

    ListModel {
        id: managerListModel
        ListElement {
            key: qsTr("First Name")
            value: qsTr("Khanh")
        }
        ListElement {
            key: qsTr("Last Name")
            value: qsTr("Chu")
        }
        ListElement {
            key: qsTr("BV Email")
            value: qsTr("khanh.chu@banvien.com.vn")
        }
    }
}
