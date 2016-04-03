#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>
#include<QVBoxLayout>
#include"controller.h"

namespace Ui {
class finestraPrincipale;
}

class finestraPrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit finestraPrincipale(QWidget *parent = 0);
    ~finestraPrincipale();
    void PaginaInziale();
    void CreaPersonaggio();
    //void MenuPrincipale();
    //void Combatti();
    //void Zaino();
    //void Mercante();
    //void Statistiche();
    //void Risultati();
public slots:
    void premiGioca();
private:
    controller* c1;
    Ui::finestraPrincipale *ui;
    QVBoxLayout* layoutPrincipale;
};

#endif // FINESTRAPRINCIPALE_H
