#include <QApplication>
#include "colorIndicator.h"
#include "circle.h"
#include <QLabel>

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
    
    QLabel *label = new QLabel("Информация", mainW);
    label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ColorIndicator  *d = new ColorIndicator(mainW,10,8,c,label);
    
    mainW->show();
    return a.exec();
}

/*
Сборка cmake ->
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.10.1/mingw_64" -DCMAKE_C_COMPILER="C:/Qt/Tools/mingw1310_64/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/Qt/Tools/mingw1310_64/bin/g++.exe" .. 

Запуск тестов ->
ctest --test-dir build --output-on-failure
*/