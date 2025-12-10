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
    std::vector<point> donat;
public:
    ColorIndicator(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
    //void mousePressEvent(QMouseEvent *event) override;
    ~ColorIndicator();
};
#endif // DONAT_H
