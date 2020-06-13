#include "Maseczka.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>
#include <stdlib.h> //rand() -> really large int
#include <QMediaPlayer>
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

QMediaPlayer * soundM = new QMediaPlayer();

Maseczka::Maseczka(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand()%(gra->szer);
    setPos(random_number,0);

    int los = rand()%15;
    if (los < 1)
      {
        //drew the rect
        //setRect(0,0,30,20);
        setPixmap(QPixmap(":/pics/maseczka.png").scaled(60,40,Qt::KeepAspectRatio));

        //connect
        QTimer * timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(move()));

        timerM->start(150);
      }

}

void Maseczka::move()
{
    //usuwanie
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            //dodawanie życia
            gra->zycie->decrease(1);

            // play get_item_sound
            soundM->setMedia(QUrl("qrc:/music/FINAL/life back.mp3"));
            if (soundM->state() == QMediaPlayer::PlayingState)
              {
                soundM->setPosition(0);
              }
            else if (soundM->state() == QMediaPlayer::StoppedState)
              {
                soundM->play();
              }

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }

    //move maseczka down
    setPos(x(),y()+6);
    if(pos().y() + pixmap().height()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
