#include "overlayapp.h"

#include <QApplication>
#include <QMenu>
#include <QQmlComponent>
#include <QQmlEngine>

OverlayApp::OverlayApp(QQmlEngine *engine, QWidget *parent)
    : QWidget(parent), trayIcon(new QSystemTrayIcon(this)), trayIconMenu(new QMenu(this)), qmlEngine(engine)
{
    themeManager = new ThemeManager(qmlEngine, this);
    setupTrayIcon();
}

OverlayApp::~OverlayApp() {}

void OverlayApp::setupTrayIcon()
{
    exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

    trayIcon->setIcon(QIcon(":/resources/logo.png"));
    trayIconMenu->addAction(exitAction);

    QColor backgroundColor = themeManager->getColor("primaryBlue");
    trayIconMenu->setStyleSheet(QString("QMenu { background-color: %1; }").arg(backgroundColor.name(QColor::HexArgb)));

    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}
