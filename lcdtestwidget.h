/*
 *@author:  缪庆瑞
 *@date:    2020.12.28
 *@brief:   LCD显示与触摸测试界面
 */
#ifndef LCDTESTWIDGET_H
#define LCDTESTWIDGET_H

#include "touchlabel.h"
#include "crosscurvewidget.h"
#include <QFrame>
#include <QTimer>


class LcdTestWidget : public QFrame
{
    Q_OBJECT

public:
    LcdTestWidget(QWidget *parent = 0);
    ~LcdTestWidget();

protected:
    virtual void mousePressEvent(QMouseEvent *e);

private:
    QWidget *touchWidget;//触摸块部件
    TouchLabel *touchLabel[12][20];//12*20个触摸方块
    CrossCurveWidget *crossCurveWidget;//十字线部件

    QTimer *colorChangeTimer;//自动切换颜色的定时器
    QStringList colorNameList;//颜色列表
    int colorNameIndex;//颜色索引

signals:

public slots:
    void colorChangeTimerSlot();
};

#endif // LCDTESTWIDGET_H
