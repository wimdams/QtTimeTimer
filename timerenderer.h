#ifndef TIMERENDERER_H
#define TIMERENDERER_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QDebug>
#define QD qDebug() << __FILE__ << __LINE__

class TimeRenderer : public QWidget
{
    Q_OBJECT
public:
    explicit TimeRenderer(QWidget *parent = nullptr);

signals:
    void triggered();
    void elapsed();

public slots:
    void start();
    void reset();
    void setFGColor(QColor);
    void setBGColor(QColor);
    void setTotalTime(QTime);
private:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    QTimer * t;
    QColor m_FGColor;
    QColor m_BGColor;
    QTime m_startTime;  //absoluut
    QTime m_totalTime;  //relatief
    QTime m_endTime;    //absoluut
    bool m_started;
};

#endif // TIMERENDERER_H
