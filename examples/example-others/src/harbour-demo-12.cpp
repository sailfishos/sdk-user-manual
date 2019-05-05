#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>
#include "counter.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    // Read in the configuration if it exists
    QSettings settings;
    int startcount = settings.value("counter/init", 1).toInt();

    QQmlContext *context = view->rootContext();
    Counter counter;
    counter.setCount(startcount);
    context->setContextObject(&counter);

    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [&counter](){
        counter.setCount(counter.count() + 1);
    });
    timer.start();

    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    view->show();

    int result = app->exec();

    // Write out the configuration
    startcount = counter.count();
    settings.setValue("counter/init", startcount);

    return result;
}
