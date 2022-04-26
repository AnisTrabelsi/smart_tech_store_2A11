#ifndef FOURNISSEURW_H
#define FOURNISSEURW_H
#include "fournisseur.h"
#include "reclamation.h"

#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include <QDialog>
#include "menu.h"
namespace Ui {
class fournisseurw;
}

class fournisseurw : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseurw(QWidget *parent = nullptr);
    ~fournisseurw();

private slots:
    void on_valider_clicked();

    void on_pb_supprimer_clicked();

    void on_cherchermodif_clicked();

    void on_valider_2_clicked();

    void on_valider_3_clicked();

    void on_act_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_supprimer_2_clicked();

    void on_reset_ajouter_3_clicked();

    void on_reset_ajouter_2_clicked();

    void on_pb_supprimer_5_clicked();

    void on_return_fo_clicked();

private:
    Ui::fournisseurw *ui;
    Fournisseur F;
     reclamation R;
};

#endif // FOURNISSEURW_H
