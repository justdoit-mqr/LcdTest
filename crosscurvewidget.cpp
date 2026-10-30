/*
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@update:  2026.10.30
 *@brief:   十字线部件
 */
#include "crosscurvewidget.h"
#include <QFontMetrics>

CrossCurveWidget::CrossCurveWidget(QWidget *parent) : QWidget(parent)
{
}
/*
 *@brief:   鼠标按下事件处理
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
 *@brief:   鼠标移动事件(按下)处理
 *@date:    2026.10.30
 *@param:   event:鼠标事件
 */
void CrossCurveWidget::mouseMoveEvent(QMouseEvent *event)
{
    currentPos = event->pos();
    update();

    QWidget::mouseMoveEvent(event);//事件传递给父部件
}
/*
 *@brief:   绘图事件处理函数
 *@date:    2020.12.28
 *@update:  2026.10.30
 *@param:   event: 传递的绘图事件
 */
void CrossCurveWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if(!currentPos.isNull())
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);//反锯齿
        QFont font;
        font.setPointSize(9);
        painter.setFont(font);//设置字体
        QPen pen;
        pen.setColor(Qt::red);
        painter.setPen(pen);//设置画笔
        //横线/纵线各绘制3条,用来指示交点坐标
        int margins = 40;//四周margin
        int halfWidth = this->width()/2;
        int halfHeight = this->height()/2;
        painter.drawLine(0,margins,this->width(),margins);
        painter.drawLine(0,halfHeight,this->width(),halfHeight);
        painter.drawLine(0,this->height()-margins,this->width(),this->height()-margins);
        painter.drawLine(margins,0,margins,this->height());
        painter.drawLine(halfWidth,0,halfWidth,this->height());
        painter.drawLine(this->width()-margins,0,this->width()-margins,this->height());
        //绘制横纵线交点坐标
        QString leftTopPos = QString("(%1,%2)").arg(margins).arg(margins);
        painter.drawText(margins+5,margins-5,leftTopPos);
        QString leftBottomPos = QString("(%1,%2)").arg(margins).arg(this->height()-margins);
        painter.drawText(margins+5,this->height()-margins-5,leftBottomPos);
        QString centerPos = QString("(%1,%2)").arg(halfWidth).arg(halfHeight);
        painter.drawText(halfWidth+5,halfHeight-5,centerPos);
        QString rightTopPos = QString("(%1,%2)").arg(this->width()-margins).arg(margins);
        QFontMetrics fontMetrics(font);
        painter.drawText(this->width()-margins-5-fontMetrics.horizontalAdvance(rightTopPos),margins-5,rightTopPos);
        QString rightBottomPos = QString("(%1,%2)").arg(this->width()-margins).arg(this->height()-margins);
        painter.drawText(this->width()-margins-5-fontMetrics.horizontalAdvance(rightBottomPos),this->height()-margins-5,rightBottomPos);
        //绘制点击位置交点坐标和交点
        painter.drawText(currentPos.x()+5,currentPos.y()+20,QString("(%1,%2)").arg(currentPos.x()).arg(currentPos.y()));
        pen.setWidth(4);
        painter.setPen(pen);
        painter.drawPoint(currentPos.x(),currentPos.y());
        /*画xy轴线
        painter.drawLine(0,currentPos.y(),this->width(),currentPos.y());
        painter.drawLine(currentPos.x(),0,currentPos.x(),this->height());*/

    }
}
