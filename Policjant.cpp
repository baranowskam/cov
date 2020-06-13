#include "Policjant.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QDebug>
#include <stdlib.h>//rand() -> really large int
#include <QMediaPlayer>
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

QMediaPlayer * soundP = new QMediaPlayer();

Policjant::Policjant(): QObject(), QGraphicsPixmapItem()
{
    int los = rand()%6;
    if (los < 1)
      {
        //set random position
        int random_number = rand()%(gra->wys-100);

        //connect
        QTimer * timerPO = new QTimer();

        int kierunek = rand()%2;
        if (kierunek==0)
          {
            setPixmap(QPixmap(":/pics/policjant2.png").scaled(100,100,Qt::KeepAspectRatio).transformed(QTransform().scale(-1, 1)));
            setPos(0,random_number);
            connect(timerPO,SIGNAL(timeout()),this,SLOT(move()));
          }
        else
          {
            setPixmap(QPixmap(":/pics/policjant2.png").scaled(100,100,Qt::KeepAspectRatio));
            setPos(gra->szer,random_number);
            connect(timerPO,SIGNAL(timeout()),this,SLOT(move2()));
          }

        timerPO->start(50);
      }
}

void Policjant::move()
{
    //usuwanie
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            //dodawanie punktów
            gra->wynik->increase(-2);

            // play get_item_sound
            soundP->setMedia(QUrl("qrc:/music/FINAL/punkty strata.mp3"));
            if (soundP->state() == QMediaPlayer::PlayingState)
              {
                soundP->setPosition(0);
              }
            else if (soundP->state() == QMediaPlayer::StoppedState)
              {
                soundP->play();
              }

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    //move policjant right
    setPos(x()+4,y());
    if(pos().x() + pixmap().width()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Policjant::move2()
{
    //usuwanie
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            //dodawanie punktów
            gra->wynik->increase(-2);

            // play get_item_sound
            soundP->setMedia(QUrl("qrc:/music/FINAL/punkty strata.mp3"));
            if (soundP->state() == QMediaPlayer::PlayingState)
              {
                soundP->setPosition(0);
              }
            else if (soundP->state() == QMediaPlayer::StoppedState)
              {
                soundP->play();
              }

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    //move policjant right
    setPos(x()-4,y());
    if(pos().x() - pixmap().width()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
