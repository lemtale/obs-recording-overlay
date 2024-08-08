import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Effects
import Qt5Compat.GraphicalEffects
import OBSRecordingOverlay 1.0
import Theme 1.0

Rectangle {
    id: root
    anchors.fill: parent
    color: Theme.dark6

    property string buttonText: "Menu Item"
    property string iconSource: ""
    property int colorOption: ColorOption.Default

    signal onClick

    states: [
        State {
            name: "default"
            when: root.colorOption == ColorOption.Default
            PropertyChanges {
                target: button
                color: Theme.dark6
            }
            PropertyChanges {
                target: iconColorOverlay
                color: Theme.colorText
            }
            PropertyChanges {
                target: text
                color: Theme.colorText
            }
            PropertyChanges {
                target: buttonMouseArea
                onEntered: button.color = Theme.dark4
            }
            PropertyChanges {
                target: buttonMouseArea
                onExited: button.color = Theme.dark6
            }
        },
        State {
            name: "red"
            when: root.colorOption == ColorOption.Red
            PropertyChanges {
                target: button
                color: "transparent"
            }
            PropertyChanges {
                target: iconColorOverlay
                color: Theme.red6
            }
            PropertyChanges {
                target: text
                color: Theme.red6
            }
            PropertyChanges {
                target: buttonMouseArea
                onEntered: button.color = Theme.redLightHover
            }
            PropertyChanges {
                target: buttonMouseArea
                onExited: button.color = "transparent"
            }
        }
    ]

    Rectangle {
        id: button
        anchors.fill: parent
        radius: Theme.radiusSM

        Behavior on color {
            ColorAnimation {
                duration: 100
            }
        }

        Row {
            height: parent.height
            spacing: root.iconSource.length > 0 ? 8 : 0

            topPadding: Theme.spacingXS / 1.5
            bottomPadding: Theme.spacingXS / 1.5
            leftPadding: Theme.spacingXS
            rightPadding: Theme.spacingXS

            Item {
                readonly property bool hasIcon: root.iconSource.length > 0

                id: iconWrapper
                width: iconWrapper.hasIcon ? Theme.fontSizeMD : 0
                height: iconWrapper.hasIcon ? Theme.fontSizeMD : 0
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    id: icon
                    source: root.iconSource
                    width: iconWrapper.hasIcon ? Theme.fontSizeMD : 0
                    height: iconWrapper.hasIcon ? Theme.fontSizeMD : 0
                    smooth: true
                    visible: false
                }

                ColorOverlay {
                    id: iconColorOverlay
                    anchors.fill: icon
                    source: icon
                }
            }

            Text {
                id: text
                text: root.buttonText
                font.pixelSize: Theme.fontSizeSM
                font.weight: 600
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        MouseArea {
            id: buttonMouseArea
            anchors.fill: button
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor

            onClicked: root.onClick()
        }
    }
}
