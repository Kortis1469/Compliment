#include "donat.h"


Donat::Donat(QWidget *parent):QWidget(parent), donatCr(10)
{
    resize(1080, 720);
}

void Donat::paintEvent(QPaintEvent *event){
    int
        magicX = 1080/2,
        magicY = 720/2,
        magicR = 8;
    int
        height = abs(magicR-magicY),
        width = abs(magicR-magicX);

    std::vector<point> pts = donatCr.createCircle(magicX, magicY, magicR);

    QPainter p;
    p.begin(this);
    for(point p2:pts){
        p.setPen(p2.color);
        p.drawPoint(p2.x,p2.y);
    }
    p.end();
    donat = pts;
}

Donat::~Donat()
{

}
