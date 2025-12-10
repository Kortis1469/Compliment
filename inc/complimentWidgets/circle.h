#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QWidget>
#include <vector>
#include <QColor>
#include "diskCreator.h"
#include "IttentGradientColorSetter.h"
#include <QtCore>
#include <QMouseEvent>

class Circle : public QWidget
{
    Q_OBJECT
    private:
        uint16_t width;
        uint16_t height;
        uint16_t radius;
        std::vector<point> circle;
    public:
        Circle(QWidget *parent, uint16_t width, uint16_t height);
        void paintEvent(QPaintEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;
        ~Circle();


};
#endif // CIRCLE_H
