#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

namespace Ui {
  class GameOver;
}

class GameOver : public QMainWindow
{
  Q_OBJECT

public:
  explicit GameOver(QWidget *parent = nullptr);
  ~GameOver();

  int wysGO, szerGO;
  QRect recGO;

  void keyPressEvent(QKeyEvent*event);

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::GameOver *ui;
};

#endif // GAMEOVER_H
