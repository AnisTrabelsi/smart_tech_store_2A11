#ifndef FACTUREW_H
#define FACTUREW_H

#include <QDialog>
#include "facture.h"
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
namespace Ui {
class factureW;
}

class factureW : public QDialog
{
    Q_OBJECT

public:
    explicit factureW(QWidget *parent = nullptr);
    ~factureW();


private slots:


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_modifier_2_clicked();
    void on_pushButton_clicked();

    void on_matricule_A_editingFinished();

    void on_recuperer_clicked();

    void on_pb_modifier_3_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_recuperer_2_clicked();

    void on_recuperer_3_clicked();


private:
    Ui::factureW *ui;
      facture F;
};

#endif // FACTUREW_H
