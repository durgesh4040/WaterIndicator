#include "widget.h"
#include "ui_widget.h"
#include"indicator.h"
#include"waterwidget.h"
#include<QLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   Indicator *indicator=new Indicator(this);
    WaterWidget *tank=new WaterWidget(this);
    connect(tank,&WaterWidget::normal,indicator,&Indicator::activateNormal);
    connect(tank,&WaterWidget::warning,indicator,&Indicator::activateWarning);
    connect(tank,&WaterWidget::danger,indicator,&Indicator::activateDanger);
    ui->horizontalLayout->addWidget(indicator);
    ui->horizontalLayout->addWidget(tank);

   // waw->isRightToLeft();
}

Widget::~Widget()
{
    delete ui;
}

