#include "Makaron.h"
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

QMediaPlayer * sound = new QMediaPlayer();

/*!
 Określenie pozycji (losowej), na której utworzy się obiekt makaron.
 Zakres, na jakim może utworzyć się obiekt, to szerokość ekranu gry.
 W następnej kolejności tworzenie obiektu makaron. Obiekt
 nie może powstać poza ekranem gry. Dodatkowo dzięki funkcji 'QTimer'
 możliwe jest określenie interwałów w jakich będzie tworzył się nasz obiekt.
*/
Makaron::Makaron(): QObject(), QGraphicsPixmapItem(){
    int random_number = rand()%(gra->szer);
    setPos(random_number,0);

    setPixmap(QPixmap(":/pics/lubella.png").scaled(40,80,Qt::KeepAspectRatio));

    QTimer * timerN = new QTimer();
    connect(timerN,SIGNAL(timeout()),this,SLOT(move()));
    timerN->start(120);
}

/*!
 Funkcja, dzięki której obiekt makaron porusza się po ekranie gry (spadanie).
 Funkcja collidingItems() pozwala na łapanie przez gracza przedmiotu, pochwycenie obiektu makaron
 powoduje zdobycia 1 punktu. Złapanie przedmiotu sygnalizowane jest dźwiękiem.
 Jeśli gracz nie złapie przedmiotu i przedmiot dotrze do dolnej krawędzi ekranu,
 to po dotknięciu jej zniknie w celu uniknięcia zapychania pamięci komputera
 (przedmiot zostanie usunięty).
*/
void Makaron::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            gra->wynik->increase(1);

            sound->setMedia(QUrl("qrc:/music/FINAL/punkt zdobycie.mp3"));
            if (sound->state() == QMediaPlayer::PlayingState)
              {
                sound->setPosition(0);
              }
            else if (sound->state() == QMediaPlayer::StoppedState)
              {
                sound->play();
              }

            scene() -> removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(),y()+10);

    if(pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
