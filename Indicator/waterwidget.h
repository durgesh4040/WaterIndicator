#ifndef WATERWIDGET_H
#define WATERWIDGET_H

#include <QWidget>
#include<QTimer>


class WaterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaterWidget(QWidget *parent = nullptr);
signals:
 // QWidget interface
    void normal();
    void warning();
    void danger();
protected:
    void paintEvent(QPaintEvent *event) override;

    // QWidget interface
public:
    QSize sizeHint() const override;
private :
    int waterheight;
    QTimer *timer;
};

#endif // WATERWIDGET_H
