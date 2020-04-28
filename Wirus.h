#ifndef WIRUS_H
#define WIRUS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Wirus: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wirus();
public slots:
    void move();
};
#endif // WIRUS_H
