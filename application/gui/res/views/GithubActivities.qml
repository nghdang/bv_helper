import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import "../components"

Item {
    id: root
    readonly property string header: qsTr("GitHub Activities")
    readonly property string dateFormat: "yyyy-MM-dd"
    property bool isSelectingStartDate

    function sendRequest(url, responseHandler) {
        var xhr = new XMLHttpRequest()
        xhr.onreadystatechange = function () {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                githubRequestProgressBar.value = 100
                //                githubRequestProgressDialog.close()
                if (xhr.status === 200) {
                    var response = JSON.parse(xhr.responseText)
                    responseHandler(response)
                } else {
                    console.error("Request failed with status", xhr.status, url)
                }
            } else if (xhr.readyState === XMLHttpRequest.OPENED) {
                //                githubRequestProgressDialog.open()
                githubRequestProgressBar.value = 50
            } else if (xhr.readyState === XMLHttpRequest.LOADING) {
                githubRequestProgressBar.value = 90
            }
        }
        xhr.open("GET", "https://production.github.bshg.com/api/v3/" + url)
        xhr.setRequestHeader("Authorization", "Bearer " + tokenValue.text)
        xhr.send()
    }

    Dialog {
        id: githubRequestProgressDialog
        width: 300
        height: 100
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        title: qsTr("Processing Request")

        ProgressBar {
            id: githubRequestProgressBar
            width: parent.width
            from: 0
            to: 100
        }
    }

    CalendarPopup {
        id: calendarPopup
        width: 300
        height: 200
        locale: Qt.locale("en_US")
        onOpened: {
            var currentDateText = isSelectingStartDate ? startDateValue.text : endDateValue.text
            if (currentDateText.length) {
                selectedDate = Date.fromLocaleDateString(locale,
                                                         currentDateText,
                                                         dateFormat)
            } else {
                selectedDate = new Date()
            }
        }

        onSelected: function (date) {
            var selectedDateText = date.toLocaleDateString(locale, dateFormat)
            if (isSelectingStartDate) {
                startDateValue.text = selectedDateText
            } else {
                endDateValue.text = selectedDateText
            }

            calendarPopup.close()
        }
    }

    AddPRojectDialog {
        id: addProjectDialog
        width: 500
        height: 170
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

        onAccepted: {
            var project = org + "/" + repo
            for (var i = 0; i < projectComboBox.model.count; i++) {
                if (projectComboBox.model.get(i).text === project) {
                    return
                }
            }
            projectComboBox.model.append({
                                             "text": project
                                         })
            if (projectComboBox.currentIndex < 0) {
                projectComboBox.currentIndex = 0
            }
        }
    }

    Column {
        width: parent.width
        height: parent.height
        spacing: 10

        RowLayout {
            id: tokenRow
            width: parent.width
            height: 40
            spacing: 10

            Label {
                id: tokenLabel
                Layout.fillHeight: true
                verticalAlignment: Text.AlignVCenter
                text: qsTr("Access Token")
            }

            TextField {
                id: tokenValue
                Layout.fillWidth: true
                Layout.fillHeight: true
                echoMode: TextInput.Password
                text: "d972fe496f0b8be549999ff1edbb93b90bde9577"

                Button {
                    id: tokenVisibleButton
                    width: parent.height - 10
                    height: parent.height - 10
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Visible")
                    onClicked: {
                        tokenValue.echoMode === TextInput.Password ? tokenValue.echoMode = TextInput.Normal : tokenValue.echoMode = TextInput.Password
                    }
                }
            }
        }

        RowLayout {
            id: projectsRow
            width: parent.width
            height: 40
            spacing: 10

            ComboBox {
                id: projectComboBox
                Layout.fillWidth: true
                Layout.fillHeight: true
                model: ListModel {
                    ListElement {
                        text: "EOX6/frontend_SEAV2"
                    }
                }
            }

            Button {
                id: addButton
                Layout.fillHeight: true
                text: qsTr("Add")
                onClicked: {
                    addProjectDialog.open()
                }
            }

            Button {
                id: removeButton
                Layout.fillHeight: true
                text: qsTr("Remove")
                onClicked: {
                    projectComboBox.model.remove(projectComboBox.currentIndex)
                }
            }
        }

        RowLayout {
            id: durationRow
            width: parent.width
            height: 40
            spacing: 10

            Label {
                id: startDateLabel
                Layout.fillHeight: true
                verticalAlignment: Text.AlignVCenter
                text: qsTr("Start Date")
            }

            TextField {
                id: startDateValue
                Layout.fillWidth: true
                Layout.fillHeight: true
                horizontalAlignment: Text.AlignRight
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        isSelectingStartDate = true
                        var pos = startDateValue.mapToItem(root, 0, 0)
                        calendarPopup.x = Math.min(
                                    pos.x,
                                    root.x + root.width - calendarPopup.width)
                        calendarPopup.y = pos.y + startDateValue.height
                        calendarPopup.open()
                    }
                }
                Component.onCompleted: {
                    var now = new Date()
                    var last5Days = new Date(now.getTime(
                                                 ) - (5 * 24 * 60 * 60 * 1000))
                    text = last5Days.toLocaleDateString(calendarPopup.locale,
                                                        dateFormat)
                }
            }

            Label {
                id: endDateLabel
                Layout.fillHeight: true
                verticalAlignment: Text.AlignVCenter
                text: qsTr("End Date")
            }

            TextField {
                id: endDateValue
                Layout.fillWidth: true
                Layout.fillHeight: true
                horizontalAlignment: Text.AlignRight
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        isSelectingStartDate = false
                        var pos = endDateValue.mapToItem(root, 0, 0)
                        calendarPopup.x = Math.min(
                                    pos.x,
                                    root.x + root.width - calendarPopup.width)
                        calendarPopup.y = pos.y + endDateValue.height
                        calendarPopup.open()
                    }
                }
                Component.onCompleted: {
                    var now = new Date()
                    text = now.toLocaleDateString(calendarPopup.locale,
                                                  dateFormat)
                }
            }

            Button {
                id: fetchButton
                Layout.fillHeight: true
                text: qsTr("Fetch")
                onClicked: {
                    var pullsResHandler = function (pullsRes) {
                        var pulls = {}
                        var fromDate = Date.fromLocaleString(
                                    calendarPopup.locale, startDateValue.text,
                                    "yyyy-MM-dd")
                        var toDate = Date.fromLocaleString(
                                    calendarPopup.locale, endDateValue.text,
                                    "yyyy-MM-dd")
                        for (var i = 0; i < pullsRes.length; i++) {
                            var pull = pullsRes[i]
                            if (pull.user.login === "extNguyenD") {
                                var createdDate = Date.fromLocaleString(
                                            calendarPopup.locale,
                                            pull.created_at,
                                            "yyyy-MM-ddThh:mm:ssZ")
                                var updatedDate = Date.fromLocaleString(
                                            calendarPopup.locale,
                                            pull.updated_at,
                                            "yyyy-MM-ddThh:mm:ssZ")
                                if (((createdDate.getTime() >= fromDate.getTime(
                                          )) && (createdDate.getTime(
                                                     ) <= toDate.getTime(
                                                     ))) || ((updatedDate.getTime(
                                                                  ) >= fromDate.getTime(
                                                                  )) && (updatedDate.getTime(
                                                                             ) <= toDate.getTime(
                                                                             )))) {
                                    pulls[pull.number] = {
                                        "pullNumber": pull.number,
                                        "pullTitle": pull.title,
                                        "isSelect": Qt.Unchecked
                                    }
                                }
                            }
                        }
                        var currentPulls = []
                        for (var j = 0; j < githubActivitiesListView.model.count; j++) {
                            currentPulls.push(
                                        githubActivitiesListView.model.get(
                                            j).pullNumber)
                        }
                        for (var pullNumber in pulls) {
                            if (!currentPulls.includes(parseInt(pullNumber))) {
                                githubActivitiesListView.model.append(
                                            pulls[pullNumber])
                            }
                        }
                    }
                    sendRequest("repos/" + projectComboBox.currentText
                                + "/pulls?state=all&per_page=100",
                                pullsResHandler)
                }
            }
        }

        ListView {
            id: githubActivitiesListView
            width: parent.width
            height: parent.height - 4 * 40 - 4 * parent.spacing
            focus: true
            clip: true
            spacing: 10
            model: ListModel {}
            delegate: Row {
                width: parent ? parent.width : -1
                height: 40
                spacing: 10

                CheckBox {
                    id: activityCheckBox
                    width: parent.height
                    height: parent.height
                    indicator.implicitWidth: parent.height
                    indicator.implicitHeight: parent.height
                    tristate: false
                    checkState: Qt.Unchecked
                    onCheckStateChanged: {
                        isSelect = checkState
                        activityLabel.font.bold = checkState == Qt.Checked
                    }
                }

                Label {
                    id: activityLabel
                    width: parent.width - parent.height - parent.spacing
                    height: parent.height
                    verticalAlignment: Text.AlignVCenter
                    text: pullTitle + "(#" + pullNumber + ")"
                    font.pixelSize: 20
                }
            }
        }

        RowLayout {
            id: footerRow
            height: 40
            anchors.right: parent.right
            spacing: 10

            Button {
                id: backButton
                Layout.preferredWidth: 120
                Layout.fillHeight: true
                text: qsTr("Back")
                onClicked: githubActivitiesViewModel.enterBack()
            }

            Button {
                id: refreshButton
                Layout.preferredWidth: 120
                Layout.fillHeight: true
                text: qsTr("Refresh")
            }

            Button {
                id: nextButton
                Layout.preferredWidth: 120
                Layout.fillHeight: true
                text: qsTr("Next")
            }
        }
    }
}
