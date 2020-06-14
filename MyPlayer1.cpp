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

/*!
 Funkcja, dzięki której na ekranie gry tworzą sie przedmioty,
 zarówno te pozytywne (maseczka, makaron, papier) jak i negatywne (wirus, policjant).
 */
void MyPlayer1::spawn()
{
    Wirus * wirus = new Wirus();
    scene() -> addItem(wirus);

    Maseczka * maseczka = new Maseczka();
    scene()-> addItem(maseczka);

    Makaron * makaron  = new Makaron();
    scene()-> addItem(makaron);

    Papier * papier = new Papier();
    scene()-> addItem(papier);

    Policjant * policjant = new Policjant();
    scene()-> addItem(policjant);

}
