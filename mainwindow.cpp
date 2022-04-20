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
ui->idreclamation->setValidator(new QIntValidator (0, 99999, this));
ui->idf->setValidator(new QIntValidator (0, 99999, this));
ui->idfournisseur_2->setValidator(new QIntValidator (0, 99999, this));
ui->view->setModel(F.afficher(0));
ui->view_2->setModel(R.afficher());
ui->archive->setModel(F.afficherarchive());


Fournisseur F;
bool test=F.supprimersys();
if(test)
{
ui->view->setModel(F.afficher(0));
}
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valider_clicked()
{
    if( ui->idfournisseur->text().isEmpty() ||  ui->nom->text().isEmpty() || ui->dateajout->text().isEmpty()|| ui->dateexpr->text().isEmpty()|| ui->description->text().isEmpty()  )
               {
                   QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
               }
               else{

    int idfournisseur=ui->idfournisseur->text().toInt();
  QString nom=ui->nom->text();
  QDate dateajout=ui->dateajout->date();
  QDate dateexpr=ui->dateexpr->date();
  QString description=ui->description->text();
  Fournisseur F(idfournisseur,nom,dateajout,dateexpr,description);
  bool test=F.ajouter();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher(0));
    }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      ui->idfournisseur->clear();
      ui->nom->clear();
      ui->dateajout->clear();
       ui->dateexpr->clear();
        ui->description->clear();

}
}



void MainWindow::on_pb_supprimer_clicked()
{
   Fournisseur f1; f1.setid(ui->supp->text().toInt());
        bool test=f1.archiver(f1.getid());

        if(test)

      {
      QMessageBox::information(nullptr, QObject::tr("archiver un fournisseur"),
                        QObject::tr("fournisseur archivé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher(0));
ui->archive->setModel(F.afficherarchive());
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("archiver un fournisseur"),
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

ui->view->setModel(F.afficher(0));
      }
        else //introuvable
        {
            QMessageBox::critical(nullptr, QObject::tr("chercher fournisseur"),
                        QObject::tr("fournisseur introuvable !.\n"
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
       ui->view->setModel(F.afficher(0));
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
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



void MainWindow::on_valider_3_clicked()
{
    if( ui->idreclamation->text().isEmpty() ||  ui->datereclamation->text().isEmpty() || ui->descriptionr->text().isEmpty()|| ui->idf->text().isEmpty()  )
               {
                   QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
               }
               else{
    int idreclamation=ui->idreclamation->text().toInt();
  QDate datereclamation=ui->datereclamation->date();
  QString description=ui->descriptionr->text();
     int idfournisseur=ui->idf->text().toInt();
  reclamation F(idreclamation,datereclamation,description,idfournisseur);
  bool test=F.ajouter();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                      QObject::tr("reclamation ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->view_2->setModel(R.afficher());
    }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une reclamation"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      ui->idreclamation->clear();

      ui->datereclamation->clear();
       ui->descriptionr->clear();
        ui->idf->clear();

}
}

void MainWindow::on_act_clicked()
{
   Fournisseur F;
   bool test=F.supprimersys();
   if(test)
 {
 QMessageBox::information(nullptr, QObject::tr("check"),
                   QObject::tr("check done.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher(0));
 }
   else
   {
       QMessageBox::critical(nullptr, QObject::tr("check"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->view->setModel(F.afficher(1));
}

void MainWindow::on_radioButton_clicked()
{
ui->view->setModel(F.afficher(2));
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->view->setModel(F.afficher(3));
}

void MainWindow::on_pb_supprimer_3_clicked()
{
    Fournisseur f1; f1.setid(ui->supp_3->text().toInt());
         bool test=f1.supprimer(f1.getid());

         if(test)

       {
       QMessageBox::information(nullptr, QObject::tr("supprimer un fournisseur"),
                         QObject::tr("fournisseur supprimé.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
 ui->archive->setModel(F.afficherarchive());
       }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         ui->supp->clear();


}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from fournisseur WHERE to_date(dateajout,'dd-mm-yy')>=to_date('01-01-10','dd-mm-yy')");
            float dispo1=model->rowCount();

            model->setQuery("select * from fournisseur WHERE to_date(dateajout,'dd-mm-yy')<to_date('01-01-10','dd-mm-yy')");
            float dispo=model->rowCount();

            float total=dispo1+dispo;
                QString a=QString("apres 2010 . " +QString::number((dispo1*100)/total,'f',2)+"%" );
                QString b=QString("avant 2010 .  "+QString::number((dispo*100)/total,'f',2)+"%" );
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
            chart->setTitle("nombre total des fournisseurs : "+ QString::number(total));



            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();
}

/*void MainWindow::on_pb_supprimer_4_clicked()
{
    Fournisseur F1;
            F1.setid(ui->supp_4->text().toInt());
            bool test=F1.restore(F1.getid());
          ui->archive->setModel(F1.afficherarchive());
            if(test)
          {
          QMessageBox::information(nullptr, QObject::tr("restaurer un fournisseur"),
                            QObject::tr("fournisseur restauré.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
          Fournisseur E;
        ui->view->setModel(E.afficher(0)); //refresh
          }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("restaurer un fournisseur"),
                            QObject::tr("fournisseur introuvable !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            ui->supp_4->clear();
}*/



void MainWindow::on_reset_ajouter_3_clicked()
{
    ui->idreclamation->clear();

    ui->datereclamation->clear();
     ui->descriptionr->clear();
      ui->idf->clear();
}

void MainWindow::on_reset_ajouter_2_clicked()
{
    ui->idfournisseur->clear();
    ui->nom->clear();
    ui->dateajout->clear();
     ui->dateexpr->clear();
      ui->description->clear();
}

void MainWindow::on_pb_supprimer_5_clicked()
{
    reclamation F1;
            F1.setid(ui->supp_5->text().toInt());
            bool test=F1.supprimer(F1.getid());
          ui->view_2->setModel(F1.afficher());
            if(test)
          {
          QMessageBox::information(nullptr, QObject::tr("supprimer une reclamation"),
                            QObject::tr("reclamation supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
          reclamation E;
        ui->view_2->setModel(E.afficher()); //refresh
          }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("supprimer une reclamation"),
                            QObject::tr("reclamation introuvable !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            ui->supp_5->clear();
}
