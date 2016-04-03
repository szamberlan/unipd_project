#ifndef CONTROLLER
#define CONTROLLER
#include"arenasemplice.h"
#include<QVector>
#include<QWidget>
class controller {
private:
    arena*a1;
    QVector<QWidget*> contenitorQWidget;
public:
    controller(arena*);
    virtual ~controller();
    void insertWidget(QWidget*);
    void removeWidget();
};

#endif // CONTROLLER

