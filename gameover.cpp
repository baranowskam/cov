#include "gameover.h"
#include "ui_gameover.h"
#include "start.h"
#include "ui_start.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QKeyEvent>
#include <QDesktopWidget>

QMediaPlayer * soundGO = new QMediaPlayer();
Start * startNowy;

/*!
 Utworzenie okna GAME OVER po przegraniu gry, czyli po utracie wszystkich żyć.
 Porażce oraz stworzeniu okna GAME OVER towarzyszy dodatkowo motyw muzyczny. Po przegranej
 możliwe są dwie opcje do wyboru - zagranie ponownie lub też wyjście z gry. Okno można również
 wyłączyć ręcznie za pomocą klawisza Esc.
 */
GameOver::GameOver(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::GameOver)
{
  ui->setupUi(this);

  recGO=QApplication::desktop()->screenGeometry();
  wysGO=recGO.height();
  szerGO=recGO.width();
  ui->centralwidget->setFixedSize(szerGO,wysGO);
  ui->label->setFixedSize(szerGO,wysGO/2);
  ui->pushButton->setFixedSize(120,50);
  ui->pushButton_2->setFixedSize(120,50);
  ui->label->move(0,wysGO*1/10);
  ui->pushButton->move(szerGO/2-ui->pushButton->width()-20,wysGO*7/12);
  ui->pushButton_2->move(szerGO/2+20,wysGO*7/12);

  soundGO->setMedia(QUrl("qrc:/music/FINAL/GO.mp3"));
  soundGO->setPosition(0);
  soundGO->play();
}

GameOver::~GameOver()
{
  delete ui;
}

void GameOver::on_pushButton_clicked()
{
  hide();
  startNowy = new Start(this);
  startNowy->showFullScreen();
}

void GameOver::on_pushButton_2_clicked()
{
    exit(0);
}

void GameOver::keyPressEvent(QKeyEvent *event)
{
  if(event->key()==Qt::Key_Escape)
    {
      exit(0);
    }
}
