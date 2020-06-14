#include "Papier.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QMediaPlayer>
#include "Gra.h"
#include "MyPlayer1.h"

extern Gra * gra;

QMediaPlayer * sound2 = new QMediaPlayer();

/*!
 Określenie pozycji (losowej), na której utworzy się obiekt papier.
 Zakres, na jakim może utworzyć się obiekt, to szerokość ekranu gry.
 W następnej kolejności tworzenie obiektu papier toaletowy. Obiekt
 nie może powstać poza ekranem gry. Dodatkowo dzięki funkcji 'QTimer'
 możliwe jest określenie interwałów w jakich będzie tworzył się nasz obiekt.
 */
Papier::Papier(): QObject(), QGraphicsPixmapItem(){
    int random_number = rand()%(gra->szer);
    setPos(random_number,0);
    int los = rand()%5;
    if (los < 1)
      {
        setPixmap(QPixmap(":/pics/rolka.png").scaled(40,40,Qt::KeepAspectRatio));
        QTimer * timerP = new QTimer();
        connect(timerP,SIGNAL(timeout()),this,SLOT(move()));
        timerP->start(gra->szybkosc+40);
      }
}

/*!
 Funkcja, dzięki której obiekt papier porusza się po ekranie gry (spadanie).
 Funkcja collidingItems() pozwala na łapanie przez gracza przedmiotu, pochwycenie obiektu papier
 powoduje zdobycie 5 punktów. Złapanie przedmiotu sygnalizowane jest dźwiękiem.
 Jeśli gracz nie złapie przedmiotu i przedmiot dotrze do dolnej krawędzi ekranu,
 to po dotknięciu jej zniknie w celu uniknięcia zapychania pamięci komputera
 (przedmiot zostanie usunięty).
*/
void Papier::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            //dodawanie punktów
            gra->wynik->increase(5);

            // play get_item_sound
            sound2->setMedia(QUrl("qrc:/music/FINAL/punkt zdobycie.mp3"));
            if (sound2->state() == QMediaPlayer::PlayingState)
              {
                sound2->setPosition(0);
              }
            else if (sound2->state() == QMediaPlayer::StoppedState)
              {
                sound2->play();
              }
            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()+8);
    if(pos().y() + pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
