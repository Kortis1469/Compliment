#ifndef DONAT_H
#define DONAT_H


#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QWidget>
#include <vector>
#include <QColor>
#include <QtCore>
#include <QMouseEvent>
#include "circle.h"

class Donat : public QWidget
{
    Q_OBJECT
private:
    DonatCreator donatCr;
    std::vector<point> donat;
public:
    Donat(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
    //void mousePressEvent(QMouseEvent *event) override;
    ~Donat();


};
#endif // DONAT_H
