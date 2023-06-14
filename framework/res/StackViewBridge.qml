import QtQuick
import QtQuick.Controls

Item {
    property StackView stackView

    function pushView(srcView, desView) {
        console.log("pushView", srcView, desView)
        stackView.push(desView, [], StackView.Immediate)
    }

    function popView(srcView, desView) {
        console.log("popView", srcView, desView)
        stackView.pop(StackView.Immediate)
    }
}
