#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QQmlEngine>


class ThemeManager : public QObject
{
    Q_OBJECT

public:
    explicit ThemeManager(QQmlEngine *engine, QObject *parent = nullptr);

    QColor getColor(const QString &propertyName) const;
    int getIntProperty(const QString &propertyName) const;

private:
    QQmlEngine *qmlEngine;
    QObject *themeObject;
};

#endif // THEMEMANAGER_H
