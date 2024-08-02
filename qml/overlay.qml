import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: Screen.width
    height: Screen.height - 1
    title: "OBS Recording Overlay"
    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.WindowTransparentForInput
    color: "transparent"

    Rectangle {
        id: overlay
        width: 40
        height: 40
        color: "transparent"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 10
        anchors.leftMargin: 10
        visible: true

        Image {
            id: statusImage
            anchors.fill: parent
            source: "qrc:/images/record-icon.png"
        }
    }
}
