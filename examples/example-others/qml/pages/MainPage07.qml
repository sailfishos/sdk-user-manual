import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sailfishapp.counter 1.0 // Import the singleton type

Page {
    id: page
    // Instantiate a Counter object
    property Counter qmlcounter: Counter {
        objectName: "counter" // Optionally allow access from C++
        count: 5 // Initialise the value of the property
    }

    Column {
        id: column
        width: page.width
        spacing: Theme.paddingLarge
        Label {
            x: Theme.horizontalPageMargin
            text: qsTr("Counting ") + qmlcounter.count // Access the object
                                                       // property
            color: Theme.secondaryHighlightColor
            font.pixelSize: Theme.fontSizeExtraLarge
        }
    }
}
