 #include "Wynik.h"
#include <QFont>

Wynik::Wynik(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //ustawianie wyniku na 0
    wynik = 0;

    //wypisanie wyniku
    setPlainText(QString("Wynik: ") + QString::number(wynik));
    //umiejscowienie wyniku
    setPos(450,0);
    setDefaultTextColor((Qt::blue));
    setFont(QFont("times",13));
}

void Wynik::increase(int pkt)
{
    wynik=wynik+pkt;
    if (wynik<0)
      wynik=0;
    setPlainText(QString("Wynik: ") + QString::number(wynik));
}

int Wynik::getScore()
{
    return wynik;
}
