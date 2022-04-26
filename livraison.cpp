#include "livraison.h"
#include "ui_livraison.h"
#include "civraison.h"
#include "civraison.cpp"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
#include "map.h"

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
    QString Ville;
       if(ui->ville->currentIndex()==0)
         Ville="Tunis";
       else if (ui->ville->currentIndex()==1)
              {
               Ville="Bizerte";}
           else if (ui->ville->currentIndex()==2)
                        {
                         Ville="Sousse";}
       else if (ui->ville->currentIndex()==3)
                    {
                     Ville="Kairouan";}
       else if (ui->ville->currentIndex()==4)
                    {
                     Ville="Sfax";}
       else if (ui->ville->currentIndex()==5)
                    {
                     Ville="Beja";}
       else if (ui->ville->currentIndex()==6)
                    {
                     Ville="Djerba";}

    QDate date_livraison = ui->date_Livraison->date();
    if(Ville=="Tunis")
    {
        Map m(nullptr,0);

        m.exec();
    }
    else if(Ville=="Bizerte")
    {
        Map m(nullptr,1);

        m.exec();

    }
    else if(Ville=="Sousse")
    {
        Map m(nullptr,2);

        m.exec();

    }
    else if(Ville=="Kairouan")
    {
        Map m(nullptr,3);

        m.exec();

    }
    else if(Ville=="Sfax")
    {
        Map m(nullptr,4);

        m.exec();

    }
    else if(Ville=="Beja")
    {
        Map m(nullptr,5);

        m.exec();

    }
    else if(Ville=="Djerba")
    {
        Map m(nullptr,6);
        m.exec();

    }

    CIVRAISON CI(idlivraison,code_postal,Region,Ville,date_livraison);
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
