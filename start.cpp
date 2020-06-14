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
#include <QStackedWidget>

Gra * gra;
/*!
 Utworzenie okna startowego, w którym wybierany jest tryb gry - single lub multiplayer.
 Istnieje też opcja otworzenia instrukcji.
 Wybór sterowania jest możliwy tylko w przypadku gry single player.
 W trybie dla dwóch osób Gracz 1 steruje strzałkami, natomiast
 Gracz 2 klawiszami WSAD.
 */
Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);

    recS=QApplication::desktop()->screenGeometry();
    wysS=recS.height();
    szerS=recS.width();

    ui->centralwidget->setFixedSize(szerS,wysS);
    ui->label->setFixedSize(szerS,wysS/2);
    ui->asdw->setFixedSize(120,50);
    ui->strzalki->setFixedSize(120,50);
    ui->play->setFixedSize(120,50);
    ui->play_2->setFixedSize(120,50);
    ui->cofnij->setFixedSize(120,20);
    ui->nick->setFixedSize(ui->label_nick->width(),ui->label_nick->height());
    ui->nick->setFont(QFont("Times",ui->nick->height()*5/9));

    ui->horizontalLayoutWidget->move(10,5);
    ui->label->move(0,wysS/8);
    ui->label_nick->move(szerS/2-ui->label_nick->width()-20,wysS*2/3);
    ui->nick->move(szerS/2+20,wysS*2/3);
    ui->play->move(szerS/2+20,wysS*3/4);
    ui->play_2->move(szerS/2-ui->play->width()-20,wysS*3/4);
    ui->klawisz->move(szerS/2-ui->klawisz->width()/2,wysS/4-ui->klawisz->height());
    ui->label_1->move(szerS/2-ui->label_1->width()-20,wysS/2-ui->label_1->height());
    ui->label_2->move(szerS/2+20,wysS/2-ui->label_2->height());
    ui->radioButton_1->move(szerS/2-ui->label_1->width()/2-30,wysS/2);
    ui->radioButton_2->move(szerS/2+ui->label_2->width()/2,wysS/2);
//    ui->radioButton_3->move(szerS/2-ui->label_1->width()/3-10,wysS/3);
//    ui->radioButton_4->move(szerS/2+ui->label_2->width()/3,wysS/3);
//    ui->radioButton->move(szerS/2+ui->label_2->width()/3,wysS/3);
    ui->asdw->move(szerS/2-ui->asdw->width()-20,wysS*2/3);
    ui->strzalki->move(szerS/2+20,wysS*2/3);
    ui->cofnij->move(szerS/2-ui->cofnij->width()/2,wysS*2/3+ui->asdw->height()*3/2);
    ui->pushButton->move(szerS-ui->pushButton->width(),0);

    ui->label_1->hide();
    ui->radioButton_1->hide();
    ui->label_2->hide();
    ui->radioButton_2->hide();
    ui->asdw->hide();
    ui->strzalki->hide();
    ui->klawisz->hide();
    ui->cofnij->hide();
    ui->label_instrukcja->hide();
    ui->graphicsView_instrukcja->hide();
    ui->label_wyniki->hide();
    ui->pushButton->hide();

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

/*!
 Okno tworzone w przypadku wybrania opcji multiplayer.
 */
