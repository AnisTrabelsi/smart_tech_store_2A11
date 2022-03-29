#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
#include <QSound>
#include <QtWidgets/QApplication>

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_chercher_clicked();

    void on_pb_modifier_clicked();

    void on_tri_croissant_clicked();

    void on_tri_decroissant_clicked();

    void on_cherche_aff_clicked();

    void on_tri_ref_clicked();

    void on_tri_quantite_clicked();

    void on_tri_libelle_clicked();

    void on_stat_clicked();

    void on_reset_ajouter_clicked();

private:
    Ui::MainWindow *ui;
    Produit P;
    QSound *son;


};

#endif // MAINWINDOW_H
