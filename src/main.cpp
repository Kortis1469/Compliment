#include <QApplication>
#include "colorIndicator.h"
#include "circle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    uint16_t
        width = 1080,
        height = 720;
    QWidget *mainW = new QWidget();
    mainW->resize(width, height);

    uint16_t widthFC = width/2;
    uint16_t heightFC = height/2;
    Circle *c = new Circle(mainW, widthFC, heightFC, 250);
    ColorIndicator  *d = new ColorIndicator(mainW,100,100,10,8);
    d->alignToRadius(c->getXCenter(),c->getYCenter(),c->getRadius());

    mainW->show();
    return a.exec();
}

/*
Сборка cmake ->
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.10.1/mingw_64" -DCMAKE_C_COMPILER="C:/Qt/Tools/mingw1310_64/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/Qt/Tools/mingw1310_64/bin/g++.exe" .. 

Запуск тестов ->
ctest --test-dir build --output-on-failure
*/