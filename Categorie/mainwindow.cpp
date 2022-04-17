#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "categorie.h"
#include "arduino.h"
#include "categorie.cpp"
#include <QString>
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->view->setModel(CA.afficherCategorie(0));
    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).

}
void MainWindow::update_label()
{
     data="";
while(A.getdata().size()<5)
{
     data=A.read_from_arduino();
}
qDebug() << data ;

 // data=A.read_from_arduino();
  int D=data.toInt();
//qDebug() << D ;

    if(A.cherchercode(D)!=-1)
{
        QString nom=A.chercher(D);
        qDebug() << nom ;
        QByteArray x=nom.toUtf8();
        qDebug() << x ;
        A.write_to_arduino(x);
    }
    else
A.write_to_arduino("0");
data="";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NUM_clicked()
{
   ui->view->setModel(CA.afficherCategorie(1));
}
   void MainWindow::on_PAIMENT_clicked()
   {
      ui->view->setModel(CA.afficherCategorie(2));
   }
      void MainWindow::on_ID_clicked()
      {
         ui->view->setModel(CA.afficherCategorie(3));
      }
void MainWindow::on_valider_clicked()
{
    int ID_CATEGORIE = ui->ID_CATEGORIE->text().toInt();
    int REMISE = ui->REMISE->text().toInt();
    QString LIBELLE=ui->LIBELLE->text();
    Categorie CA(ID_CATEGORIE, LIBELLE,REMISE);
    bool test = CA.ajouterCategorie();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                                 QObject::tr("Categorie ajouté.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
        ui->view->setModel(CA.afficherCategorie(0));
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
    ui->ID_CATEGORIE->clear();
    ui->REMISE->clear();
    ui->LIBELLE->clear();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Categorie C1;
    C1.setID(ui->supp->text().toInt());
    bool test = C1.supprimerCategorie(C1.getID());

    if (test)

    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un Categorie"),
                                 QObject::tr("Categorie supprimé.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
        ui->view->setModel(CA.afficherCategorie(0));
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Categorie"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
    ui->supp->clear();
}

void MainWindow::on_cherchermodif_clicked()
{
    Categorie C1;
    C1 = C1.chercher_Categorie(ui->idmodif->text().toInt());

    if (C1.getID() != 0)
    {

        ui->idCategorie_3->setText(QString::number(C1.getID()));
        ui->REMISE_3->setText(QString::number(C1.getREMISE()));
        ui->LIBELLE_3->setText(C1.getLIBELLE());

        ui->view->setModel(CA.afficherCategorie(0));
    }
    else // introuvable
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                              QObject::tr("employee introuvable !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_valider_3_clicked()
{

    int ID_CATEGORIE = ui->idCategorie_3->text().toInt();
    int REMISE = ui->REMISE_3->text().toInt();
    QString LIBELLE=ui->LIBELLE_3->text();
    Categorie C(ID_CATEGORIE,LIBELLE,REMISE);

    Categorie E1;
    int test = E1.CategorieExists(ID_CATEGORIE);

    if (test == true)
    {
        if (int test1 = E1.modifier_Categorie(ID_CATEGORIE,LIBELLE,REMISE) == true)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un Categorie"),
                                     QObject::tr("Categorie modifié.\n"
                                                 "Click Cancel to exit."),
                                     QMessageBox::Cancel);
            ui->view->setModel(E1.afficherCategorie(0));
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un modifé"),
                                  QObject::tr("Erreur de modification!.\n"
                                              "Click Cancel to exit."),
                                  QMessageBox::Cancel);
        }
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
}


