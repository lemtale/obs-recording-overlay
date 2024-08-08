#include "src/core/coloroptionenum.h"
#include <QApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <src/systemtray.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterSingletonType<ColorOption>(
        "OBSRecordingOverlay", 1, 0, "ColorOption", [](QQmlEngine *, QJSEngine *) -> QObject * {
            return new ColorOption();
        });
    qmlRegisterSingletonType(QUrl("qrc:/qml/themes/Theme.qml"), "Theme", 1, 0, "Theme");

    SystemTray systemTray(&engine);
    app.setWindowIcon(QIcon(":/resources/logo.png"));

    engine.rootContext()->setContextProperty("systemTray", &systemTray);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
