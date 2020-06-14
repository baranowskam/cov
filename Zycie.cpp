#include "Zycie.h"
#include "serce.h"
#include "Wynik.h"
#include "gameover.h"
#include "ui_gameover.h"
#include "Gra.h"
#include <QFont>
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

extern Gra * gra;
GameOver * graGO;

/*!
 Ustawienie początkowej ilości życ gracza (lub graczy) na wartość 3.
 */
Zycie::Zycie(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    zycie = 3;
}

/*!
 Funkcja pokazująca ilość żyć jakie pozostały graczowi (lub graczom) w
 trakcie rozgrywki. Grę rozpoczyna się z 3 życiami (3 serca reprezentowane graficznie
 na ekranie). Z każdą utratą życia jedno z serc będzie znikać z ekranu. Gracz (lub gracze)
 nie mogą mieć więcej niż 3 życia. Spadek ilości serc do 0 oznacza porażkę oraz wyświetlenie okna
 GAME OVER.
 */
void Zycie::decrease(int pkt)
{
    zycie=zycie+pkt;
    if (zycie>3)
      zycie=3;

    if (zycie==0)
      {
        gra -> s1 ->hide();
        gra -> s2 ->hide();
        gra -> s3 ->hide();

        QString line1 = gra->nickGracza;
        QString line2 = QString::number(gra->wartoscWyniku);
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
        graGO = new GameOver();
        graGO -> showFullScreen();
      }
    else if (zycie==1)
      {
        gra -> s1 ->show();
        gra -> s2 ->hide();
        gra -> s3 ->hide();
      }
    else if (zycie==2)
      {
        gra -> s1 ->show();
        gra -> s2 ->show();
        gra -> s3 ->hide();
      }
    else if (zycie==3)
      {
        gra -> s1 ->show();
        gra -> s2 ->show();
        gra -> s3 ->show();
      }
}

/*!
 Funkcja zwracające życie (1 punkt życia) dla gracza (lub graczy) w przypadku
 złapania odpowiedniego przedmiotu w trakcie gry.
 */
int Zycie::getHealth()
{
    return zycie;
}
