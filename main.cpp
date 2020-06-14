#include <QApplication>
#include "Gra.h"
#include "start.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Start s;
    s.showFullScreen();
    s.setWindowTitle("Nie złap koronawirusa!");

    return a.exec();
}
