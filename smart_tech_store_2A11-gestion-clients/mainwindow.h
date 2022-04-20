#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
#include "exportexcel.h"
#include <QTime>
#include"arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   void myfunction();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_pb_chercher_client_clicked();


    void on_pb_modifier_clicked();




    void on_radio_nom_clicked();


    void on_radio_prenom_clicked();


    void on_radio_nb_pts_clicked();

    void on_pb_client_dumois_clicked();

    void on_pb_chercher_aff_clicked();

    void on_reset_clicked();








    void on_tabWidget_currentChanged(int index);


    void on_exporter_clicked();

    void on_pb_historique_client_clicked();



private:
    Ui::MainWindow *ui;
    client C;
    QByteArray code;//variable contenant les données recues
    Arduino A;
};
#endif // MAINWINDOW_H
