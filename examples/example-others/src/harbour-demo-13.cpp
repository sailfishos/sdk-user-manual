#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>
#include "counter.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    // Establish the correct location for the data files
    QString data_dir =
            QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile file(QDir(data_dir).filePath("count.data"));

    // Read in the configuration if it exists
    int startcount = 1;
    if (file.open(QIODevice::ReadOnly)) {
        startcount = file.readLine().toInt();
        file.close();
    }

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

    // Create the data directory if it doesn't already exit
    QDir dir;
    dir.mkpath(data_dir);

    // Write out the data
    startcount = counter.count();
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QString::number(startcount).toUtf8());
        file.close();
    }

    return result;
}
