#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QImage>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "imageprovider.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/rectangles/Main.qml"_qs);
    ImageProvider *imageProvider = new ImageProvider();
    engine.addImageProvider(QLatin1String("refreshedImage"), imageProvider);


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

