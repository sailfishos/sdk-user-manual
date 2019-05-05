TARGET = harbour-demo

CONFIG += sailfishapp

SOURCES += src/harbour-demo.cpp

DISTFILES += qml/harbour-demo.qml \
    qml/cover/CoverPage.qml \
    qml/pages/MainPage.qml \
    rpm/harbour-demo.spec \
    harbour-demo.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

HEADERS +=

OTHER_FILES += README \
    rpm/harbour-demo.spec \
    rpm/harbour-demo.yaml

