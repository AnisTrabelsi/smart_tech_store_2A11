#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Commande.h"
#include "Commande.cpp"
#include "livraison.h"
#include "civraison.h"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->num_Tel->setValidator(new QIntValidator(11111111,99999999,this));
    ui->quantity->setValidator(new QIntValidator(0,99999999,this));
    ui->Paiment_Valide->setValidator(new QIntValidator(0,99999999,this));
    ui->idCommande->setValidator(new QIntValidator(0,99999999,this));
    ui->view->setModel(C.afficherCommande(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NUM_clicked()
{
   ui->view->setModel(C.afficherCommande(1));
}
   void MainWindow::on_PAIMENT_clicked()
   {
      ui->view->setModel(C.afficherCommande(2));
   }
      void MainWindow::on_ID_clicked()
      {
         ui->view->setModel(C.afficherCommande(3));
      }
void MainWindow::on_valider_clicked()
{
    Livraison L(nullptr);
    if( ui->idCommande->text().isEmpty() || ui->date_Commande->text().isEmpty() || ui->num_Tel->text().isEmpty() || ui->quantity->text().isEmpty() || ui->Paiment_Valide->text().isEmpty()|| ui->mode_Livraison->text().isEmpty()  )
               {
                   QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
               }
    else {
    int idCommande = ui->idCommande->text().toInt();
    QDate date_Commande = ui->date_Commande->date();
    int num_Tel = ui->num_Tel->text().toInt();
    int quantity = ui->quantity->text().toInt();
    int Paiment_Valide = ui->Paiment_Valide->text().toInt();
    QString mode_Livraison = ui->mode_Livraison->text();
    if(mode_Livraison=="LIVRAISON")
    {

        L.show();
        L.exec();


    }
    Commande C(idCommande, num_Tel, quantity, Paiment_Valide, mode_Livraison, date_Commande);
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
        ui->view->setModel(C.afficherCommande(0));
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
    C1 = C1.chercher_Commande(ui->idmodif->text().toInt());

    if (C1.getIdCommande() != 0)
    {

        ui->idCommande_3->setText(QString::number(C1.getIdCommande()));
        ui->num_Tel_3->setText(QString::number(C1.getNumTel()));
        ui->quantity_3->setText(QString::number(C1.getQuantity()));
        ui->Paiment_Valide_3->setText(QString::number(C1.getPaimentValide()));
        ui->mode_Livraison_3->setText(C1.getModeLivraison());
        ui->date_Commande_3->setDate(C1.getDateCommande());

        ui->view->setModel(C.afficherCommande(0));
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


    int idCommande = ui->idCommande_3->text().toInt();
    int num_Tel = ui->num_Tel_3->text().toInt();
    int quantity = ui->quantity_3->text().toInt();
    int Paiment_Valide = ui->Paiment_Valide_3->text().toInt();
    QString mode_Livraison = ui->mode_Livraison_3->text();
    QDate date_Commande = ui->date_Commande_3->date();
    Commande C(idCommande, num_Tel, quantity, Paiment_Valide, mode_Livraison, date_Commande);

    Commande E1;
    int test = E1.CommandeExists(idCommande);

    if (test == true)
    {
        if (int test1 = E1.modifier_Commande(idCommande, num_Tel, quantity, Paiment_Valide, mode_Livraison, date_Commande) == true)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un Commande"),
                                     QObject::tr("Commande modifié.\n"
                                                 "Click Cancel to exit."),
                                     QMessageBox::Cancel);
            ui->view->setModel(E1.afficherCommande(0));
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
void MainWindow::on_pushButton_clicked()
{

        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from COMMANDE WHERE MODE_LIVRAISON='BOUTIQUE'");
        float dispo1=model->rowCount();

       model->setQuery("select * from COMMANDE WHERE MODE_LIVRAISON='LIVRAISON'");
        float dispo=model->rowCount();

        float total=dispo1+dispo;
            QString a=QString("Boutique . " +QString::number((dispo1*100)/total,'f',2)+"%" );
            QString b=QString("Livraison .  "+QString::number((dispo*100)/total,'f',2)+"%" );
            QPieSeries *series = new QPieSeries();
            series->append(a,dispo1);
            series->append(b,dispo);
        if (dispo1!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( dispo!=0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();


        chart->addSeries(series);
        chart->setTitle("Pourcentages de mode livraison de nos clients "+ QString::number(total));
        chart->legend()->hide();


        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}


