/*
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@brief:   十字线部件
 */
#ifndef CROSSCURVEWIDGET_H
#define CROSSCURVEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>

class CrossCurveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CrossCurveWidget(QWidget *parent = 0);

protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void paintEvent(QPaintEvent  *event);

private:
    QPoint currentPos;//记录鼠标按下的当前坐标(相对该部件自身)

signals:

public slots:
};

#endif // CROSSCURVEWIDGET_H
