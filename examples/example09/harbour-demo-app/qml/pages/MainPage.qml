import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    Column {
        id: column
        width: page.width
        spacing: Theme.paddingLarge
        Label {
            x: Theme.horizontalPageMargin
            text: qsTr("Counting ") + count // Variable takes value set in C++
            color: Theme.secondaryHighlightColor
            font.pixelSize: Theme.fontSizeExtraLarge
        }
    }
}
