#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>

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
    QColor m_color;
};

#endif // COLORWIDGET_H
