#ifndef COLOROPTIONENUM_H
#define COLOROPTIONENUM_H

#include <QObject>

class ColorOption : public QObject
{
    Q_OBJECT

public:
    explicit ColorOption(QObject *parent = nullptr)
        : QObject(parent)
    {}

    enum ColorOptionEnum { Default, Red };
    Q_ENUM(ColorOptionEnum)
};

#endif // COLOROPTIONENUM_H
