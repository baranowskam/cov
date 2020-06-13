#include "serce.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include "Gra.h"

extern Gra * gra;

Serce::Serce(): QObject(), QGraphicsPixmapItem()
{
    //drew the rect
    setPixmap(QPixmap(":/pics/heart.png").scaled(40,80,Qt::KeepAspectRatio));
}
