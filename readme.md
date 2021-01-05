# LcdTest
这是一个基于Qt widget开发用于测试Lcd液晶屏显示和触摸功能的小程序。
## 示例:
![1.gif](./screenshot/1.gif)
## 功能概述：
LcdTest的主要功能是测试液晶屏的显示和触摸是否正常。  
程序启动后会定时循环播放不同的背景颜色，用户可通过这些颜色判断液晶屏显示是否正常。接着点击界面的任意位置，如果触摸正常的话界面会停止播放背景颜色，显示出12×20个方块，可通过点击这些方块根据十字线确定触摸位置是否准确。  
该程序由三个类构成：LcdTestWidget、CrossCurveWidget、TouchLabel  
LcdTestWidget：程序主窗口部件，负责整个程序的控制逻辑，以及鼠标事件的分发处理。  
CrossCurveWidget:绘制十字线的透明部件，作为主窗口的子部件通过raise()提升至最上层  
TouchLabel:触摸方块部件，用于标识一个大致的触摸位置，并在触摸后切换颜色显示  
## 小结：
这是一个比较简单的小程序，唯一值得一提的应该是这里面关于鼠标事件的传递处理。其中包括子部件对事件的accept()和ignore()处理对父部件的影响，以及父部件将接到的鼠标事件进行转换后再主动分发给子部件的处理。另外childAt()和鼠标透传属性Qt::WA_TransparentForMouseEvents的关系也值得好好分析一番。

## 作者联系方式:
**邮箱:justdoit_mqr@163.com**  
**新浪微博:@为-何-而来**  