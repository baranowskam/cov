#include "koszyk.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include "Gra.h"

extern Gra * gra;
/*!
  Utworzenie obiektu koszyk (stan pusty), który będzie graficznie reprezentował
  ilość zdobytych przez gracza (lub graczy) punktów.
*/
Koszyk::Koszyk(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/shop/zakupy/wozek0.png").scaled(140,140,Qt::KeepAspectRatio));
}
