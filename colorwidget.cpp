#include "colorwidget.h"

#include <QColorDialog>
#include <QPainter>

ColorWidget::ColorWidget(QWidget *parent) : QWidget(parent)
{
    m_color = Qt::white;
}

QColor ColorWidget::color()
{
    return m_color;
}

void ColorWidget::setColor(QColor newColor)
{
    m_color = newColor;
}

void ColorWidget::paintEvent(QPaintEvent *event)
{
    (void) event;
    QPainter p(this);
    p.setBrush(m_color);
    p.drawRect(0,0,this->width()-1,this->height()-1);
}

void ColorWidget::mousePressEvent(QMouseEvent *event)
{
    (void) event;
    QColor c = QColorDialog::getColor(m_color,this,"choose the new color");
    if(c.isValid()){
        m_color = c;
        update();
        emit( newColor(m_color));
    }
}
