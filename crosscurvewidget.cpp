/*
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@brief:   十字线部件
 */
#include "crosscurvewidget.h"

CrossCurveWidget::CrossCurveWidget(QWidget *parent) : QWidget(parent)
{
}
/*
 *@brief:   鼠标按下事件处理
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@param:   e:鼠标事件
 */
void CrossCurveWidget::mousePressEvent(QMouseEvent *e)
{
    currentPos = e->pos();
    update();

    QWidget::mousePressEvent(e);//事件传递给父部件
}
/*
 *@brief:   绘图事件处理函数
 *@author:  缪庆瑞
 *@date:    2020.12.28
 *@param:   event: 传递的绘图事件
 */
void CrossCurveWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if(!currentPos.isNull())
    {
        //定义painter,设置属性
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);//反锯齿
        painter.setPen(QColor(Qt::red));//红色画笔
        //画x轴线
        painter.drawLine(0,currentPos.y(),1024,currentPos.y());
        //画y轴线
        painter.drawLine(currentPos.x(),0,currentPos.x(),600);
    }
}
