#ifndef MASECZKA_H
#define MASECZKA_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Maseczka: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Maseczka();
public slots:
    void move();
private:
    int mozliwosc=15;
};
#endif // MASECZKA_H
