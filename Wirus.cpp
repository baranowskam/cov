#include "Wirus.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QDebug>
#include <stdlib.h>//rand() -> really large int
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

Wirus::Wirus(): QObject(), QGraphicsPixmapItem()
{
    //set random position
    int random_number = rand()%970;
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
