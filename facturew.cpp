#include "facturew.h"
#include "ui_facturew.h"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QIntValidator>
#include <QValidator>
#include "menu.h"
factureW::factureW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::factureW)
{

    ui->setupUi(this);
    ui->TVA_A->setValidator(new QIntValidator(0,99,this));
    ui->tab_facture->setModel(F.afficherho("facture",0));
    ui->archive_table->setModel(F.afficherho("ARCHIVE_TABLE",0));


//ui->dateajout_A->setda;

    ui->tttva_A->setValidator(new QIntValidator(0,9999999,this));
 ui->totalht_A->setValidator(new QIntValidator(0,9999999,this));
ui->ttttc_A->setValidator(new QIntValidator(0,9999999,this));
ui->remise_A->setValidator(new QIntValidator(0,99,this));

QDate date = QDate::currentDate();
   ui->dateajout_A->setDate(date);




}

factureW::~factureW()
{
    delete ui;
}


void factureW::on_pb_ajouter_clicked()
{   int nfacture=ui->remise_A->text().toInt();
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

 ui->tab_facture->setModel(F.afficherho("facture",0));
}






void factureW::on_pb_modifier_clicked()
{


    facture f1;
    f1=f1.chercher(ui->nfacture_MM->text().toInt(),"FACTURE");

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

void factureW::on_pb_modifier_2_clicked()
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
    ui->tab_facture->setModel(F.afficherho("facture",0));
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

void factureW::on_matricule_A_editingFinished()
{





}

void factureW::on_pushButton_clicked()
{
    //ui->tab_facture_2->setModel(F.trier());

}

void factureW::on_recuperer_clicked()
{
    facture f1;
    f1.set_nfacture(ui->nfacture_R->text().toInt());

    bool test=f1.supprimer(f1.get_nfacture(),"FACTURE_ARCHIVE");

    if(test)

  {
  QMessageBox::information(nullptr, QObject::tr("supprimer une facture"),
                    QObject::tr("facture supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_facture->setModel(F.afficherho("facture",0));
ui->archive_table->setModel(F.afficherho("ARCHIVE_TABLE",0));

ui->nfacture_S->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une facture"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }



}
void factureW::on_pb_supprimer_clicked()
{
   facture f1;
   f1.set_nfacture(ui->nfacture_S->text().toInt());


   bool test=f1.supprimer(f1.get_nfacture(),"FACTURE");

        if(test)

      {
      QMessageBox::information(nullptr, QObject::tr("supprimer un fournisseur"),
                        QObject::tr("fournisseur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_facture->setModel(F.afficherho("facture",0));
ui->archive_table->setModel(F.afficherho("ARCHIVE_TABLE",0));

ui->nfacture_S->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }}

void factureW::on_pb_modifier_3_clicked()
{facture f1;

    f1.set_nfacture(ui->nfacture_MM->text().toInt());

    f1.imprimer(ui->idcommande_M->text().toInt());
}

void factureW::on_pushButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from facture WHERE total_ht>5000");
                float dispo1=model->rowCount();

                model->setQuery("select * from facture WHERE total_ht<5000");
                float dispo=model->rowCount();

                float total=dispo1+dispo;
                    QString a=QString("plus . " +QString::number((dispo1*100)/total,'f',2)+"%" );
                    QString b=QString("moins .  "+QString::number((dispo*100)/total,'f',2)+"%" );
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
               // chart->setTitle(""+ QString::number(total));
                chart->legend()->hide();


                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();
}



void factureW::on_radioButton_clicked()
{
    ui->tab_facture->setModel(F.afficherho("facture",0));

  }

void factureW::on_radioButton_2_clicked()
{
    ui->tab_facture->setModel(F.afficherho("facture",1));

}

void factureW::on_radioButton_3_clicked()
{
    ui->tab_facture->setModel(F.afficherho("facture",2));
}

void factureW::on_recuperer_2_clicked()
{

//ui->tabs->setModel(F.afficherho())

    ui->tabs->setModel(F.afficherpar(ui->nomr->text(),0));
}

void factureW::on_recuperer_3_clicked()
{
facture f;
f.regrouper(ui->nomr->text());
ui->tab_facture->setModel(F.afficherho("facture",0));
ui->archive_table->setModel(F.afficherho("ARCHIVE_TABLE",0));

}



void factureW::on_pb_ajouter_4_clicked()
{
    menu h(nullptr);

     this->hide();
     h.setModal(this);
     h.exec();
}

void factureW::on_idcommande_A_editingFinished()
{
    QSqlQueryModel* model;

 if(ui->idcommande_A->text()!=""){
     facture f;
     model=f.chercheravancer(ui->idcommande_A->text().toInt());
  ui->tableView->setModel(model);
 int n=f.numberofrows(ui->idcommande_A->text().toInt());
 int prixht=0;
 for (int i=0;i<n;++i) {
     prixht+=model->data(model->index(i,0,QModelIndex()),Qt::DisplayRole).toInt()*model->data(model->index(i,2,QModelIndex()),Qt::DisplayRole).toInt();



 }

 ui->totalht_A->setText(QString::number(prixht));



  }
}

void factureW::on_TVA_A_editingFinished()
{

    int prixht=ui->totalht_A->text().toInt();
    if(prixht!=0){

      ui->tttva_A->setText(QString::number((prixht*ui->TVA_A->text().toInt())/100));
ui->ttttc_A->setText(QString::number((prixht+ui->tttva_A->text().toInt())));


    }
}
