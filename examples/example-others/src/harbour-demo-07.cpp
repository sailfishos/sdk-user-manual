#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>
#include "counter-07.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    qmlRegisterType<Counter>("harbour.sailfishapp.counter", 1, 0, "Counter");
    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    Counter * counter = view->rootObject()->findChild<Counter *>("counter");

    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [counter](){
        counter->setCount(counter->count() + 1);
    });
    timer.start();

    view->show();

    return app->exec();
}
