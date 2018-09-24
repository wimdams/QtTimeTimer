#include "timerenderer.h"

TimeRenderer::TimeRenderer(QWidget *parent) : QWidget(parent)
{
    t = new QTimer(this);
    t->setInterval(100);
    connect(t, SIGNAL(timeout()), this, SLOT(update()));
    m_FGColor = Qt::red;
    m_BGColor = Qt::white;
    m_totalTime.setHMS(0,1,0); //hhmmss
    m_started = false;
}

void TimeRenderer::start()
{
    m_startTime = QTime::currentTime();
    m_endTime = m_startTime.addSecs(m_totalTime.msecsSinceStartOfDay()/1000);
    t->start();
    m_started = true;
}

void TimeRenderer::reset()
{
    t->stop();
    m_started = false;
}

void TimeRenderer::setFGColor(QColor newColor)
{
    m_FGColor = newColor;
}

void TimeRenderer::setBGColor(QColor newColor)
{
    m_BGColor = newColor;
}

void TimeRenderer::setTotalTime(QTime totalTime)
{
    m_totalTime = totalTime;
    m_endTime = m_startTime.addSecs(m_totalTime.msecsSinceStartOfDay()/1000);
}

void TimeRenderer::paintEvent(QPaintEvent *event)
{
    (void) event;
    double hoek = 0;
    if(m_started){
       int delta = QTime::currentTime().msecsTo(m_endTime);
       int totaal = m_totalTime.msecsSinceStartOfDay();
       hoek = (360.0 * delta * 16) / totaal;
       if(hoek<0){
           hoek = 0;
           emit elapsed();
       }
       hoek = 360 * 16 - hoek;
    }            //QTime::currentTime().second() *96;
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
