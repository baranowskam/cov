#include "gracz.h"
#include "Gra.h"
#include <QFont>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>

extern Gra * gra;

Gracz::Gracz(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    nick = gra -> nickGracza;
    setPlainText(nick);
    setDefaultTextColor((Qt::red));
    setFont(QFont("Walt Disney Script v4.1",40));
    setPos((gra->szer)/2-nick.length(),0);
}
