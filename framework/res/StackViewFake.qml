import QtQuick
import QtQuick.Controls

Item {
    property StackView stackView

    function pushView(view) {
        stackView.push(view)
    }

    function popView() {
        stackView.pop()
    }
}
