#include "home.h"
#include "ui_home.h"
#include "employee.h"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QIntValidator>
#include <QValidator>
home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
        ui->le_matricule_3->setValidator(new QIntValidator(0,999999,this));
        ui->le_salaire_3->setValidator(new QIntValidator(0,999999,this));
        QRegExp rx("[a-zA-Z]+");
        QValidator *validator = new QRegExpValidator(rx, this);


        ui->le_nom_3->setValidator(validator);
        ui->le_prenom_3->setValidator(validator);
       /*QRegExp emailT("^[A-Z0-9a-z._-]{1,}@(\\w+)(\\.(\\w+))(\\.(\\w+))?(\\.(\\w+))?$");
        QValidator *validateur = new QRegExpValidator(emailT, this);


        ui->le_e_mail->setValidator(validateur);*/
        ui->le_salaire_3->setValidator(new QIntValidator(0,999999,this));
        QRegExp expEmail("\\b[a-zA-Z0-9.%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,4}\\b");
                  QRegExpValidator *valEmail =new QRegExpValidator(expEmail,this);
                  ui->le_e_mail_3->setValidator(valEmail);
                  Employee E;
        ui->tab_employee_2->setModel(E.afficher(0));
         ui->tablearchive->setModel(E.afficherarchive());
}

home::~home()
{
    delete ui;
}

