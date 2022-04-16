#pragma once
#include "categorie.h"
#include <QMainWindow>
#include "arduino.h"

namespace Ui
{
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

   void on_valider_3_clicked();
   void on_NUM_clicked();
   void on_PAIMENT_clicked();
   void on_ID_clicked();

private:
    Ui::MainWindow *ui;
     Categorie CA;
     QByteArray data; // variable contenant les données reçues

        Arduino A; // objet temporaire


};
