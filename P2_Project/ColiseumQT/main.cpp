#include<iostream>
using namespace std;
#include<QApplication>
#include"finestragioco.h"
int main(int argc, char* argv[])
{
    QApplication a(argc,argv);
    finestraGioco f;
    f.show();
    return a.exec();
}