void home::on_pb_ajouter_2_clicked()
{
    if( ui->le_matricule_3->text().isEmpty() || ui->le_nom_3->text().isEmpty()|| ui->le_prenom_3->text().isEmpty()|| ui->le_e_mail_3->text().isEmpty()|| ui->le_mot_de_passe_3->text().isEmpty()|| ui->le_salaire_3->text().isEmpty()  )
           {
               QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                    QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
           }
           else{


        int matricule=ui->le_matricule_3->text().toInt();
        QString nom=ui->le_nom_3->text();
        QString prenom=ui->le_prenom_3->text();
        QString e_mail=ui->le_e_mail_3->text();
        QString mot_de_passe=ui->le_mot_de_passe_3->text();
        QDate date_embauche=ui->le_date_embauche_3->date();
        int salaire=ui->le_salaire_3->text().toInt();
        int code;
        Employee E;
        do{
        srand((unsigned)time(0));
             code = (rand()%999999)+1;
}while(E.cherchercode(code)!=-1);
        if(ui->le_e_mail_3->text().contains(QRegExp("\\b[a-zA-Z0-9.%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,4}\\b")))
        {
        Employee E(matricule,nom,prenom,e_mail,date_embauche,salaire,mot_de_passe,code);
        bool test=E.ajouter();
        if(test)
      {
      QMessageBox::information(nullptr, QObject::tr("Ajouter un employee"),
                        QObject::tr("employee ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_employee_2->setModel(E.afficher(0));
     ui->tablearchive->setModel(E.afficherarchive());
      }}
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ajouter un employee"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        }





}

void home::on_pb_supprimer_2_clicked()
{
    Employee E1;
        E1.setmatricule(ui->le_matricule_supp_2->text().toInt());
        bool test=E1.supprimerdefinitif(E1.getmatricule());
      ui->tablearchive->setModel(E1.afficherarchive());
        if(test)
      {
      QMessageBox::information(nullptr, QObject::tr("supprimer un employee"),
                        QObject::tr("Employee supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
      Employee E;
    ui->tab_employee_2->setModel(E.afficher(0)); //refresh
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                        QObject::tr("employee introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        ui->le_matricule_supp_2->clear();
}


 void home::on_pb_modifier_4_clicked()
{
    int matricule=ui->le_matricule_4->text().toInt();
        QString nom=ui->le_nom_4->text();
        QString prenom=ui->le_prenom_4->text();
        QString e_mail=ui->le_e_mail_4->text();
        QString mot_de_passe=ui->le_mot_de_passe_4->text();
        QDate date_embauche=ui->le_date_embauche_4->date();
        int salaire=ui->le_salaire_4->text().toInt();
       int code=ui->le_code->text().toInt();
        Employee E(matricule,nom,prenom,e_mail,date_embauche,salaire,mot_de_passe,code);

    Employee E1;
    int test=E1.userExists(matricule);
    if(test==true)
    {
        if(int test1=E1.modifier(matricule,nom,prenom,e_mail,date_embauche,salaire,mot_de_passe,code)==true){
            QMessageBox::information(nullptr, QObject::tr("modifier un employee"),
                              QObject::tr("employee modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tab_employee_2->setModel(E.afficher(0));

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un employee"),
                        QObject::tr("Erreur de modification!.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

    }

        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un employee"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
}


void home::on_pb_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from employee where salaire >= 1000");
       float dispo1=model->rowCount();

       model->setQuery("select * from employee where salaire <1000");
       float dispo=model->rowCount();

       float total=dispo1+dispo;
           QString a=QString("Cadre . " +QString::number((dispo1*100)/total,'f',2)+"%" );
           QString b=QString("employee .  "+QString::number((dispo*100)/total,'f',2)+"%" );
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
       chart->setTitle("Salaire des employes :Nb employes: "+ QString::number(total));



       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->resize(1000,500);
       chartView->show();

}

void home::on_pb_modifier_3_clicked()
{
    Employee E1;
            E1=E1.chercher(ui->le_matriculeM_2->text().toInt());

            if(E1.getnom()!="vide")
          {

              ui->le_matricule_4->setText( QString::number(E1.getmatricule()) ) ;
              ui->le_nom_4->setText( E1.getnom() ) ;
              ui->le_prenom_4->setText( E1.getprenom() ) ;
              ui->le_e_mail_4->setText(E1.gete_mail());
             ui->le_mot_de_passe_4->setText(E1.getmot_de_passe());
             ui->le_date_embauche_4->setDate(E1.getdate_embauche());
            ui->le_salaire_4->setText( QString::number(E1.getsalaire()));
             ui->le_code->setText( QString::number(E1.getcode()));

   ui->tab_employee_2->setModel(E1.afficher(0));
          }
            else //introuvable
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher Employee"),
                            QObject::tr("employee introuvable !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
}



void home::on_restaurer_clicked()
{
    Employee E1;
        E1.setmatricule(ui->le_restaurer->text().toInt());
        bool test=E1.supprimerarchive(E1.getmatricule());
      ui->tablearchive->setModel(E1.afficherarchive());
        if(test)
      {
      QMessageBox::information(nullptr, QObject::tr("restaurer un employee"),
                        QObject::tr("Employee restauré.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
      Employee E;
    ui->tab_employee_2->setModel(E.afficher(0)); //refresh
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("restaurer un employee"),
                        QObject::tr("employee introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        ui->le_matricule_supp_2->clear();
}

void home::on_radioButton_clicked()
{
    Employee E;
     ui->tab_employee_2->setModel(E.afficher(1));
}

void home::on_radioButton_2_clicked()
{
    Employee E;
     ui->tab_employee_2->setModel(E.afficher(2));
}

void home::on_radioButton_3_clicked()
{
    Employee E;
     ui->tab_employee_2->setModel(E.afficher(3));
}

void home::on_radioButton_4_clicked()
{
    Employee E;
     ui->tab_employee_2->setModel(E.afficher(4));
}

void home::on_pb_supprimer_3_clicked()
{
    Employee E1;
        E1.setmatricule(ui->le_matricule_supp_3->text().toInt());
        bool test=E1.supprimer(E1.getmatricule());
      ui->tablearchive->setModel(E1.afficherarchive());
        if(test)
      {
      QMessageBox::information(nullptr, QObject::tr("archiver un employee"),
                        QObject::tr("Employee archivé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
      Employee E;
    ui->tab_employee_2->setModel(E.afficher(0)); //refresh
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("archiver un employee"),
                        QObject::tr("employee introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        ui->le_matricule_supp_3->clear();
}



void home::on_reset_ajouter_3_clicked()
{
    ui->le_matricule_3->clear();
    ui->le_nom_3->clear();
    ui->le_prenom_3->clear();
    ui->le_e_mail_3->clear();
    ui->le_mot_de_passe_3->clear();
    ui->le_date_embauche_3->clear();
    ui->le_salaire_3->clear();
}
