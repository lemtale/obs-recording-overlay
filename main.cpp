#include "overlayapp.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    OverlayApp overlayApp;
    app.setWindowIcon(QIcon(":/images/obs-recording-overlay-logo.png"));

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("overlayApp", &overlayApp);
    engine.load(QUrl(QStringLiteral("qrc:/qml/overlay.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
