#include "serce.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include "Gra.h"

extern Gra * gra;

/*!
  Utworzenie obiektu serce, który będzie graficznie reprezentował
  ilość żyć, które pozostały graczowi (lub graczom) w trakcie gry.
*/
Serce::Serce(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/pics/heart.png").scaled(40,80,Qt::KeepAspectRatio));
}
