#include "Wynik.h"
#include "Gra.h"
#include "win.h"
#include "ui_win.h"
#include <QFont>
#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>

extern Gra * gra;
Win * graWIN;

int wygrana = 3;

Wynik::Wynik(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //ustawianie wyniku na 0
    wynik = 0;

    //wypisanie wyniku
    setPlainText(QString::number(wynik));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Walt Disney Script v4.1",25));
    //setFont(QFont("Times",25));

}

void Wynik::increase(int pkt)
{
    wynik=wynik+pkt;

    if (wynik<0)
      wynik=0;

    if (wynik==0)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek0.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<5)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek0_5.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<20)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek1.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<50)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek2.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<80)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek3.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<120)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek4.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<150)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek5.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<200)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek6.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<260)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek7.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<320)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek8.png").scaled(140,140,Qt::KeepAspectRatio));
    else if (wynik<400)
      gra -> stanKoszyka -> setPixmap(QPixmap(":/shop/zakupy/wozek9.png").scaled(140,140,Qt::KeepAspectRatio));

    if (wynik >= wygrana)
          {
            gra -> music -> stop();
            gra -> hide();
            gra -> player1 -> hide();
            gra -> player2 -> hide();
            gra -> close();
            graWIN = new Win();
            graWIN -> showFullScreen();
          }

    setPlainText(QString::number(wynik));
}

int Wynik::getScore()
{
    return wynik;
}
