#ifndef WIN_H
#define WIN_H

#include <QMainWindow>

namespace Ui {
  class Win;
}

class Win : public QMainWindow
{
  Q_OBJECT

public:
  explicit Win(QWidget *parent = nullptr);
  ~Win();

  int wysW, szerW;
  QRect recW;

private:
    void keyPressEvent(QKeyEvent*event);

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::Win *ui;
};

#endif // WIN_H
