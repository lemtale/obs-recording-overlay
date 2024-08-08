#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <src/core/coloroptionenum.h>
#include <QQmlEngine>
#include <QSystemTrayIcon>
#include <QWidget>

#include <src/utilities/thememanager.h>

class SystemTray : public QWidget
{
    Q_OBJECT

public:
    SystemTray(QQmlEngine *engine, QWidget *parent = nullptr);
    ~SystemTray();

public slots:
    void quitApp();

private:
    void setupTrayIcon();
    void setupTrayStyles();
    void addMenuAction(
        QString buttonText = "Button",
        QString qrcIconSource = "",
        ColorOption::ColorOptionEnum color = ColorOption::Default,
        const char *clickedSlot = nullptr);

    QQmlEngine *qmlEngine;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *exitAction;
    ThemeManager *themeManager;
};
#endif // SYSTEMTRAY_H
