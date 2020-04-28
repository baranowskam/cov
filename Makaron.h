#ifndef MAKARON_H
#define MAKARON_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Makaron: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Makaron();
public slots:
    void move();
};
#endif // MAKARON_H
