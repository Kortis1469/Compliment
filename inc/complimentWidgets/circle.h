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
        uint16_t XCenter;
        uint16_t YCenter;
        uint16_t radius;

        std::shared_ptr<const std::vector<point>> colorDisk;
    public:
        Circle(QWidget *parent, uint16_t x1, uint16_t y1,uint16_t x2, uint16_t y2);
        void paintEvent(QPaintEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;
        uint16_t getRadius();
        uint16_t getXCenter();
        uint16_t getYCenter();
        ~Circle() = default;


};
#endif // CIRCLE_H
