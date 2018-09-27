#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>
#include <QColorDialog>
#include <QKeyEvent>
#include <QPainter>
#include <QStyleOptionFocusRect>
#include "wda.h"

class ColorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorWidget(QWidget *parent = nullptr);
    QColor color();
signals:
    void newColor(QColor);
public slots:
    void setColor(QColor);
private:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void showColorDialog();
    QColor m_color;
};

#endif // COLORWIDGET_H
