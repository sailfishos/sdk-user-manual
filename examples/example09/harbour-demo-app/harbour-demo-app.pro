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

INCLUDEPATH += $$PWD/../libdemo

LIBS += -L../libdemo/lib -ldemo

libdemo.files += ../libdemo/lib
libdemo.path = /usr/share/$${TARGET}

INSTALLS += libdemo
