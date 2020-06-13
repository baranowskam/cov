#include "Wirus.h"
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

QMediaPlayer * soundW = new QMediaPlayer();

Wirus::Wirus(): QObject(), QGraphicsPixmapItem()
{
    //set random position
    int random_number = rand()%(gra->szer);
    setPos(random_number,0);

    //drew the ellipse
    //setRect(0,0,10,10);
    setPixmap(QPixmap(":/pics/virus2.png").scaled(40,40,Qt::KeepAspectRatio));

    //connect
    QTimer * timerW = new QTimer();
    connect(timerW,SIGNAL(timeout()),this,SLOT(move()));

    timerW->start(110);
}

void Wirus::move()
{
    //usuwanie
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            // play get_item_sound
            soundW->setMedia(QUrl("qrc:/music/FINAL/life gone.mp3"));
            if (soundW->state() == QMediaPlayer::PlayingState)
              {
                soundW->setPosition(0);
              }
            else if (soundW->state() == QMediaPlayer::StoppedState)
              {
                soundW->play();
              }

            //odejmowanie życia
            gra->zycie->decrease(-1);

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    //move virus down
    setPos(x(),y()+7);
    if(pos().y() + pixmap().height()<0){
    scene()->removeItem(this);
     delete this;
    }
}
