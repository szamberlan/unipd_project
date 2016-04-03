#include"controller.h"

controller::controller(arena *a): a1(a){}

controller::~controller()
{
    delete a1;
    removeWidget();
}

void controller::insertWidget(QWidget *qw)
{
    if(qw)
    {
        contenitorQWidget.push_back(qw);
    }
}

void controller::removeWidget()
{
    if(!contenitorQWidget.empty())
    {
        QVector<QWidget*>::iterator it;
        it=contenitorQWidget.begin();
        while(it!=contenitorQWidget.end())
        {
            delete *it;
            ++it;
        }
        contenitorQWidget.clear();
    }
}
