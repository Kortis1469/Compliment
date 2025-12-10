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

    Circle *c = new Circle(mainW, width, height);
    ColorIndicator  *d = new ColorIndicator(mainW);

    mainW->show();
    return a.exec();
}

/*
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.10.1/mingw_64" -DCMAKE_C_COMPILER="C:/Qt/Tools/mingw1310_64/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/Qt/Tools/mingw1310_64/bin/g++.exe" ..
*/