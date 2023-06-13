import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Popup {
    id: calendarPopup

    property var selectedDate: new Date()
    signal selected(date date)

    modal: true
    focus: true

    GridLayout {
        id: startDateCalendar
        width: parent.width
        height: parent.height
        columns: 2
        rows: 2

        Row {
            Layout.row: 0
            Layout.columnSpan: 2
            Layout.fillWidth: true
            height: 30

            Button {
                id: prevMonthButton
                width: 2 * parent.height
                height: parent.height
                text: qsTr("Prev")
                onClicked: {
                    monthGrid.month -= 1
                }
            }

            Label {
                id: currentMonthLabel
                width: parent.width - prevMonthButton.width - nextMonthButton.width
                height: parent.height
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
                text: {
                    var currentMonth = new Date(monthGrid.year, monthGrid.month)
                    return currentMonth.toLocaleDateString(monthGrid.locale,
                                                           "MMM, yyyy")
                }
            }

            Button {
                id: nextMonthButton
                width: 2 * parent.height
                height: parent.height
                text: qsTr("Next")
                onClicked: {
                    monthGrid.month += 1
                }
            }
        }

        DayOfWeekRow {
            id: dayOfWeekRow
            Layout.row: 1
            Layout.column: 1
            Layout.fillWidth: true

            locale: monthGrid.locale

            delegate: Label {
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: shortName
                font: dayOfWeekRow.font

                required property string shortName
            }
        }

        WeekNumberColumn {
            id: weekNumberColumn
            Layout.fillHeight: true

            month: monthGrid.month
            year: monthGrid.year
            locale: monthGrid.locale

            delegate: Label {
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: weekNumber
                font: dayOfWeekRow.font

                required property int weekNumber
            }
        }

        MonthGrid {
            id: monthGrid
            Layout.fillWidth: true
            Layout.fillHeight: true

            locale: calendarPopup.locale
            delegate: Label {
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                opacity: model.month === monthGrid.month ? 1 : 0.3
                font: monthGrid.font
                text: monthGrid.locale.toString(model.date, "d")

                Rectangle {
                    anchors.fill: parent
                    visible: (selectedDate.getMonth() === model.date.getMonth())
                             && (selectedDate.getDate(
                                     ) === model.date.getDate())
                    color: "transparent"
                    border.color: "green"
                }

                required property var model
            }

            onClicked: function (date) {
                selected(date)
            }

            Component.onCompleted: {
                month = selectedDate.getMonth()
                year = selectedDate.getFullYear()
            }
        }
    }
}
