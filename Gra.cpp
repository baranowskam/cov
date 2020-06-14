#include "Wynik.h"
#include "Zycie.h"
#include "Gra.h"
#include "Wirus.h"
#include "Papier.h"
#include "Policjant.h"
#include "Maseczka.h"
#include "Makaron.h"
#include "serce.h"
#include "koszyk.h"
#include "start.h"

#include <QDebug>
#include <QGraphicsItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDesktopWidget>
#include <QDir>

// jednak nie dziala ta funkcja sciagajaca sciezke pliku, w kazdym razie niecalkowicie
// ale nie usuwajcie zadnej sciezki, jedynie dodajcie swoja a reszte wykomentujcie
QString sciezka_pliku = "C:/Users/dell/Desktop/COVID-19/wyniki.txt";                      // MARTYNA
//QString sciezka_pliku = "C:/Users/Michalina/Desktop/COVID-19/wyniki.txt";               // MICHALINA

/*!
 Utworzenie głównego okna gry, które będzie zawierało wszystkie elementy - graczy,
 przedmioty pozytywne oraz negatywne, wynik, życie, tło, podkład muzyczny.
 */
Gra::Gra (QWidget *parent)
{
    QString dir = QDir::homePath();
    sciezka = dir + "/COVID-19/wyniki.txt";
    qDebug()<< sciezka;
    sciezka = sciezka_pliku;
    rec=QApplication::desktop()->screenGeometry();
    wys=rec.height();
    szer=rec.width();
    setWindowTitle("NIE ZŁAP KORONAWIRUSA!");
    scene = new QGraphicsScene();
    scene -> setSceneRect(0,0,szer,wys);
    setBackgroundBrush(QBrush(QImage(":/background/tlo/tlo_mapa.png").scaled(szer,wys)));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(szer,wys);
    player1 = new MyPlayer1();
    player1 -> setPixmap(QPixmap(p1).scaled(w,h,Qt::KeepAspectRatio));
    player1->setPos(szer/2-w-10,wys-player1->pixmap().height());
    player2 = new MyPlayer1();
    player2 -> setPixmap(QPixmap(p2).scaled(w,h,Qt::KeepAspectRatio));
    player2->setPos(szer/2+10,wys-player2->pixmap().height());
    stanKoszyka = new Koszyk();
    wynik = new Wynik();
    zycie = new Zycie();
    s1 = new Serce();
    s2 = new Serce();
    s3 = new Serce();

    s1 -> setPos(s1->pixmap().width()*0.5,s1->pixmap().height()*0.5);
    s2 -> setPos(s1->pixmap().width()*2,s1->pixmap().height()*0.5);
    s3 -> setPos(s1->pixmap().width()*3.5,s1->pixmap().height()*0.5);
    stanKoszyka -> setPos(szer-stanKoszyka->pixmap().width(),0);
    wynik -> setPos(szer-stanKoszyka->pixmap().width()/2-20,stanKoszyka->pixmap().height());

    scene -> addItem(player1);
    scene -> addItem(player2);
    scene -> addItem(wynik);
    scene -> addItem(stanKoszyka);
    scene -> addItem(zycie);
    scene -> addItem(s1);
    scene -> addItem(s2);
    scene -> addItem(s3);

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player1,SLOT(spawn()));
    QObject::connect(timer,SIGNAL(timeout()),player2,SLOT(spawn()));
    timer->start(2000);

    setFocusPolicy(Qt::ClickFocus);
    grabKeyboard();

    playlist->addMedia(QUrl("qrc:/music/FINAL/game.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music->setPlaylist(playlist);
    music->setPosition(0);
    music->play();

    show();
}
/*!
 Funkcja, która pozwala na sterowanie graczami. Gracz może poruszać się w
 4 głównych kierunkach świata, czyli na lewo, prawo, w górę lub w dół. Gracz nie
 może poruszać się po skosie.
 */
void Gra::keyPressEvent(QKeyEvent *event)
{
  switch(event->key())
    {
      case Qt::Key_Escape:
        this->close();
        break;

      case Qt::Key_A:
        if (player1->x()>0)
          player1->moveBy(-10,0);
        player1 -> setPixmap(QPixmap(p1).scaled(w,h,Qt::KeepAspectRatio));
        break;

      case Qt::Key_D:
        if (player1->x()+50<szer)
          player1->moveBy(10,0);
        player1 -> setPixmap(QPixmap(p1).scaled(w,h,Qt::KeepAspectRatio).transformed(QTransform().scale(-1, 1)));
        break;

      case Qt::Key_W:
        if (player1->y()>0)
          player1->moveBy(0,-10);
        break;

      case Qt::Key_S:
        if (player1->y()+100<wys)
          player1->moveBy(0,10);
        break;


      case Qt::Key_Left:
        if (player2->x()>0)
          player2->moveBy(-10,0);
        player2 -> setPixmap(QPixmap(p2).scaled(w,h,Qt::KeepAspectRatio));
        break;

      case Qt::Key_Right:
        if (player2->x()+50<szer)
          player2->moveBy(10,0);
        player2 -> setPixmap(QPixmap(p2).scaled(w,h,Qt::KeepAspectRatio).transformed(QTransform().scale(-1, 1)));
        break;

      case Qt::Key_Up:
        if (player2->y()>0)
          player2->moveBy(0,-10);
        break;

      case Qt::Key_Down:
        if (player2->y()+100<wys)
          player2->moveBy(0,10);
        break;
    }
}
