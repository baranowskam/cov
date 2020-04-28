#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "Wynik.h"
#include "Zycie.h"

class MyPlayer1: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public slots:
    void spawn();
};

#endif // MYPLAYER1_H
