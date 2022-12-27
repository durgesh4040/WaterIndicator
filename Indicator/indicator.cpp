#include "indicator.h"
#include<QPainter>
#include<QPen>
#include<QBrush>

Indicator::Indicator(QWidget *parent)
    : QWidget{parent},
    redActive(false),
      greenActive(false),
      yellowActive(false),
      lightOn(true)
    {
    greenActive=true;
QSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
timer=new QTimer(this);
timer->setInterval(700);
connect(timer,&QTimer::timeout,[=](){
   toogleLights();
});
timer->start();
}
void Indicator::paintEvent(QPaintEvent *event)
{
    QPen mpen;
    mpen.setWidth(3);
    mpen.setColor(Qt::black);
    QPainter painter(this);
   painter.setPen(mpen);
    painter.setBrush(Qt::gray);
    painter.drawRect(QRectF(0,0,120,330));
    //Red light Active:
    if(redActive){
    painter.setBrush(lightOn==true? Qt::red :Qt::black);
    painter.drawEllipse(10,10,100,100);
    painter.setBrush(Qt::black);
    painter.drawEllipse(10,120,100,100);
    painter.setBrush(Qt::black);
    painter.drawEllipse(10,230,100,100);
    }
    else if(greenActive){
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);
        painter.setBrush(lightOn==true? Qt::green :Qt::black);
        painter.drawEllipse(10,120,100,100);
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,230,100,100);
        }
    else if(yellowActive){
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,120,100,100);
        painter.setBrush(lightOn==true? Qt::yellow:Qt::black);
        painter.drawEllipse(10,230,100,100);
    }else{
        painter.setBrush(Qt::red);
        painter.drawEllipse(10,10,100,100);
        painter.setBrush(Qt::green);
        painter.drawEllipse(10,120,100,100);
        painter.setBrush(Qt::yellow);
        painter.drawEllipse(10,230,100,100);
        }
}

QSize Indicator::sizeHint() const
{
    return QSize(120,350);
}

void Indicator::activateNormal()
{
greenActive=true;
redActive =false;
yellowActive=false;
}

void Indicator::activateWarning()
{
    yellowActive=true;
    greenActive=false;
    redActive=false;

}

void Indicator::activateDanger()
{
redActive=true;
greenActive=false;
yellowActive=false;
}

void Indicator::toogleLights()
{
if(!lightOn){
    lightOn=true;
}else{
    lightOn=false;
}
update();
}
