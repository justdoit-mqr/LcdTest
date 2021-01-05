/*
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@brief:   触摸方块部件
 */
#ifndef TOUCHLABEL_H
#define TOUCHLABEL_H

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>

class TouchLabel : public QLabel
{
    Q_OBJECT
public:
    explicit TouchLabel(QWidget *parent = 0);

protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void paintEvent(QPaintEvent  *event);

private:
    bool isTouch;//标记是否已被触摸

signals:

public slots:
};

#endif // TOUCHLABEL_H
