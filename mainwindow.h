#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include "reclamation.h"
#include <QMainWindow>

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




    void on_pushButton_clicked();

    void on_valider_3_clicked();

    void on_act_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur F;
     reclamation R;
};

#endif // MAINWINDOW_H
