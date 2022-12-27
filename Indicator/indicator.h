#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include<QTimer>
class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
    // QWidget interface
public:
    QSize sizeHint() const override;
public slots:
    void activateNormal();
    void activateWarning();
    void activateDanger();
private:
    void toogleLights();
    bool  redActive;
    bool greenActive;
    bool yellowActive;
    bool lightOn;
    QTimer *timer;
};
#endif // INDICATOR_H
