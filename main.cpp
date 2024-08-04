#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include <src/overlayapp.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    OverlayApp overlayApp;
    app.setWindowIcon(QIcon(":/resources/logo.png"));

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("overlayApp", &overlayApp);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
