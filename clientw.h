#ifndef CLIENTW_H
#define CLIENTW_H

#include <QDialog>
#include "client.h"
#include "exportexcel.h"
#include <QTime>
#include"arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class clientw;
}

class clientw : public QDialog
{
    Q_OBJECT

public:
    explicit clientw(QWidget *parent = nullptr);
    ~clientw();

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

    void on_return_home_clicked();

private:
    Ui::clientw *ui;
    client C;
    QByteArray code;//variable contenant les données recues
    Arduino A;
};

#endif // CLIENTW_H
