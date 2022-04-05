#include "mdp_oub.h"
#include "ui_mdp_oub.h"
#include "employee.h"
#include "mainwindow.h"
#include "home.h"
mdp_oub::mdp_oub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mdp_oub)
{
    ui->setupUi(this);
}

mdp_oub::~mdp_oub()
{
    delete ui;
}





void mdp_oub::on_pb_ajouter_2_clicked()
{
    Employee E;
    QString code;
    code=ui->le_code->text();
    int matricule =E.mdp_oub(code);
    if(matricule!=-1)
    {

     QMessageBox::information(this,"Connexion","employé trouvé");
     qDebug()<< "employé trouvé";

    }

   else
    {
      QMessageBox::critical(this,"Connexion","employé introuvable");
      qDebug()<< "employé introuvable";
    }
}

void mdp_oub::on_pb_ajouter_3_clicked()
{

    QString code=ui->le_code->text();
        QString mot_de_passe=ui->nouv->text();

       // Employee E(mot_de_passe);

    Employee E1;

    int matricule=E1.mdp_oub(code);
    if(matricule!=-1)
    {

       if(int test1=E1.modifmdp(mot_de_passe,matricule)==true){
            QMessageBox::information(nullptr, QObject::tr("modifier un employee"),
                              QObject::tr("mot de passe modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

            home h(nullptr);
            this->hide();
            h.setModal(this);
            h.exec();

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
