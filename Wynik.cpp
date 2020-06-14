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
#include <QFile>
#include <QDir>

extern Gra * gra;
Win * graWIN;

/*!
 Ustawienie wyniku, jaki potrzebny jest do wygrania gry.
 */
int wygrana = 1;

/*!
 Ustawienie wyniku początkowego na 0, wypisanie wyniku na ekranie,
 określenie koloru oraz czcionki tekstu.
 */
Wynik::Wynik(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    wynik = 0;
    setPlainText(QString::number(wynik));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Walt Disney Script v4.1",25));
}

/*!
 Funkcja, która graficznie reprezentuje ilość zdobytych punktów.
 W zależności od tego, ile punktów udało się zdobyć graczowi (lub graczom)
 koszyk znajdujący się na ekranie będzie coraz bardziej się zapełniał. Określone
 zostały przedziały punktowe, w jakich koszyk przyjmuje poszczególne statusy
 (bardziej lub mniej zapełniony). Gracz nie może mieć mniej niż 0 punktów.
 Zdobycie określonej liczby punktów spowoduje wygranie gry i wyświetlenie okna WIN.
 */
void Wynik::increase(int pkt)
{
    wynik=wynik+pkt;
    gra->wartoscWyniku=wynik;
    if (wynik > wygrana)
      gra->wartoscWyniku=wygrana;

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
        QString line1 = gra->nickGracza;
        QString line2 = QString::number(wynik);
        QFile fileN(gra->sciezka);
        if (fileN.exists())
          qDebug() << "Istnieje";
        else
          qDebug() << "Nie istnieje";
        if(fileN.open(QIODevice::ReadWrite | QIODevice::Text))
          {
            QTextStream text(&fileN);
            text.readAll();
            text << endl << line1 << endl << line2;
            fileN.flush();
            fileN.close();
          }
        else
          qDebug() << "cos jest nie tak :(";
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
