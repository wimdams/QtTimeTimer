#include "colorwidget.h"

ColorWidget::ColorWidget(QWidget *parent) : QWidget(parent)
{
    m_color = Qt::white;
    setFocusPolicy(Qt::StrongFocus);
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
    QRect rect(1,1,this->width()-2,this->height()-2);

    p.setBrush(m_color);
    p.drawRect(0,0,this->width()-1,this->height()-1);

    //Als we de focus hebben tekenen we een focus rechthoek
    if(hasFocus()){
        QStyleOptionFocusRect option;
        option.initFrom(this);
        option.backgroundColor = palette().color(QPalette::Background);
        option.rect = rect;
        style()->drawPrimitive(QStyle::PE_FrameFocusRect, &option, &p, this);
    }
    //De beste contrast kleur berekenen
    p.setPen(m_color.lightness() > 127? Qt::black : Qt::white);
    QString rgb("#%1%2%3");
    rgb = rgb.arg(m_color.red(),2,16,QChar('0')).arg(m_color.green(),2,16,QChar('0')).arg(m_color.blue(),2,16,QChar('0'));
    rgb = rgb.toUpper();
    p.drawText(rect,Qt::AlignVCenter | Qt::AlignHCenter,rgb);
}

void ColorWidget::mousePressEvent(QMouseEvent *event)
{
    (void) event;
    showColorDialog();
}

void ColorWidget::keyPressEvent(QKeyEvent *event)
{
    //Enkel reageren op enter en spatie
    if(event->type() == QEvent::KeyPress && (event->key() == Qt::Key_Space || event->key() == Qt::Key_Enter  || event->key() == Qt::Key_Return )){
        showColorDialog();
    }else{
        QWidget::keyPressEvent(event);
    }
}

void ColorWidget::showColorDialog()
{
    QColor c = QColorDialog::getColor(m_color,this,"choose the new color");
    if(c.isValid()){
        m_color = c;
        update();
        emit( newColor(m_color));
    }
}

