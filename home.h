#ifndef HOME_H
#define HOME_H

#include <QDialog>
#include "arduino.h"
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

private slots:
     void update_label();
    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_4_clicked();

    void on_pb_stat_clicked();

    void on_restaurer_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_modifier_3_clicked();

    void on_reset_ajouter_3_clicked();

private:
    Ui::home *ui;
    QByteArray data; // variable contenant les données reçues

       Arduino A; // objet temporaire
};

#endif // HOME_H
