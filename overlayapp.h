#ifndef OVERLAYAPP_H
#define OVERLAYAPP_H

#include <QWidget>

class OverlayApp : public QWidget
{
    Q_OBJECT

public:
    OverlayApp(QWidget *parent = nullptr);
    ~OverlayApp();
};
#endif // OVERLAYAPP_H
