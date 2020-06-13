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

GameOver::GameOver(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::GameOver)
{
  ui->setupUi(this);

  recGO=QApplication::desktop()->screenGeometry();
  wysGO=recGO.height();
  szerGO=recGO.width();
  ui->centralwidget->setFixedSize(szerGO,wysGO);
  ui->label->move(szerGO/2-ui->label->width()/2,wysGO/3);
  ui->pushButton->move(szerGO/2-ui->pushButton->width()-20,wysGO/2);
  ui->pushButton_2->move(szerGO/2+20,wysGO/2);

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
