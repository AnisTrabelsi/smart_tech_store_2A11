#include "livraison.h"
#include "ui_livraison.h"
#include "civraison.h"
#include "civraison.cpp"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>

Livraison::Livraison(QWidget *parent) :
    QDialog(parent),
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
    if( ui->idLivraison->text().isEmpty() || ui->date_Livraison->text().isEmpty() || ui->Code->text().isEmpty() || ui->Region->text().isEmpty())
               {
                   QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
               }
    else {
    int idlivraison = ui->idLivraison->text().toInt();
    int code_postal = ui->Code->text().toInt();
    QString Region = ui->Region->text();
    QString ville;
       if(ui->ville->currentIndex()==0)
         ville="Tunis";
       else if (ui->ville->currentIndex()==1)
              {
               ville="Bizerte";}
           else if (ui->ville->currentIndex()==2)
                        {
                         ville="Sousse";}
       else if (ui->ville->currentIndex()==3)
                    {
                     ville="Kairouan";}
       else if (ui->ville->currentIndex()==4)
                    {
                     ville="Sfax";}
       else if (ui->ville->currentIndex()==5)
                    {
                     ville="Beja";}
       else if (ui->ville->currentIndex()==6)
                    {
                     ville="Jerba";}

    QDate date_livraison = ui->date_Livraison->date();
    CIVRAISON(idlivraison,code_postal,Region,ville,date_livraison);
    bool test2 = CI.ajouterLivraison();

    if (test2)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                                 QObject::tr("Commande ajouté.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
        ui->idLivraison->clear();
        ui->Code->clear();
        ui->ville->clear();
        ui->Region->clear();
        ui->date_Livraison->clear();
        this->hide();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
    }



}
