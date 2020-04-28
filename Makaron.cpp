#include "Makaron.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <stdlib.h> //rand() -> really large int
#include <QDebug>
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

Makaron::Makaron(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand()%985;
    setPos(random_number,0);

    //drew the rect
    //setRect(0,0,20,40);
    setPixmap(QPixmap(":/pics/lubella.png").scaled(40,80,Qt::KeepAspectRatio));
    //setTransformOriginPoint(50,50);
    //setRotation(180);

    //connect
    QTimer * timerN = new QTimer();
    connect(timerN,SIGNAL(timeout()),this,SLOT(move()));
    timerN->start(120);
}

void Makaron::move()
{
    //usuwanie
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            //dodawanie punktów
            gra->wynik->increase(1);

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }

    //move makaron down
    setPos(x(),y()+10);
// ///////////////////////////////// czy plus 80? wczesniej bylo rect.height()
    if(pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
