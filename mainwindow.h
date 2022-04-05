#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include "reclamation.h"
#include <QMainWindow>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    Fournisseur F;
     reclamation R;
};

#endif // MAINWINDOW_H
