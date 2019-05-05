import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property int count: 5

    Column {
        id: column
        width: page.width
        spacing: Theme.paddingLarge
        Label {
            x: Theme.horizontalPageMargin
            text: qsTr("Counting ") + count
            color: Theme.secondaryHighlightColor
            font.pixelSize: Theme.fontSizeExtraLarge
        }
    }
}
