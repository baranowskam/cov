#include "Zycie.h"
#include <QFont>

Zycie::Zycie(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //ustawianie zycia na 3
    zycie = 3;
    //wypisanie zycia
    setPlainText(QString("Życie Gracza: ") + QString::number(zycie));
    //umiejscowienie zycia
    setPos(50,0);
    setDefaultTextColor((Qt::red));
    setFont(QFont("times",12));
}

void Zycie::decrease(int pkt)
{
    zycie=zycie+pkt;
    if (zycie<0)
      zycie=0;
    if (zycie>3)
      zycie=3;
    setPlainText(QString("Życie Gracza: ") + QString::number(zycie));
}

int Zycie::getHealth()
{
    return zycie;
}
