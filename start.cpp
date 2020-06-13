#include "start.h"
#include "ui_start.h"
#include "Gra.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QDesktopWidget>

Gra * gra;

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);

    recS=QApplication::desktop()->screenGeometry();
    wysS=recS.height();
    szerS=recS.width();

    //ui->radioButton_1->

    ui->centralwidget->setFixedSize(szerS,wysS);
    ui->label->move(szerS/2-ui->label->width()/2,wysS/2-ui->label->height());
    ui->play->move(szerS/2-ui->play->width()-20,wysS/2);
    ui->play_2->move(szerS/2+20,wysS/2);
    ui->klawisz->move(szerS/2-ui->klawisz->width()/2,wysS/4-ui->klawisz->height());
    ui->label_1->move(szerS/2-ui->label_1->width()-20,wysS/2-ui->label_1->height());
    ui->label_2->move(szerS/2+20,wysS/2-ui->label_2->height());
    ui->radioButton_1->move(szerS/2-ui->label_1->width()/2-30,wysS/2);
    ui->radioButton_2->move(szerS/2+ui->label_2->width()/2,wysS/2);
    ui->asdw->move(szerS/2-ui->asdw->width()-10,wysS*2/3);
    ui->strzalki->move(szerS/2+10,wysS*2/3);
    ui->cofnij->move(szerS/2-ui->cofnij->width()/2,wysS*2/3+ui->asdw->height()*3/2);

    ui->label_1->hide();
    ui->radioButton_1->hide();
    ui->label_2->hide();
    ui->radioButton_2->hide();
    ui->asdw->hide();
    ui->strzalki->hide();
    ui->klawisz->hide();
    ui->cofnij->hide();

    // play background music
    playlistS->addMedia(QUrl("qrc:/music/FINAL/start.mp3"));
    playlistS->setPlaybackMode(QMediaPlaylist::Loop);
    musicS->setPlaylist(playlistS);
    musicS->setPosition(0);
    musicS->play();
}

Start::~Start()
{
    delete ui;
}

void Start::on_play_clicked()
{
  qDebug() << "test 0";
    hide();
    girl = 1;
    gra = new Gra(this);
    gra->showFullScreen();
    musicS->stop();
    gra -> p1 = ":/pics/babeczka2.png";
    gra -> p2 = ":/pics/facet.png";
    gra -> player1 -> setPixmap(QPixmap(gra->p1).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
    gra -> player2 -> setPixmap(QPixmap(gra->p2).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
}

void Start::on_play_2_clicked()
{
  // wybor gracza/klawiszy
    ui->label->hide();
    ui->play->hide();
    ui->play_2->hide();
    ui->asdw->show();
    ui->strzalki->show();
    ui->klawisz->show();
    ui->cofnij->show();
    ui->label_1->show();
    ui->radioButton_1->show();
    ui->label_2->show();
    ui->radioButton_2->show();
    ui->label_1->setPixmap(QPixmap(":/pics/babeczka2.png").scaled(40,100,Qt::KeepAspectRatio));
    ui->label_2->setPixmap(QPixmap(":/pics/facet.png").scaled(40,100,Qt::KeepAspectRatio));
}

void Start::on_asdw_clicked()
{
  hide();

  gra = new Gra(this);
  gra->showFullScreen();
  musicS->stop();
  if (ui->radioButton_1->isChecked())
    {
      gra -> p2 = ":/pics/facet.png";
      gra -> p1 = ":/pics/babeczka2.png";
    }
  else if (ui->radioButton_2->isChecked())
    {
      gra -> p1 = ":/pics/facet.png";
      gra -> p2 = ":/pics/babeczka2.png";
    }
  gra -> player1 -> setPixmap(QPixmap(gra->p1).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
  gra -> player2 -> setPixmap(QPixmap(gra->p2).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
  gra->player2->hide();
  gra->player1->moveBy(30,0);
}

void Start::on_strzalki_clicked()
{
  hide();
  gra = new Gra(this);
  gra->showFullScreen();
  musicS->stop();
  if (ui->radioButton_1->isChecked())
    {
      gra -> p1 = ":/pics/facet.png";
      gra -> p2 = ":/pics/babeczka2.png";
    }
  else if (ui->radioButton_2->isChecked())
    {
      gra -> p2 = ":/pics/facet.png";
      gra -> p1 = ":/pics/babeczka2.png";
    }
  gra -> player1 -> setPixmap(QPixmap(gra->p1).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
  gra -> player2 -> setPixmap(QPixmap(gra->p2).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
  gra->player1->hide();
  gra->player2->moveBy(-30,0);
}

void Start::on_cofnij_clicked()
{
  ui->label->show();
  ui->play->show();
  ui->play_2->show();

  ui->asdw->hide();
  ui->strzalki->hide();
  ui->klawisz->hide();
  ui->cofnij->hide();
}

void Start::keyPressEvent(QKeyEvent *event)
{
  if(event->key()==Qt::Key_Escape)
    {
      exit(0);
    }
}

void Start::on_actionMultiplayer_triggered()
{
    ui->play->clicked();
}

void Start::on_actionASDW_triggered()
{
    ui->asdw->clicked();
}

void Start::on_action_triggered()
{
    ui->strzalki->clicked();
}

void Start::on_actionZako_cz_triggered()
{
    exit(0);
}
