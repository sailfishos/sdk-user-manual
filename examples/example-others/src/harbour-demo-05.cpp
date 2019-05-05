#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>
#include "counter.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());
    QQmlContext *context = view->rootContext();

    Counter counter;
    context->setContextObject(&counter); // Expose all properties of counter to
                                         // the QML

    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [&counter](){
        counter.setCount(counter.count() + 1); // Changes are automatically
                                               // reflected in the UI
    });
    timer.start();

    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    view->show();

    return app->exec();
}
