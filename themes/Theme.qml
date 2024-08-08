pragma Singleton
import QtQuick 2.15

QtObject {
    id: theme

    // Styles from mantine.dev

    // Colors
    readonly property color dark0: "#C9C9C9"
    readonly property color dark2: "#828282"
    readonly property color dark4: "#424242"
    readonly property color dark6: "#2E2E2E"

    readonly property color red6: "#FA5252"
    readonly property color redLightHover: "#33FA5252"

    property alias colorText: theme.dark0
    property alias colorDimmed: theme.dark2

    // Radius
    readonly property int radiusXS: 2
    readonly property int radiusSM: 4
    readonly property int radiusMD: 8
    readonly property int radiusLG: 16
    readonly property int radiusXL: 32

    // Font size
    readonly property int fontSizeXS: 12
    readonly property int fontSizeSM: 14
    readonly property int fontSizeMD: 16
    readonly property int fontSizeLG: 18
    readonly property int fontSizeXL: 20

    // Spacing
    readonly property int spacingXXS: 4
    readonly property int spacingXS: 10
    readonly property int spacingSM: 12
    readonly property int spacingMD: 16
    readonly property int spacingLG: 20
    readonly property int spacingXL: 32
}
