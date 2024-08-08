#include "systemtray.h"

#include <QApplication>
#include <QDebug>
#include <QMenu>
#include <QPainter>
#include <QPainterPath>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickWidget>
#include <QWidgetAction>

#include <src/core/coloroptionenum.h>

SystemTray::SystemTray(QQmlEngine *engine, QWidget *parent)
    : QWidget(parent)
    , trayIcon(new QSystemTrayIcon(this))
    , trayIconMenu(new QMenu(this))
    , qmlEngine(engine)
{
    themeManager = new ThemeManager(qmlEngine, this);
    setupTrayIcon();
}

SystemTray::~SystemTray() {}

void SystemTray::setupTrayIcon()
{
    addMenuAction("Configure Connection", "qrc:/resources/icons/settings-bolt.svg");
    trayIconMenu->addSeparator();
    addMenuAction("Exit", "qrc:/resources/icons/power.svg", ColorOption::Red, SLOT(quitApp()));

    trayIcon->setIcon(QIcon(":/resources/logo.png"));

    setupTrayStyles();

    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}

void SystemTray::setupTrayStyles()
{
    trayIconMenu->setAttribute(Qt::WA_TranslucentBackground);
    trayIconMenu->setWindowFlag(Qt::NoDropShadowWindowHint);

    QColor backgroundColor = themeManager->getColor("dark6");
    QColor borderColor = themeManager->getColor("dark4");
    int padding = themeManager->getIntProperty("spacingXXS");
    int borderRadius = themeManager->getIntProperty("radiusSM");

    QString stylesheet = QString("QMenu { "
                                 "    background-color: %1;"
                                 "    border: 1px solid %2;"
                                 "    border-radius: %3px;"
                                 "    padding: %4px;"
                                 "}"
                                 "QMenu::item {"
                                 "    background-color: %1;"
                                 "    border-radius: %3px;"
                                 "}"
                                 "QMenu::separator {"
                                 "    background-color: %2;"
                                 "    height: 1px;"
                                 "    margin: %4px 0px;"
                                 "}")
                             .arg(
                                 backgroundColor.name(QColor::HexArgb),
                                 borderColor.name(QColor::HexArgb),
                                 QString::number(borderRadius),
                                 QString::number(padding));
    trayIconMenu->setStyleSheet(stylesheet);
}

void SystemTray::addMenuAction(
    QString buttonText,
    QString qrcIconSource,
    ColorOption::ColorOptionEnum color,
    const char *clickedSlot)
{
    QQuickWidget *view = new QQuickWidget;
    view->setSource(QUrl("qrc:/qml/Components/MenuItem.qml"));
    view->setMinimumSize(200, 32);

    view->setCursor(Qt::PointingHandCursor);
    view->setResizeMode(QQuickWidget::SizeRootObjectToView);

    QWidgetAction *widgetAction = new QWidgetAction(trayIconMenu);
    widgetAction->setDefaultWidget(view);
    trayIconMenu->addAction(widgetAction);

    QQuickItem *rootObject = view->rootObject();
    if (rootObject) {
        rootObject->setProperty("buttonText", buttonText);
        rootObject->setProperty("iconSource", qrcIconSource);
        rootObject->setProperty("colorOption", color);

        if (clickedSlot) {
            connect(rootObject, SIGNAL(onClick()), this, clickedSlot);
        }
    }
}

void SystemTray::quitApp()
{
    qApp->quit();
}
