#ifndef COMMANDEW_H
#define COMMANDEW_H
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include "Commande.h"
#include <QDialog>

namespace Ui {
class commandeW;
}

class commandeW : public QDialog
{
    Q_OBJECT

public:
    explicit commandeW(QWidget *parent = nullptr);
    ~commandeW();
private slots:
    void on_valider_clicked();

    void on_pb_supprimer_clicked();

    void on_cherchermodif_clicked();

   void on_valider_3_clicked();
   void on_pushButton_clicked();
   void on_NUM_clicked();
   void on_PAIMENT_clicked();
   void on_ID_clicked();

private:
    Ui::commandeW *ui;
    Commande C;
};

#endif // COMMANDEW_H
