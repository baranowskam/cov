#include "Maseczka.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>
#include <stdlib.h> //rand() -> really large int
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

Maseczka::Maseczka(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand()%980;
    setPos(random_number,0);

    //drew the rect
    //setRect(0,0,30,20);
    setPixmap(QPixmap(":/pics/mask.png").scaled(60,40,Qt::KeepAspectRatio));

    //connect
    QTimer * timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(move()));

    timerM->start(150);
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
