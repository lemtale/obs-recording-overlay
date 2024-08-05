#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include <src/overlayapp.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterSingletonType(QUrl("qrc:/qml/themes/Theme.qml"), "Theme", 1, 0, "Theme");

    OverlayApp overlayApp(&engine);
    app.setWindowIcon(QIcon(":/resources/logo.png"));

    engine.rootContext()->setContextProperty("overlayApp", &overlayApp);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
