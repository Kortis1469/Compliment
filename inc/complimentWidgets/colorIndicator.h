#ifndef DONAT_H
#define DONAT_H
#pragma once

#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QWidget>
#include <vector>
#include <QColor>
#include <QtCore>
#include <QMouseEvent>
#include "diskCreator.h"
#include "donatCreator.h"

class ColorIndicator : public QWidget
{
    Q_OBJECT
private:
    uint16_t width;
    uint16_t height;
    uint16_t radius;
    uint16_t xCenter;
    uint16_t yCenter;
    uint16_t radiusAlign;

    std::shared_ptr<const std::vector<point>> indicator;
    QPoint dragOffset;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    bool isValidArea(QPoint offset);
    void biasToRadius(QPoint &position);
    

public:
    ColorIndicator(QWidget *parent, int32_t xCenter, int32_t yCenter, int32_t radius, int32_t innerRadius);
    void paintEvent(QPaintEvent *event) override;
    void alignToRadius(uint16_t xCenter, uint16_t yCenter, uint16_t radius);
    ~ColorIndicator();
};
#endif // DONAT_H