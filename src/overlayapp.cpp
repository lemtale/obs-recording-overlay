#include "overlayapp.h"

#include <QApplication>
#include <QMenu>

OverlayApp::OverlayApp(QWidget *parent)
    : QWidget(parent), trayIcon(new QSystemTrayIcon(this)), trayIconMenu(new QMenu(this))
{
    setupTrayIcon();
}

OverlayApp::~OverlayApp() {}

void OverlayApp::setupTrayIcon()
{
    exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

    trayIcon->setIcon(QIcon(":/resources/logo.png"));
    trayIconMenu->addAction(exitAction);

    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}
