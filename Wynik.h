#ifndef WYNIK_H
#define WYNIK_H

#include <QGraphicsTextItem>

class Wynik: public QGraphicsTextItem{
public:
    Wynik(QGraphicsItem * parent=0);
    void increase(int pkt); //dodawanie punktacji
    int getScore();
    int wynik;
};

#endif // WYNIK_H
