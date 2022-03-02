#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Commande.h"
#include "Commande.cpp"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->view->setModel(C.afficherCommande());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valider_clicked()
{
    int idCommande = ui->idCommande->text().toInt();
    int num_Tel = ui->num_Tel->text().toInt();
    int quantity = ui->quantity->text().toInt();
    int Paiment_Valide = ui->Paiment_Valide->text().toInt();
    QString mode_Livraison = ui->mode_Livraison->text();
    QDate date_Commande = ui->date_Commande->date();
    Commande C(idCommande, num_Tel, quantity, Paiment_Valide, mode_Livraison, date_Commande);
    bool test = C.ajouterCommande();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                                 QObject::tr("Commande ajouté.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
        ui->view->setModel(C.afficherCommande());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
    ui->idCommande->clear();
    ui->num_Tel->clear();
    ui->quantity->clear();
    ui->Paiment_Valide->clear();
    ui->mode_Livraison->clear();
    ui->date_Commande->clear();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Commande C1;
    C1.setIdCommande(ui->supp->text().toInt());
    bool test = C1.supprimerCommande(C1.getIdCommande());

    if (test)

    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un Commande"),
                                 QObject::tr("Commande supprimé.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
        ui->view->setModel(C.afficherCommande());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Commande"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
    ui->supp->clear();
}

void MainWindow::on_cherchermodif_clicked()
{
    Commande C1;
    C1 = C1.supprimerCommande(ui->supp->text().toInt());

    if (C1.getNumTel() != 0)
    {

        ui->idCommande_3->setText(QString::number(C1.getIdCommande()));
        ui->num_Tel_3->setText(QString::number(C1.getNumTel()));
        ui->quantity_3->setText(QString::number(C1.getQuantity()));
        ui->Paiment_Valide_3->setText(QString::number(C1.getPaimentValide()));
        ui->mode_Livraison_3->setText(C1.getModeLivraison());
        ui->date_Commande_3->setDate(C1.getDateCommande());

        ui->view->setModel(C.afficherCommande());
    }
    else // introuvable
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                              QObject::tr("employee introuvable !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_valider_2_clicked()
{

    int idCommande = ui->idCommande_3->text().toInt();
    int num_Tel = ui->num_Tel_3->text().toInt();
    int quantity = ui->quantity_3->text().toInt();
    int Paiment_Valide = ui->Paiment_Valide_3->text().toInt();
    QString mode_Livraison = ui->mode_Livraison_3->text();
    QDate date_Commande = ui->date_Commande_3->date();
    Commande C(idCommande, num_Tel, quantity, Paiment_Valide, mode_Livraison, date_Commande);

    Commande E1;
    int test = E1.userExists(idCommande);

    if (test == true)
    {
        if (int test1 = E1.modifier_Commande(idCommande, num_Tel, quantity, Paiment_Valide, mode_Livraison, date_Commande) == true)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un Commande"),
                                     QObject::tr("Commande modifié.\n"
                                                 "Click Cancel to exit."),
                                     QMessageBox::Cancel);
            ui->view->setModel(E1.afficherCommande());
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
