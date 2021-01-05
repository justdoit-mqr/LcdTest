/*
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@brief:   触摸方块部件
 */
#include "touchlabel.h"

TouchLabel::TouchLabel(QWidget *parent)
    : QLabel(parent),isTouch(false)
{

}
/*
 *@brief:   鼠标按下事件处理
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@param:   e:鼠标事件
 */
void TouchLabel::mousePressEvent(QMouseEvent *e)
{
    isTouch = true;
    update();
    e->accept();//接受事件不再上传
}
/*
 *@brief:   绘图事件处理函数
 *@author:  缪庆瑞
 *@date:    2020.12.28
 *@param:   event: 传递的绘图事件
 */
void TouchLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    //定义painter,设置属性
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//反锯齿
    painter.setPen(QColor(Qt::lightGray));//画笔
    if(isTouch)
    {
        painter.setBrush(QBrush(Qt::green));
        painter.drawRect(this->rect());
    }
    else
    {
        painter.drawRect(this->rect());
    }
}
