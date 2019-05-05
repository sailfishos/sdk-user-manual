#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());
    QQmlContext *context = view->rootContext();

    int count = 0;
    context->setContextProperty("count", count); // Set the variable for use
                                                 // in QML

    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    view->show();

    return app->exec();
}
