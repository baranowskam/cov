#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "MyPlayer1.h"
#include "Wynik.h"
#include "Zycie.h"
//#include "Zycie2.h"

class Gra:public QGraphicsView
{
public:
    Gra(QWidget *parent=0);

    QGraphicsScene *scene;
    MyPlayer1 *player1;
    MyPlayer1 *player2;
    Wynik *wynik;
    Zycie *zycie;
    //Zycie2 *zycie2;
private:
    void keyPressEvent(QKeyEvent*event);
};

#endif // GRA_H
