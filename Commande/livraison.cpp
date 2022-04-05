#include "livraison.h"
#include "ui_livraison.h"
#include "civraison.h"
#include "civraison.cpp"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>

Livraison::Livraison(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Livraison)
{
    ui->setupUi(this);
}

Livraison::~Livraison()
{
    delete ui;
}

void Livraison::on_valider_clicked()
{
    if( ui->idLivraison->text().isEmpty() || ui->date->text().isEmpty() || ui->num_Tel->text().isEmpty() || ui->quantity->text().isEmpty() || ui->Paiment_Valide->text().isEmpty()|| ui->mode_Livraison->text().isEmpty()  )
               {
                   QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
               }
    else {
    int idlivraison = ui->idLivraison->text().toInt();
    int code_postal = ui->code_postal->text().toInt();
    QString Region = ui->Region->text();
    QString Ville = ui->Ville->text();
    QDate date_livraison = ui->date_livraison->date();
    CCIVRAISONnum_Tel, quantity, Paiment_Valide, mode_Livraison, date_Commande);
    bool test = C.ajouterCommande();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                                 QObject::tr("Commande ajouté.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
        ui->view->setModel(C.afficherCommande(0));
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
    }
    ui->idCommande->clear();
    ui->num_Tel->clear();
    ui->quantity->clear();
    ui->Paiment_Valide->clear();
    ui->mode_Livraison->clear();
    ui->date_Commande->clear();

}
