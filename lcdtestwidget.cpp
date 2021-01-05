/*
 *@author:  缪庆瑞
 *@date:    2020.12.28
 *@brief:   LCD显示与触摸测试界面
 */
#include "lcdtestwidget.h"
#include <QGridLayout>
#include <QApplication>
#include <QDebug>

//lcd屏幕分辨率
#define LCD_RESOLUTION_X 1024
#define LCD_RESOLUTION_Y 600

LcdTestWidget::LcdTestWidget(QWidget *parent)
    : QFrame(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(LCD_RESOLUTION_X,LCD_RESOLUTION_Y);

    //触摸块部件
    touchWidget = new QWidget(this);
    touchWidget->setVisible(false);
    touchWidget->setFixedSize(LCD_RESOLUTION_X,LCD_RESOLUTION_Y);
    QGridLayout *gridLayout = new QGridLayout(touchWidget);//布局小块
    gridLayout->setMargin(0);
    gridLayout->setSpacing(0);
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<20;j++)
        {
            touchLabel[i][j] = new TouchLabel(this);
            gridLayout->addWidget(touchLabel[i][j],i,j);
        }
    }
    //十字线部件   显示在父部件的最上方
    crossCurveWidget = new CrossCurveWidget(this);
    crossCurveWidget->setFixedSize(LCD_RESOLUTION_X,LCD_RESOLUTION_Y);
    crossCurveWidget->raise();
    //自动切换颜色定时器
    colorNameList<<"white"<<"red"<<"green"<<"blue"<<"cyan"<<"magenta"<<"yellow";
    colorNameIndex = 0;
    colorChangeTimer = new QTimer(this);
    colorChangeTimer->setInterval(1000);
    connect(colorChangeTimer,SIGNAL(timeout()),this,SLOT(colorChangeTimerSlot()));
    colorChangeTimer->start();
    colorChangeTimerSlot();
}

LcdTestWidget::~LcdTestWidget()
{
}
/*
 *@brief:   鼠标按下事件处理
 * 将鼠标按下事件分发给触摸块部件
 *@author:  缪庆瑞
 *@date:    2020.12.29
 *@param:   e:鼠标事件
 */
void LcdTestWidget::mousePressEvent(QMouseEvent *e)
{
    //关闭颜色切换定时器
    if(colorChangeTimer->isActive())
    {
        colorChangeTimer->stop();
        touchWidget->setVisible(true);//显示触摸块小部件
        this->setStyleSheet(QString("LcdTestWidget{background-color:%1;}").arg(colorNameList.at(0)));
    }
    /*使用childAt()获取指定位置的小部件,然后将鼠标事件的pos转换(mapFrom())后发送给小部件
     * 注:当同一位置有多个部件时childAt()返回最上层显示且能够接收鼠标事件的部件，所以此处
     * 默认获取的将是crossCurveWidget部件，要想获取TouchLabel部件此处需要先把crossCurveWidget
     * 设置鼠标透传属性。
     */
    crossCurveWidget->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    QWidget *wid = this->childAt(e->pos());
    if(wid)
    {
        QPoint p = wid->mapFrom(this, e->pos());
        QMouseEvent *mEvent = new QMouseEvent(e->type(), p, e->button(), e->buttons(), e->modifiers());
        QApplication::postEvent(wid, mEvent);
    }
    crossCurveWidget->setAttribute(Qt::WA_TransparentForMouseEvents, false);
}
/*
 *@brief:   自动切换颜色定时器响应槽
 *@author:  缪庆瑞
 *@date:    2020.12.29
 */
void LcdTestWidget::colorChangeTimerSlot()
{
    this->setStyleSheet(QString("background-color:%1;").arg(colorNameList.at(colorNameIndex)));
    colorNameIndex++;
    if(colorNameIndex>=colorNameList.size())
    {
        colorNameIndex = 0;
    }
}
