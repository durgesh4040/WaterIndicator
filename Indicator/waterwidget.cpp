#include "waterwidget.h"
#include<QPainter>
#include<QPen>
#include<QBrush>

WaterWidget::WaterWidget(QWidget *parent)
    : QWidget{parent},
      waterheight(50)
{


    QSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
    timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,[=](){
waterheight+=5;
update();
if(waterheight<=210){
  emit normal();
    }
else if(waterheight>=211&&waterheight<=250){
    emit warning();

}else{
    emit danger();
    }
    });
timer->start();
}

void WaterWidget::paintEvent(QPaintEvent *event)
{
QPen pen;
pen.setWidth(3);
pen.setColor(Qt::black);
 QPainter painter(this);
 painter.setPen(pen);
 //painter.setBrush(Qt::blue);
 painter.drawLine(10,10,10,300);//drawLine in left
 painter.drawLine(10,300,300,300);
 painter.drawLine(300,300,300,10);
 painter.setBrush(Qt::blue);
 painter.drawRect(10,300-waterheight,290,waterheight);
 //painter.setFont(QFont("Times",14,QFont::Bold));
 //painter.drawText(QPoint(320,360),"WATER TANK");
}
QSize WaterWidget::sizeHint() const
{
   return QSize(500,500);
}
