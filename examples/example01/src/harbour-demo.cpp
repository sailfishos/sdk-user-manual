#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    view->setSource(SailfishApp::pathTo(QString("qml/harbour-demo.qml")));
    view->show();

    return app->exec();
}
