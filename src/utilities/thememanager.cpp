#include "thememanager.h"

#include <QColor>
#include <QQmlComponent>

ThemeManager::ThemeManager(QQmlEngine *engine, QObject *parent)
    : QObject(parent), qmlEngine(engine), themeObject(nullptr)
{
    QQmlComponent component(qmlEngine, QUrl(QStringLiteral("qrc:/qml/themes/Theme.qml")));
    themeObject = component.create();
}

QColor ThemeManager::getColor(const QString &propertyName) const
{
    if (!themeObject) {
        return QColor();
    }

    QVariant colorVariant = themeObject->property(propertyName.toUtf8());
    if (!colorVariant.isValid()) {
        return QColor();
    }

    return colorVariant.value<QColor>();
}
