#ifndef START_H
#define START_H

#include "Gra.h"
#include "MyPlayer1.h"
#include "Wynik.h"
#include "Zycie.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLabel>
#include "Maseczka.h"

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

    QMediaPlaylist * playlistS = new QMediaPlaylist();
    QMediaPlayer * musicS = new QMediaPlayer();

    bool girl;
    QString nickStart;

    int wysS, szerS;
    QRect recS;

    int p;

    void keyPressEvent(QKeyEvent*event);

private slots:
    void on_play_clicked();

    void on_play_2_clicked();

    void on_asdw_clicked();

    void on_strzalki_clicked();

    void on_cofnij_clicked();

    void on_actionMultiplayer_triggered();

    void on_actionASDW_triggered();

    void on_action_triggered();

    void on_actionZako_cz_triggered();

    void on_actionInstrukcja_2_triggered();

    void on_pushButton_clicked();

    void on_actionWyniki_triggered();


private:
    Ui::Start *ui;
};

#endif // START_H
