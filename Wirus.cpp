#include "Wirus.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QDebug>
#include <stdlib.h>
#include <QMediaPlayer>
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

QMediaPlayer * soundW = new QMediaPlayer();

/*!
 Określenie pozycji (losowej), na której utworzy się obiekt wirus.
 Zakres, na jakim może utworzyć się obiekt, to szerokość ekranu gry.
 Następnie tworzony jest obiekt. Wirus nie może powstać poza
 ekranem gry. Dodatkowo dzięki funkcji 'QTimer' możliwe jest określenie
 interwałów w jakich będzie tworzył się nasz obiekt.
 */
Wirus::Wirus(): QObject(), QGraphicsPixmapItem()
{

    int random_number = rand()%(gra->szer);
    setPos(random_number,0);

    setPixmap(QPixmap(":/pics/virus2.png").scaled(40,40,Qt::KeepAspectRatio));

    QTimer * timerW = new QTimer();
    connect(timerW,SIGNAL(timeout()),this,SLOT(move()));

    timerW->start(gra->szybkosc+10);
}

/*!
 Funkcja, dzięki której obiekt wirus porusza się po ekranie gry (spadanie).
 Funkcja collidingItems() pozwala na 'wpadnięcie' przez gracza na obiekt, kolizja z nim
 powoduje utratę 1 życia. Złapanie wirusa sygnalizowane jest dźwiękiem.
 Jeśli graczowi uda się ominąć wirusa i przedmiot dotrze do dolnej krawędzi ekranu,
 to po dotknięciu jej zniknie w celu uniknięcia zapychania pamięci komputera
 (przedmiot zostanie usunięty).
*/
void Wirus::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            soundW->setMedia(QUrl("qrc:/music/FINAL/life gone.mp3"));
            if (soundW->state() == QMediaPlayer::PlayingState)
              {
                soundW->setPosition(0);
              }
            else if (soundW->state() == QMediaPlayer::StoppedState)
              {
                soundW->play();
              }
            gra->zycie->decrease(-1);

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()+7+gra->krok);
    if(pos().y() + pixmap().height()<0)
      {
        scene()->removeItem(this);
        delete this;
      }
}
