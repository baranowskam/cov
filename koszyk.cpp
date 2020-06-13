#include "koszyk.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include "Gra.h"

extern Gra * gra;

Koszyk::Koszyk(): QObject(), QGraphicsPixmapItem()
{
    //utworzenie koszyka - stan pusty
    setPixmap(QPixmap(":/shop/zakupy/wozek0.png").scaled(140,140,Qt::KeepAspectRatio));
}
