#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_matricule->setValidator(new QIntValidator(0,999999,this));
    ui->le_salaire->setValidator(new QIntValidator(0,999999,this));
    ui->tab_employee->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int matricule=ui->le_matricule->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString e_mail=ui->le_e_mail->text();
    QString mot_de_passe=ui->le_mot_de_passe->text();
    QDate date_embauche=ui->le_date_embauche->date();
    int salaire=ui->le_salaire->text().toInt();
    Employee E(matricule,nom,prenom,e_mail,date_embauche,salaire,mot_de_passe);


    bool test=E.ajouter();
    if(test)
  {
  QMessageBox::information(nullptr, QObject::tr("Ajouter un employee"),
                    QObject::tr("employee ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_employee->setModel(E.afficher());
  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->le_matricule->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_e_mail->clear();
    ui->le_mot_de_passe->clear();
    ui->le_date_embauche->clear();
    ui->le_salaire->clear();
}


void MainWindow::on_pb_supprimer_clicked()
{
    Employee E1;
    E1.setmatricule(ui->le_matricule_supp->text().toInt());
    bool test=E1.supprimer(E1.getmatricule());

    if(test)
  {
  QMessageBox::information(nullptr, QObject::tr("supprimer un employee"),
                    QObject::tr("Employee supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_employee->setModel(E.afficher()); //refresh
  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                    QObject::tr("employee introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->le_matricule_supp->clear();

}






void MainWindow::on_pb_modifier_clicked()
{

    Employee E1;
    E1=E1.chercher(ui->le_matriculeM->text().toInt());

    if(E1.getnom()!="vide") //employe trouvé
  {

      ui->le_matricule_2->setText( QString::number(E1.getmatricule()) ) ;
      ui->le_nom_2->setText( E1.getnom() ) ;
      ui->le_prenom_2->setText( E1.getprenom() ) ;
      ui->le_e_mail_2->setText(E1.gete_mail());
     ui->le_date_embauche_2->setDate(E1.getdate_embauche());
      ui->le_salaire_2->setText( QString::number(E1.getsalaire()) ) ;
      ui->le_mot_de_passe_2->setText(E1.getmot_de_passe());

ui->tab_employee->setModel(E.afficher()); //refresh
  }
    else //introuvable
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                    QObject::tr("employee introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->le_matricule_supp->clear();
}



void MainWindow::on_pb_modifier_2_clicked()
{
    int matricule=ui->le_matricule_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString e_mail=ui->le_e_mail_2->text();
    QString mot_de_passe=ui->le_mot_de_passe_2->text();
    QDate date_embauche=ui->le_date_embauche_2->date();
    int salaire=ui->le_salaire_2->text().toInt();
    Employee E(matricule,nom,prenom,e_mail,date_embauche,salaire,mot_de_passe);

Employee E1;
int test=E1.userExists(matricule);
if(test==true)
{
    if(int test1=E1.modifier(matricule,nom,prenom,e_mail,date_embauche,salaire,mot_de_passe)==true){
        QMessageBox::information(nullptr, QObject::tr("modifier un employee"),
                          QObject::tr("employee modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_employee->setModel(E.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
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
