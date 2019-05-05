#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>
#include "counter-06.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    Counter::instantiate();
    qmlRegisterSingletonType<Counter>("harbour.sailfishapp.counter",
                                      1, 0, "Counter", Counter::provider);
    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [](){
        Counter::getInstance().setCount(Counter::getInstance().count() + 1);
    });
    timer.start();

    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    view->show();

    return app->exec();
}
