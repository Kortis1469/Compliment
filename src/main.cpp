#include <QApplication>
#include "donat.h"
#include "circle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    uint16_t
        width = 1080,
        height = 720;
    QWidget *mainW = new QWidget();
    mainW->resize(width, height);

    Circle *c = new Circle(mainW, width, height);
    Donat  *d = new Donat(mainW);


    mainW->show();
    return a.exec();
}
