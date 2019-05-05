import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sailfishapp.counter 1.0 // Import the QML module

Page {
    id: page
    // Use the type imported from the module
    property Counter qmlcounter: Counter {
        objectName: "counter"
        count: 5
    }

    Column {
        id: column
        width: page.width
        spacing: Theme.paddingLarge
        Label {
            x: Theme.horizontalPageMargin
            text: qsTr("Counting ") + qmlcounter.count
            color: Theme.secondaryHighlightColor
            font.pixelSize: Theme.fontSizeExtraLarge
        }
    }
}
