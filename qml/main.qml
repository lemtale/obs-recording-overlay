import QtQuick 2.15
import QtQuick.Controls 2.15
import "themes"
import "Overlay"

Window {
    visible: true
    width: Screen.width
    height: Screen.height - 1
    title: "OBS Recording Overlay"
    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.WindowTransparentForInput
    color: "transparent"

    Overlay {
        imageSource: "qrc:/resources/images/paused.png"
    }
}
