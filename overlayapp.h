#ifndef OVERLAYAPP_H
#define OVERLAYAPP_H

#include <QSystemTrayIcon>
#include <QWidget>

class OverlayApp : public QWidget
{
    Q_OBJECT

public:
    OverlayApp(QWidget *parent = nullptr);
    ~OverlayApp();

private:
    void setupTrayIcon();

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *exitAction;
};
#endif // OVERLAYAPP_H
