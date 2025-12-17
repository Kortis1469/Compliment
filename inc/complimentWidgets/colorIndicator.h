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
#include "basicTypes.h"
#include "diskCreator.h"
#include "donatCreator.h"

class ColorIndicator : public QWidget
{
    Q_OBJECT
private:
    uint16_t width;
    uint16_t height;
    uint16_t radius;
    std::shared_ptr<const std::vector<point>> indicator;
    QPoint dragOffset;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;    

public:
    ColorIndicator(QWidget *parent, uint16_t x1, uint16_t y1,uint16_t x2, uint16_t y2);
    void paintEvent(QPaintEvent *event) override;
    ~ColorIndicator();
};
#endif // DONAT_H

/*
class DraggableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DraggableWidget(QWidget *parent = nullptr)
        : QWidget(parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton) {
            dragOffset = event->globalPos() - frameGeometry().topLeft();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override
    {
        if (event->buttons() & Qt::LeftButton) {
            move(event->globalPos() - dragOffset);
        }
    }

private:
    QPoint dragOffset;
};
*/