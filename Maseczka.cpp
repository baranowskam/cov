#include "Maseczka.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>
#include <stdlib.h>
#include <QMediaPlayer>
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

QMediaPlayer * soundM = new QMediaPlayer();

/*!
 Określenie pozycji (losowej), na której utworzy się obiekt maseczka.
 Zakres, na jakim może utworzyć się obiekt, to szerokość ekranu gry.
 W następnej kolejności tworzenie obiektu maseczka. Obiekt
 nie może powstać poza ekranem gry. Dodatkowo dzięki funkcji 'QTimer'
 możliwe jest określenie interwałów w jakich będzie tworzył się nasz obiekt.
 */
Maseczka::Maseczka(): QObject(), QGraphicsPixmapItem(){
    int random_number = rand()%(gra->szer);
    setPos(random_number,0);

    int los = rand()%15;
    if (los < 1)
      {
        setPixmap(QPixmap(":/pics/maseczka.png").scaled(60,40,Qt::KeepAspectRatio));

        QTimer * timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(move()));

        timerM->start(150);
      }

}

/*!
 Funkcja, dzięki której obiekt maseczka porusza się po ekranie gry (spadanie).
 Funkcja collidingItems() pozwala na łapanie przez gracza przedmiotu, pochwycenie obiektu maseczka
 pozwala na zdobycie 1 życia. Złapanie przedmiotu sygnalizowane jest dźwiękiem.
 Jeśli gracz nie złapie przedmiotu i przedmiot dotrze do dolnej krawędzi ekranu,
 to po dotknięciu jej zniknie w celu uniknięcia zapychania pamięci komputera
 (przedmiot zostanie usunięty).
*/
void Maseczka::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            gra->zycie->decrease(1);

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

    setPos(x(),y()+6);
    if(pos().y() + pixmap().height()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
