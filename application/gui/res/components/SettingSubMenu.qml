import QtQuick
import QtQuick.Controls

Column {
    Repeater {
        anchors.fill: parent
        model: getCategoryModel()
        delegate: Row {
            width: parent ? parent.width - 20 : -1
            height: 50
            anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined
            spacing: 10

            Label {
                id: infoKey
                width: parent.width * 0.3
                height: 40
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                text: key
                font.pixelSize: 20
            }

            TextField {
                width: parent.width - infoKey.width - parent.spacing
                anchors.verticalCenter: parent.verticalCenter
                height: 40
                text: value
                onEditingFinished: value = text
            }
        }
    }
}
