#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    // Access the counter property defined in the QML
    QObject * counter = view->rootObject()->findChild<QObject *>("counter");

    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [counter](){
        counter->setProperty("count", counter->property("count").toInt() + 1);
    });
    timer.start();

    view->show();

    return app->exec();
}
