import QtQuick
import QtQuick.Controls

Item {
    property StackView stackView

    function pushView(srcView, desView) {
        var found = false
        stackView.find(function (item, index) {
            found = desView === item
            return found
        })
        if (!found)
            stackView.push(desView)
    }

    function popView(srcView, desView) {
        stackView.pop()
    }
}
