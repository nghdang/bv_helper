import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Dialog {
    id: projectDialog

    property alias org: orgComboBox.currentText
    property alias repo: repoComboBox.currentText

    title: qsTr("Project")
    standardButtons: Dialog.Ok | Dialog.Cancel

    GridLayout {
        width: parent.width
        height: 80
        rows: 2
        columns: 2

        Label {
            id: orgLabel
            Layout.row: 0
            Layout.column: 0
            Layout.preferredWidth: 170
            Layout.preferredHeight: parent.height / 2
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Organization")
        }

        ComboBox {
            id: orgComboBox
            Layout.row: 1
            Layout.column: 0
            Layout.preferredWidth: 170
            Layout.preferredHeight: parent.height / 2

            onCurrentTextChanged: function () {
                var repoResHandler = function (repoRes) {
                    var repos = []
                    for (var i = 0; i < repoRes.length; i++) {
                        repos.push(repoRes[i].name)
                    }
                    repoComboBox.model = repos.sort()
                }
                sendRequest("orgs/" + orgComboBox.currentText + "/repos",
                            repoResHandler)
            }
        }

        Label {
            id: repoLabel
            Layout.row: 0
            Layout.column: 1
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 2
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Repository")
        }

        ComboBox {
            id: repoComboBox
            Layout.row: 1
            Layout.column: 1
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 2
        }
    }

    Component.onCompleted: {
        var orgResHandler = function (orgRes) {
            var orgs = []
            for (var i = 0; i < orgRes.length; i++) {
                orgs.push(orgRes[i].login)
            }
            orgComboBox.model = orgs.sort()
        }
        sendRequest("user/orgs", orgResHandler)
    }
}
