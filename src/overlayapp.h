#ifndef OVERLAYAPP_H
#define OVERLAYAPP_H

#include <QSystemTrayIcon>
#include <QWidget>
#include <QQmlEngine>

#include <src/utilities/thememanager.h>

class OverlayApp : public QWidget
{
    Q_OBJECT

public:
    OverlayApp(QQmlEngine *engine, QWidget *parent = nullptr);
    ~OverlayApp();

private:
    void setupTrayIcon();

    QQmlEngine *qmlEngine;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *exitAction;
    ThemeManager *themeManager;
};
#endif // OVERLAYAPP_H