void Start::on_play_clicked()
{
    if (ui->radioButton->isChecked()) p=3;
    else if (ui->radioButton_4->isChecked()) p=1;
    else p=2;
    hide();
    gra = new Gra(this);
    gra->showFullScreen();
    musicS->stop();
    gra -> p1 = ":/pics/babeczka2.png";
    gra -> p2 = ":/pics/facet.png";
    gra -> player1 -> setPixmap(QPixmap(gra->p1).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
    gra -> player2 -> setPixmap(QPixmap(gra->p2).scaled(gra->w,gra->h,Qt::KeepAspectRatio));
qDebug() << "test 20";
    if (ui->nick->text().length()>0)
      gra -> nickGracza = ui->nick->text();
    else
      gra -> nickGracza = "Gracz"+QString::number(rand());
    gra -> gracz = new Gracz();
    gra -> scene -> addItem(gra->gracz);
    gra -> poziom = p;
    gra->szybkoscStartowa = 105;
    gra->szybkosc=gra->szybkoscStartowa;
}

/*!
 Wyświetlenie wyboru sterowanie (strzałki lub też WSAD) oraz grafiki postaci.
 */
void Start::on_play_2_clicked()
{
    if (ui->radioButton->isChecked()) p=3;
    else if (ui->radioButton_4->isChecked()) p=1;
    else p=2;
  // wybor gracza/klawiszy
    ui->radioButton_3->hide();
    ui->radioButton_4->hide();
    ui->radioButton-> hide();
    ui->label->hide();
    ui->play->hide();
    ui->play_2->hide();
    ui->label_nick->hide();
    ui->nick->hide();
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

/*!
 Utworzenie nowego okna oraz rozpoczęcie gry w przypadku wybrania
 trybu single player oraz sterowania za pomocą klawiszy WSAD.
 */
void Start::on_asdw_clicked()
{
  hide();

  gra = new Gra(this);
  gra -> poziom = p;
  gra->szybkoscStartowa = 150;
  gra->szybkosc=gra->szybkoscStartowa;
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
  if (ui->nick->text().length()>0)
    gra -> nickGracza = ui->nick->text();
  else
    gra -> nickGracza = "Gracz"+QString::number(rand());
  gra -> gracz = new Gracz();
  gra -> scene -> addItem(gra->gracz);
}

/*!
 Utworzenie nowego okna oraz rozpoczęcie gry w przypadku wybrania
 trybu single player oraz sterowania za pomocą strzałek.
 */
void Start::on_strzalki_clicked()
{
  hide();
  gra = new Gra(this);
  gra -> poziom = p;
  gra->szybkoscStartowa = 150;
  gra->szybkosc=gra->szybkoscStartowa;
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
  if (ui->nick->text().length()>0)
    gra -> nickGracza = ui->nick->text();
  else
    gra -> nickGracza = "Gracz"+QString::number(rand());
  gra -> gracz = new Gracz();
  gra -> scene -> addItem(gra->gracz);
}

void Start::on_cofnij_clicked()
{
  ui->label->show();
  ui->play->show();
  ui->play_2->show();
  ui->label_nick->show();
  ui->nick->show();

  ui->label_1->hide();
  ui->radioButton_1->hide();
  ui->label_2->hide();
  ui->radioButton_2->hide();
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

void Start::on_actionInstrukcja_2_triggered()
{
  ui->pushButton->show();
  ui->graphicsView_instrukcja->show();
  ui->graphicsView_instrukcja->setFixedSize(szerS,wysS);
  ui->label_instrukcja->show();
  ui->label_instrukcja->setFixedSize(szerS,wysS);
}

void Start::on_pushButton_clicked()
{
  ui->pushButton->hide();
  ui->graphicsView_instrukcja->hide();
  ui->label_wyniki->hide();
  ui->label_instrukcja->hide();
}

void Start::on_actionWyniki_triggered()
{
  ui->pushButton->show();
  ui->graphicsView_instrukcja->show();
  ui->graphicsView_instrukcja->setFixedSize(szerS,wysS);
  ui->label_wyniki->show();
  ui->label_wyniki->setFixedSize(szerS,wysS);
  ui->label_wyniki->move(100,50);


  QFile file(":/wyniki/wyniki.txt");
  if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      QTextStream in(&file);
      while(!in.atEnd())
        {
              QString nick_line = in.readLine();
              QString score_line = in.readLine();
              ui->label_wyniki->setText(ui->label_wyniki->text()+"\n"+nick_line+"   "+score_line);
        }
      file.close();
    }
}
