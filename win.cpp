#include "win.h"
#include "ui_win.h"
#include "start.h"
#include "ui_start.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QKeyEvent>
#include <QDesktopWidget>

QMediaPlayer * soundWIN = new QMediaPlayer();
Start * startNowy2;

Win::Win(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Win)
{
  ui->setupUi(this);

  recW=QApplication::desktop()->screenGeometry();
  wysW=recW.height();
  szerW=recW.width();
  ui->centralwidget->setFixedSize(szerW,wysW);
  ui->label->move(szerW/2-ui->label->width()/2,wysW/3);
  ui->pushButton->move(szerW/2-ui->pushButton->width()-20,wysW*7/12);
  ui->pushButton_2->move(szerW/2+20,wysW*7/12);

  soundWIN->setMedia(QUrl("qrc:/music/FINAL/WIN.mp3"));
  soundWIN->setPosition(0);
  soundWIN->play();
}

Win::~Win()
{
  delete ui;
}

void Win::on_pushButton_clicked()
{
  hide();
  startNowy2 = new Start(this);
  startNowy2 -> showFullScreen();
}

void Win::on_pushButton_2_clicked()
{
  exit(0);
}

void Win::keyPressEvent(QKeyEvent *event)
{
  if(event->key()==Qt::Key_Escape)
    {
      exit(0);
    }
}
