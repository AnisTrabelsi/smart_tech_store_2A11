#ifndef CATEGORIEW_H
#define CATEGORIEW_H
#include "categorie.h"
#include "arduino.h"
#include <QDialog>

namespace Ui {
class Categoriew;
}

class Categoriew : public QDialog
{
    Q_OBJECT

public:
    explicit Categoriew(QWidget *parent = nullptr);
    ~Categoriew();
private slots:
    void on_valider_clicked();

    void on_pb_supprimer_clicked();

    void on_cherchermodif_clicked();
    void update_label();

   void on_valider_3_clicked();
   void on_NUM_clicked();
   void on_PAIMENT_clicked();
   void on_ID_clicked();

   void on_return_2_clicked();

private:
    Ui::Categoriew *ui;
    Categorie CA;
    QByteArray data; // variable contenant les données reçues

       Arduino A; // objet temporaire

};

#endif // CATEGORIEW_H
