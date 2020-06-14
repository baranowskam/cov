#include "Policjant.h"
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

QMediaPlayer * soundP = new QMediaPlayer();

/*!
 Określenie pozycji (losowej), na której utworzy się obiekt policjant.
 Zakres, na jakim może utworzyć się obiekt, to wysokość ekranu gry, pomijane
 jest dolne 100 pikseli długości stworzonego okna. Dalej dokonywane jest
 utworzenie obiektu policjant. Obiekt nie może powstać poza
 ekranem gry. Dodatkowo dzięki funkcji 'QTimer' możliwe jest określenie
 interwałów w jakich będzie tworzył się nasz obiekt. Policjant może tworzyć się
 po dwóch skrajnych stronach okna gry, z lewej lub z prawej. W zależności od miejsca
 spawnu poruszać się będzie w prawo lub w lewo. Obiekt policjant ma jeden model graficzny,
 który w zależności od miejsca spawnu jest odbiciem lustrzanym oryginalnego obrazka.
 */
Policjant::Policjant(): QObject(), QGraphicsPixmapItem()
{
    if (gra->poziom==3) // poziom hard
    {
        mozliwosc=5;
    }
    else if (gra->poziom==1) // poziom easy
    {
        mozliwosc=100;
    }
    int los = rand()%mozliwosc;
    if (los < 1)
      {
        int random_number = rand()%(gra->wys-100);

        QTimer * timerPO = new QTimer();

        int kierunek = rand()%2;
        if (kierunek==0)
          {
            setPixmap(QPixmap(":/pics/policjant2.png").scaled(100,100,Qt::KeepAspectRatio).transformed(QTransform().scale(-1, 1)));
            setPos(0,random_number);
            connect(timerPO,SIGNAL(timeout()),this,SLOT(move()));
          }
        else
          {
            setPixmap(QPixmap(":/pics/policjant2.png").scaled(100,100,Qt::KeepAspectRatio));
            setPos(gra->szer,random_number);
            connect(timerPO,SIGNAL(timeout()),this,SLOT(move2()));
          }
        timerPO->start(gra->szybkosc+5);
      }
}

/*!
Funkcja, dzięki której obiekt policjant porusza się po ekranie gry (w lewo).
Funkcja collidingItems() pozwala na 'wpadnięcie' przez gracza na obiekt, kolizja z nim
powoduje utratę 2 punktów. Spotkanie z policjantem sygnalizowane jest dźwiękiem.
Jeśli graczowi uda się ominąć stróża prawa i przedmiot dotrze do prawej krawędzi ekranu,
to po dotknięciu jej zniknie w celu uniknięcia zapychania pamięci komputera
(przedmiot zostanie usunięty).
*/
void Policjant::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            gra->wynik->increase(-2);

            soundP->setMedia(QUrl("qrc:/music/FINAL/punkty strata.mp3"));
            if (soundP->state() == QMediaPlayer::PlayingState)
              {
                soundP->setPosition(0);
              }
            else if (soundP->state() == QMediaPlayer::StoppedState)
              {
                soundP->play();
              }
            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x()+4,y());
    if(pos().x() + pixmap().width()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

/*!
Funkcja, dzięki której obiekt policjant porusza się po ekranie gry (w prawo).
Funkcja collidingItems() pozwala na 'wpadnięcie' przez gracza na obiekt, kolizja z nim
powoduje utratę 2 punktów. Spotkanie z policjantem sygnalizowane jest dźwiękiem.
Jeśli graczowi uda się ominąć stróża prawa i przedmiot dotrze do lewej krawędzi ekranu,
to po dotknięciu jej zniknie w celu uniknięcia zapychania pamięci komputera
(przedmiot zostanie usunięty).
*/
void Policjant::move2()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(MyPlayer1))
        {
            gra->wynik->increase(-2);

            soundP->setMedia(QUrl("qrc:/music/FINAL/punkty strata.mp3"));
            if (soundP->state() == QMediaPlayer::PlayingState)
              {
                soundP->setPosition(0);
              }
            else if (soundP->state() == QMediaPlayer::StoppedState)
              {
                soundP->play();
              }
            scene() -> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x()-4,y());
    if(pos().x() - pixmap().width()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
