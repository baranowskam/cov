#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "MyPlayer1.h"
#include "Wynik.h"
#include "Zycie.h"
#include "start.h"
#include "serce.h"
#include "koszyk.h"
#include "gracz.h"

/*!
 Utworzenie klasy Gra, która zawiera wszystkie elementy, które zawierać
 będzie okno gry, czyli graczy, obiekty pozytywne oraz negatywne,
 wynik, życie, tło oraz podkład muzyczny.
 */
class Gra:public QGraphicsView
{
public:
    Gra(QWidget *parent=0);

    int wys, szer;
    QRect rec;
    QGraphicsScene *scene;
    MyPlayer1 *player1;
    MyPlayer1 *player2;
    int w=50, h=120;
    Wynik *wynik;
    int wartoscWyniku=0;
    Zycie *zycie;
    QTimer *timer;
    Serce *s1, *s2, *s3;
    Koszyk *stanKoszyka;
    Gracz *gracz;
    QMediaPlaylist *playlist = new QMediaPlaylist();
    QMediaPlayer *music = new QMediaPlayer();
    QString nickGracza;
    QString sciezka;
    QString p1 = ":/pics/babeczka2.png";
    QString p2 = ":/pics/facet.png";
    int poziom=2;
    int szybkosc, szybkoscStartowa, krok = 0;

private:
    void keyPressEvent(QKeyEvent*event);
};

#endif // GRA_H
