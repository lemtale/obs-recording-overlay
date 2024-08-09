import QtQuick 2.15
import QtQuick.Layouts 1.15
import Qt5Compat.GraphicalEffects
import Theme 1.0

Rectangle {
    id: root
    anchors.fill: parent
    color: Theme.dark6

    property bool isConnected: false

    Row {
        height: parent.height
        spacing: 12
        anchors.horizontalCenter: parent.horizontalCenter

        padding: Theme.spacingXS

        Item {
            width: Theme.fontSizeXL
            height: Theme.fontSizeXL
            anchors.verticalCenter: parent.verticalCenter

            Image {
                id: icon
                source: "qrc:/resources/icons/circle.svg"
                width: Theme.fontSizeXL
                height: Theme.fontSizeXL
                smooth: true
                visible: false
            }

            ColorOverlay {
                anchors.fill: icon
                source: icon
                color: root.isConnected ? Theme.green6 : Theme.red6
            }
        }

        Text {
            id: text
            text: root.isConnected ? "Connected" : "Disconnected"
            color: root.isConnected ? Theme.green6 : Theme.red6
            font.pixelSize: Theme.fontSizeSM
            font.weight: 600

            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
