#include "Policjant.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QDebug>
#include <stdlib.h>//rand() -> really large int
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

Policjant::Policjant(): QObject(), QGraphicsPixmapItem()
{
    //set random position
    int random_number = rand()%590;
    setPos(0,random_number);

    //drew the ellipse
    //setRect(0,0,20,20);
    setPixmap(QPixmap(":/pics/police.png").scaled(40,40,Qt::KeepAspectRatio));
    //setRotation(90);

    //connect
    QTimer * timerPO = new QTimer();
    connect(timerPO,SIGNAL(timeout()),this,SLOT(move()));

    timerPO->start(100);
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

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    //move policjant down
    setPos(x()+4,y());
    if(pos().x() + pixmap().width()<0){
        scene()->removeItem(this);
        delete this;
    }
}
