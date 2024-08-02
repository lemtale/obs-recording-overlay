import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt.labs.platform 1.1

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "OBS Recording Overlay"

    Button {
        text: "Hello world"
        anchors.centerIn: parent
    }

    SystemTrayIcon {
        visible: true
        icon.source: "qrc:/images/obs-recording-overlay-logo.png"
    }
}
