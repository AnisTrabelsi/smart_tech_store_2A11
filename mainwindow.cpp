#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include "fournisseur.h"
 #include "reclamation.h"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator> //controle saisie
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
ui->idfournisseur->setValidator(new QIntValidator (0, 99999, this));
ui->idfournisseur_2->setValidator(new QIntValidator (0, 99999, this));
ui->view->setModel(F.afficher());
ui->view_2->setModel(R.afficher());


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valider_clicked()
{
    int idfournisseur=ui->idfournisseur->text().toInt();
  QString nom=ui->nom->text();
  QDate dateajout=ui->dateajout->date();
  QDate dateexpr=ui->dateexpr->date();
  QString description=ui->description->text();
  Fournisseur F(idfournisseur,nom,dateajout,dateexpr,description);
  bool test=F.ajouter();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher());
    }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      ui->idfournisseur->clear();
      ui->nom->clear();
      ui->dateajout->clear();
       ui->dateexpr->clear();
        ui->description->clear();


}



void MainWindow::on_pb_supprimer_clicked()
{
   Fournisseur F1; F1.setid(ui->supp->text().toInt());
        bool test=F1.supprimer(F1.getid());

        if(test)

      {
      QMessageBox::information(nullptr, QObject::tr("supprimer un fournisseur"),
                        QObject::tr("fournisseur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher());
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        ui->supp->clear();


}

void MainWindow::on_cherchermodif_clicked()
{
    Fournisseur E1;
        E1=E1.chercher(ui->idmodif->text().toInt());

        if(E1.getnom()!="vide")
      {

          ui->idfournisseur_2->setText( QString::number(E1.getid()) ) ;
          ui->nom_2->setText( E1.getnom() ) ;
          ui->dateajout_2->setDate( E1.getdateajout() ) ;
          ui->dateexpr_2->setDate(E1.getdateexpr());
         ui->description_2->setText(E1.getdescription());

ui->view->setModel(F.afficher());
      }
        else //introuvable
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                        QObject::tr("employee introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

}

void MainWindow::on_valider_2_clicked()
{
    int idfournisseur=ui->idfournisseur_2->text().toInt();
    QString nom=ui->nom_2->text();
    QDate dateajout=ui->dateajout_2->date();
    QDate dateexpr=ui->dateexpr_2->date();
    QString description=ui->description_2->text();
     Fournisseur F(idfournisseur,nom,dateajout,dateexpr,description);

    Fournisseur E1;
    int test=E1.userExists(idfournisseur);

    if(test==true)
    {
        if(int test1=E1.modifier(idfournisseur,nom,dateajout,dateexpr,description)==true){
            QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                              QObject::tr("fournisseur modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
       ui->view->setModel(F.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un modifé"),
                        QObject::tr("Erreur de modification!.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

    }

        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
}


void MainWindow::on_pushButton_clicked()
{
   ui->viewt->setModel(F.trier());
}

void MainWindow::on_valider_3_clicked()
{

    int idreclamation=ui->idreclamation->text().toInt();
  QDate datereclamation=ui->datereclamation->date();
  QString description=ui->descriptionr->text();
     int idfournisseur=ui->idf->text().toInt();
  reclamation F(idreclamation,datereclamation,description,idfournisseur);
  bool test=F.ajouter();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->view_2->setModel(R.afficher());
    }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      ui->idreclamation->clear();

      ui->datereclamation->clear();
       ui->descriptionr->clear();
        ui->idf->clear();


}

void MainWindow::on_act_clicked()
{
    Fournisseur F;
    int idfournisseur=F.cherchersys();
   bool test=F.supprimersys();
   if(test)
 {
 QMessageBox::information(nullptr, QObject::tr("suppresion jawha fesfes un equipement"),
                   QObject::tr("fournisseur ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher());
 }
   else
   {
       QMessageBox::critical(nullptr, QObject::tr("mchina un equipement"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
}
