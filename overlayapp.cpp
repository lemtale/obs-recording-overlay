#include "overlayapp.h"

#include <QApplication>
#include <QMenu>

OverlayApp::OverlayApp(QWidget *parent)
    : QWidget(parent), trayIcon(new QSystemTrayIcon(this)), trayIconMenu(new QMenu(this))
{
    exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

    trayIcon->setIcon(QIcon(":/images/obs-recording-overlay-logo.png"));
    trayIconMenu->addAction(exitAction);

    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}

OverlayApp::~OverlayApp() {}
