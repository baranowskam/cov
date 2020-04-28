#ifndef PAPIER_H
#define PAPIER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Papier: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Papier();
public slots:
    void move();
};
#endif // PAPIER_H

