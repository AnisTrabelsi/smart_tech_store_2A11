#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
#include <facture.h>
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TVA_A->setValidator(new QIntValidator(0,99,this));
    ui->tab_facture->setModel(F.afficher());


    ui->tttva_A->setValidator(new QIntValidator(0,9999999,this));
 ui->totalht_A->setValidator(new QIntValidator(0,9999999,this));
ui->ttttc_A->setValidator(new QIntValidator(0,9999999,this));
ui->remise_A->setValidator(new QIntValidator(0,99,this));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{   int nfacture=7;
    int etat=ui->Etat_A->currentIndex();
    int tva=ui->TVA_A->text().toInt();
    int total_tva=ui->tttva_A->text().toInt();
    int total_ht=ui->totalht_A->text().toInt();
    int total_ttc=ui->ttttc_A->text().toInt();
    int modedereglement=ui->modedereglement_A->currentIndex();
    int remise=ui->remise_A->text().toInt();
    int matricule=ui->matricule_A->text().toInt();
    int id_commande=ui->idcommande_A->text().toInt();
    QDate datedecreation=ui->dateajout_A->date();
    QString remarque=ui->remarque_A->text();
facture F(nfacture,etat,tva,total_tva,total_ht,total_ttc,modedereglement,remise,matricule,id_commande,datedecreation,remarque);

bool test=F.ajouter();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    ui->Etat_A->clear();
    ui->TVA_A->clear();
    ui->tttva_A->clear();
    ui->totalht_A->clear();
    ui->ttttc_A->clear();
    ui->modedereglement_A->clear();
    ui->remise_A->clear();
    ui->matricule_A->clear();
    ui->idcommande_A->clear();
    ui->dateajout_A->clear();
    ui->remarque_A->clear();
    }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }

 ui->tab_facture->setModel(F.afficher());
}



void MainWindow::on_pb_supprimer_clicked()
{
   facture f1;
   f1.set_nfacture(ui->nfacture_S->text().toInt());
        bool test=f1.supprimer(f1.get_nfacture());

        if(test)

      {
      QMessageBox::information(nullptr, QObject::tr("supprimer un fournisseur"),
                        QObject::tr("fournisseur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_facture->setModel(F.afficher());
ui->nfacture_S->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }



}


void MainWindow::on_pb_modifier_clicked()
{


    facture f1;
    f1=f1.chercher(ui->nfacture_MM->text().toInt());

        if(f1.get_remarque()!="user not found")
      {


           ui->nfacture_MM->setText( QString::number(f1.get_nfacture()));
           ui->Etat_A->setCurrentIndex(f1.get_etat());
           ui->modedereglement_M->setCurrentIndex(f1.get_modedereglement());
           ui->dateajout_M->setDate( f1.get_datedecreation());
           ui->TVA_M->setText( QString::number(f1.get_tva()));
           ui->tttva_M->setText( QString::number(f1.get_total_tva()));
           ui->totalht_M->setText( QString::number(f1.get_total_ht()));
           ui->ttttc_M->setText( QString::number(f1.get_total_ttc()));
           ui->remise_M->setText( QString::number(f1.get_remise()));
           ui->matricule_M->setText( QString::number(f1.get_matricule()));
           ui->idcommande_M->setText( QString::number(f1.get_id_commande()));
           ui->remarque_M->setText(f1.get_remarque() );
           ui->client_M->setText(f1.get_nom());
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                        QObject::tr("employee introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }




}

void MainWindow::on_pb_modifier_2_clicked()
{
    int nfacture=ui->nfacture_MM->text().toInt();
    int etat=ui->Etat_M->currentIndex();
    int tva=ui->TVA_M->text().toInt();
    int total_tva=ui->tttva_M->text().toInt();
    int total_ht=ui->totalht_M->text().toInt();
    int total_ttc=ui->ttttc_M->text().toInt();
    int modedereglement=ui->modedereglement_M->currentIndex();
    int remise=ui->remise_M->text().toInt();
    int matricule=ui->matricule_M->text().toInt();
    int id_commande=ui->idcommande_M->text().toInt();
    QDate datedecreation=ui->dateajout_M->date();
    QString remarque=ui->remarque_M->text();
facture F(nfacture,etat,tva,total_tva,total_ht,total_ttc,modedereglement,remise,matricule,id_commande,datedecreation,remarque);


  facture F1;
  int test=F1.userExists(nfacture);

  if(test==true)
  {
      if(int test1=F1.modifier(nfacture,etat,tva,total_tva,total_ht,total_ttc,modedereglement,remise,matricule,id_commande,datedecreation,remarque)==true){
          QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                            QObject::tr("fournisseur modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_facture->setModel(F.afficher());
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

void MainWindow::on_matricule_A_editingFinished()
{
    
    
    
    
    
}

void MainWindow::on_pushButton_clicked()
{ui->tab_facture_2->setModel(F.trier());

}
