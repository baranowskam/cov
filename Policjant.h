#ifndef POLICJANT_H
#define POLICJANT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Policjant: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Policjant();
public slots:
    void move();
    void move2();
private:
    int mozliwosc=11;
};
#endif // POLICJANT_H
