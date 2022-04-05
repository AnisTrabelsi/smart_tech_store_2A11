#ifndef HOME_H
#define HOME_H

#include <QDialog>

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
    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_3_clicked();

    void on_pb_modifier_4_clicked();

    void on_pb_trier_2_clicked();

    void on_pb_stat_clicked();

    void on_pb_modifier_5_clicked();

    void on_restaurer_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
