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
#include "circle.h"
#include <QLabel>

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
    Circle * circle;
    QLabel * label;
    std::shared_ptr<const std::vector<point>> indicator;
    QPoint dragOffset;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    bool isValidArea(QPoint offset);
    void biasToRadius(QPoint &position);
    

public:
    ColorIndicator(QWidget *parent, int32_t radius, int32_t innerRadius, Circle * circle, QLabel * output);
    void paintEvent(QPaintEvent *event) override;
    void alignToColorCircle(Circle * c);
    void alignToRadius(uint16_t xCenter, uint16_t yCenter, uint16_t radius);
    void setColorOutput(QLabel * label);
    QPoint getActualCenter() const;
    QColor getColorFromCenterPix();
    void updateOutput();
    ~ColorIndicator();
};
#endif // DONAT_H