#include "Papier.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <stdlib.h> //rand() -> really large int
#include <QDebug>
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

Papier::Papier(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand()%990;
    setPos(random_number,0);

    //drew the rect
    //setRect(0,0,20,20);
    setPixmap(QPixmap(":/pics/rolka.png").scaled(40,40,Qt::KeepAspectRatio));

    //connect
    QTimer * timerP = new QTimer();
    connect(timerP,SIGNAL(timeout()),this,SLOT(move()));

    timerP->start(130);
}

void Papier::move()
{
    //usuwanie
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            //dodawanie punktów
            gra->wynik->increase(5);

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    //move papier down
    setPos(x(),y()+8);
    if(pos().y() + pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
