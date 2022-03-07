#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_client->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id_client=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    /*int nb_points=ui->nbpts->text().toInt();
    QString cadeau_client=ui->cadeau_client->text();
    QString classe=ui->classe->text();*/

    client c(id_client,nom,prenom,0,"c","rien");



bool test=c.ajouter_client();
QMessageBox msgBox;
if(test)
   { msgBox.setText("ajout avec success !");
ui->tab_client->setModel(c.afficher());

}
else
msgBox.setText("ajout échoué !");
msgBox.exec();


}





void MainWindow::on_pb_supprimer_clicked()
{

client c1;
c1.setid(ui->id_supp->text().toInt());

bool test=c1.supprimer(c1.getid());

QMessageBox msgBox;
if(test)
   { msgBox.setText("suppression avec success !");
ui->tab_client->setModel(c1.afficher());

}
else
msgBox.setText("suppression echouée !");
msgBox.exec();
}





////button chercher tee tableau modifier//
void MainWindow::on_pb_chercher_client_clicked()
{  client c1;

  c1=c1.chercher_client(ui->id_chercher->text().toInt());


     if(c1.getnom()!= "vide")
   {

       ui->id_client->setText( QString::number(c1.getid()) ) ;
       ui->id_nom->setText( c1.getnom() ) ;
       ui->id_prenom->setText( c1.getprenom() ) ;
       ui->id_nbpts->setText( QString::number(c1.getnb_points()) ) ;
       ui->id_cadeau->setText(c1.getcadeau_client());
      ui->id_classe->setText(c1.getclasse());

ui->tab_client->setModel(c1.afficher());

   }
     else //introuvable
     {
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                     QObject::tr("employee introuvable !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }

}







void MainWindow::on_pb_modifier_clicked()
{
    int id_client=ui->id_client->text().toInt();
    QString nom=ui->id_nom->text();
    QString prenom=ui->id_prenom->text();
    int  nbpts=ui->id_nbpts->text().toInt();
    QString cadeau_cl=ui->id_cadeau->text();
    QString classe=ui->id_classe->text();

    client c1;
    int test=c1.chercher_client_bool(id_client);

    if(test==true)
    {
        if(c1.modifier_client(id_client,nom,prenom,nbpts,classe,cadeau_cl) == true)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                              QObject::tr("client modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_client->setModel(c1.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un modifé"),
                        QObject::tr("Erreur de modification !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

    }
}





////button chercher tee tableau afficher//
void MainWindow::on_pb_chercher_client_aff_clicked()
{
    client c1;



        c1=c1.chercher_client(ui->id_chercher->text().toInt());





         if(c1.getnom()!= "vide")
       {

           ui->id_client->setText( QString::number(c1.getid()) ) ;
           ui->id_nom->setText( c1.getnom() ) ;
           ui->id_prenom->setText( c1.getprenom() ) ;
           ui->id_nbpts->setText( QString::number(c1.getnb_points()) ) ;
           ui->id_cadeau->setText(c1.getcadeau_client());
          ui->id_classe->setText(c1.getclasse());

    ui->tab_client->setModel(c1.afficher());

       }
         else //introuvable
         {
             QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                         QObject::tr("employee introuvable !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }



}









////////buttons tee tri////////
void MainWindow::on_radio_nom_clicked()
{client c1;
   ui->tab_client->setModel(c1.trier_nom());
}


void MainWindow::on_radio_prenom_clicked()
{
    client c1;
       ui->tab_client->setModel(c1.trier_prenom());
}



void MainWindow::on_radio_nb_pts_clicked()
{
    client c1;
       ui->tab_client->setModel(c1.trier_nb_pts());
}


