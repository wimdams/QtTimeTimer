#ifndef TIMERENDERER_H
#define TIMERENDERER_H

#include <QWidget>

class TimeRenderer : public QWidget
{
    Q_OBJECT
public:
    explicit TimeRenderer(QWidget *parent = nullptr);

signals:
    void triggered();

public slots:
    void start();
    void reset();
    void setFGColor(QColor);
    void setBGColor(QColor);

private:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    QTimer * t;
    QColor m_FGColor;
    QColor m_BGColor;
};

#endif // TIMERENDERER_H
