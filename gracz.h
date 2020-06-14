#ifndef GRACZ_H
#define GRACZ_H

#include <QGraphicsTextItem>

class Gracz: public QGraphicsTextItem
{
public:
  Gracz(QGraphicsItem * parent=0);
  QString nick;
};

#endif // GRACZ_H
