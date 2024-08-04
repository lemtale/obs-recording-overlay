import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    property string imageSource: "qrc:/resources/images/recording.png"
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
        source: imageSource
    }
}
