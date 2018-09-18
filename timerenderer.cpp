#include "timerenderer.h"

#include <QPainter>
#include <QTime>
#include <QTimer>

TimeRenderer::TimeRenderer(QWidget *parent) : QWidget(parent)
{
    t = new QTimer(this);
    t->setInterval(1000);
    connect(t, SIGNAL(timeout()), this, SLOT(update()));
    m_FGColor = Qt::red;
    m_BGColor = Qt::white;
}

void TimeRenderer::start()
{
    t->start();
}

void TimeRenderer::reset()
{
    t->stop();
}

void TimeRenderer::setFGColor(QColor newColor)
{
    m_FGColor = newColor;
}

void TimeRenderer::setBGColor(QColor newColor)
{
    m_BGColor = newColor;
}

void TimeRenderer::paintEvent(QPaintEvent *event)
{
    (void) event;
    int hoek = QTime::currentTime().second() *96;
    //achtergrond
    QPainter p(this);
    p.setBrush(m_BGColor);
    p.drawRect(0,0,this->width()-1,this->height()-1);

    //voorgrond
    p.setBrush(m_FGColor);
    QPoint center(this->width()/2,this->height()/2);
    int straal = (qMin(this->width(),this->height()) - 10) / 2;
    QRect rect(center.x()-straal, center.y()-straal, straal*2, straal*2);
    p.drawPie(rect, 90*16, 360*16 - hoek);
}

void TimeRenderer::mouseDoubleClickEvent(QMouseEvent *event)
{
    (void) event;
    emit triggered();
}
