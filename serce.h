#ifndef SERCE_H
#define SERCE_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Serce: public QObject, public QGraphicsPixmapItem
{
public:
  Serce();
};

#endif // SERCE_H
