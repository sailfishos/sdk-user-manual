import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sailfishapp.counter 1.0 // Import the singleton type

Page {
    id: page
    Column {
        id: column
        width: page.width
        spacing: Theme.paddingLarge
        Label {
            x: Theme.horizontalPageMargin
            text: qsTr("Counting ") + Counter.count // Access singleton property
            color: Theme.secondaryHighlightColor
            font.pixelSize: Theme.fontSizeExtraLarge
        }
    }
}
