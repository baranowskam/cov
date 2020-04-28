#include "MyPlayer1.h"
#include "Wirus.h"
#include "Maseczka.h"
#include "Makaron.h"
#include "Wynik.h"
#include "Papier.h"
#include "Policjant.h"
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>

void MyPlayer1::spawn()
{
    //create a virus
    Wirus * wirus = new Wirus();
    scene() -> addItem(wirus);

    //create a maseczka
    Maseczka * maseczka = new Maseczka();
    scene()-> addItem(maseczka);

    //create a makaron
    Makaron * makaron  = new Makaron();
    scene()-> addItem(makaron);

    //create a papier
    Papier * papier = new Papier();
    scene()-> addItem(papier);

    //create a policjant
    Policjant * policjant = new Policjant();
    scene()-> addItem(policjant);

}
