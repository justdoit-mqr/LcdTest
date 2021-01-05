/*
 *@author:  缪庆瑞
 *@date:    2020.12.28
 *@brief:   用于LCD显示和触摸测试
 */
#include "lcdtestwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LcdTestWidget w;
    w.show();
    //w.showFullScreen();

    return a.exec();
}
