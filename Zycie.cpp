#include "Zycie.h"
#include "serce.h"
#include "gameover.h"
#include "ui_gameover.h"
#include "Gra.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

extern Gra * gra;
GameOver * graGO;

Zycie::Zycie(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //ustawianie zycia na 3
    zycie = 3;
}

void Zycie::decrease(int pkt)
{
    zycie=zycie+pkt;
    if (zycie>3)
      zycie=3;

    if (zycie==0)
      {
        gra -> s1 ->hide();
        gra -> s2 ->hide();
        gra -> s3 ->hide();
        gra -> music -> stop();
        gra -> hide();
        gra -> player1 -> hide();
        gra -> player2 -> hide();
        gra -> close();
        graGO = new GameOver();
        graGO -> showFullScreen();
      }
    else if (zycie==1)
      {
        gra -> s1 ->show();
        gra -> s2 ->hide();
        gra -> s3 ->hide();
      }
    else if (zycie==2)
      {
        gra -> s1 ->show();
        gra -> s2 ->show();
        gra -> s3 ->hide();
      }
    else if (zycie==3)
      {
        gra -> s1 ->show();
        gra -> s2 ->show();
        gra -> s3 ->show();
      }
}

int Zycie::getHealth()
{
    return zycie;
}
