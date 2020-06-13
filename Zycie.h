 #ifndef ZYCIE_H
#define ZYCIE_H

#include <QGraphicsTextItem>

class Zycie: public QGraphicsTextItem{
public:
    Zycie(QGraphicsItem * parent=0);
    void decrease(int pkt); //odejmowanie żyćka
    int getHealth();
private:
    int zycie;
};

#endif // ZYCIE_H
