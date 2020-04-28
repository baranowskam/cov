#include "Wynik.h"
#include "Zycie.h"
//#include "Zycie2.h"
#include "Gra.h"
#include "Wirus.h"
#include "Papier.h"
#include "Policjant.h"
//#include "MyPlayer1.h"
#include "Maseczka.h"
#include "Makaron.h"

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

Gra::Gra (QWidget *parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene -> setSceneRect(0,0,1000,600);
    setBackgroundBrush(QBrush(QImage(":/pics/tlo.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,600);

    //create players
    player1 = new MyPlayer1();
    //player1 -> setRect(0,0,40,100);
    player1 -> setPixmap(QPixmap(":/pics/red.png").scaled(40,100,Qt::KeepAspectRatio));
    player1->setPos(scene->width()/2-60,scene->height()-player1->pixmap().height());
    player2 = new MyPlayer1();
    //player2 -> setRect(0,0,40,100);
    player2 -> setPixmap(QPixmap(":/pics/green.png").scaled(40,100,Qt::KeepAspectRatio));
    player2->setPos(scene->width()/2+10,scene->height()-player2->pixmap().height());

    // create the score/health
    wynik = new Wynik();
    zycie = new Zycie();
    //zycie2 = new Zycie2();

    // add the item to the scene
    scene -> addItem(player1);
    scene -> addItem(player2);
    scene -> addItem(wynik);
    scene -> addItem(zycie);
    //scene -> addItem(zycie2);

    //spawn virus
    QTimer * timerW = new QTimer();
    QObject::connect(timerW,SIGNAL(timeout()),player1,SLOT(spawn()));
    QObject::connect(timerW,SIGNAL(timeout()),player2,SLOT(spawn()));
    timerW->start(320000);

    //spawn maseczka
    QTimer * timerM = new QTimer();
    QObject::connect(timerM,SIGNAL(timeout()),player1,SLOT(spawn()));
    QObject::connect(timerM,SIGNAL(timeout()),player2,SLOT(spawn()));
    timerM->start(19000);

    //spawn makaron
    QTimer * timerN = new QTimer();
    QObject::connect(timerN,SIGNAL(timeout()),player1,SLOT(spawn()));
    QObject::connect(timerN,SIGNAL(timeout()),player2,SLOT(spawn()));
    timerN->start(22000);

    //spawn papier
    QTimer * timerP = new QTimer();
    QObject::connect(timerP,SIGNAL(timeout()),player1,SLOT(spawn()));
    QObject::connect(timerP,SIGNAL(timeout()),player2,SLOT(spawn()));
    timerP->start(16000);

    //spawn policjant
    QTimer * timerPO = new QTimer();
    QObject::connect(timerPO,SIGNAL(timeout()),player1,SLOT(spawn()));
    QObject::connect(timerPO,SIGNAL(timeout()),player2,SLOT(spawn()));
    timerPO->start(35000);

    setFocusPolicy(Qt::ClickFocus);
    grabKeyboard();

    show();
}

void Gra::keyPressEvent(QKeyEvent *event)
{
  switch(event->key())
    {
      case Qt::Key_A:
        if (player1->x()>0)
          player1->moveBy(-10,0);
        break;

      case Qt::Key_D:
        if (player1->x()+50<1000)
          player1->moveBy(10,0);
        break;

      case Qt::Key_W:
        if (player1->y()>0)
          player1->moveBy(0,-10);
        break;

      case Qt::Key_S:
        if (player1->y()+100<600)
          player1->moveBy(0,10);
        break;


      case Qt::Key_Left:
        if (player2->x()>0)
          player2->moveBy(-10,0);
        break;

      case Qt::Key_Right:
        if (player2->x()+50<1000)
          player2->moveBy(10,0);
        break;

      case Qt::Key_Up:
        if (player2->y()>0)
          player2->moveBy(0,-10);
        break;

      case Qt::Key_Down:
        if (player2->y()+100<600)
          player2->moveBy(0,10);
        break;
    }
}

//  void Gra::keyPressEvent(QKeyEvent *event)
//  {
//    if (event->key() == Qt::Key_A)
//      {
//          if (player1->x()>0)
//            player1->moveBy(-10,0);
//      }
//      if (event->key() == Qt::Key_D)
//      {
//          if (player1->x()+50<1000)
//            player1->moveBy(10,0);
//      }
//      if (event->key() == Qt::Key_W)
//      {
//          if (player1->y()>0)
//            player1->moveBy(0,-10);
//      }
//      if (event->key() == Qt::Key_S)
//      {
//          if (player1->y()+100<600)
//          player1->moveBy(0,10);
//      }

//      if (event->key() == Qt::Key_Left)
//        {
//            if (player2->x()>0)
//              player2->moveBy(-10,0);
//        }
//      if (event->key() == Qt::Key_Right)
//        {
//            if (player2->x()+50<1000)
//              player2->moveBy(10,0);
//        }
//      if (event->key() == Qt::Key_Up)
//        {
//            if (player2->y()>0)
//              player2->moveBy(0,-10);
//        }
//      if (event->key() == Qt::Key_Down)
//        {
//            if (player2->y()+100<600)
//            player2->moveBy(0,10);
//        }
//  }
