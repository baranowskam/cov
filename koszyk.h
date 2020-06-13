#ifndef KOSZYK_H
#define KOSZYK_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Koszyk: public QObject, public QGraphicsPixmapItem
{
public:
  Koszyk();
};

#endif // KOSZYK_H
