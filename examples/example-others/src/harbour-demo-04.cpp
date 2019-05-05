#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());
    QQmlContext *context = view->rootContext();

    int count = 0;
    context->setContextProperty("count", count);

    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, [&count, context](){
        count++;
        context->setContextProperty("count", count); // Update variable value
                                                     // once per second

    });
    timer.start();

    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    view->show();

    return app->exec();
}
