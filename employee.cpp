#include "employee.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
Employee::Employee()
{
matricule=0;
}
Employee::Employee(int matricule,QString nom,QString prenom,QString e_mail,QDate date_embauche,int salaire,QString mot_de_passe){
    this->matricule=matricule; this->nom=nom; this->prenom=prenom; this->e_mail=e_mail; this->date_embauche=date_embauche; this->mot_de_passe=mot_de_passe; this->salaire=salaire;
}
int Employee:: getmatricule(){return matricule;}
QString Employee:: getnom(){return nom;}
QString Employee:: getprenom(){return prenom;}
QString Employee:: gete_mail(){return e_mail;}
QDate Employee:: getdate_embauche(){return date_embauche;}
QString Employee::getmot_de_passe(){return mot_de_passe;}
int Employee:: getsalaire(){return salaire;}
void Employee:: setmatricule(int matricule){this->matricule=matricule;}
void Employee:: setnom(QString nom){this->nom=nom;}
void Employee:: setprenom(QString prenom){this->prenom=prenom;}
void Employee:: sete_mail(QString e_mail){this->e_mail=e_mail;}
void Employee:: setdate_embauche(QDate date_embauche){this->date_embauche=date_embauche;}
void Employee:: setmot_de_passe(QString mot_de_passe){this->mot_de_passe=mot_de_passe;}
void Employee:: setsalaire(int salaire){this->salaire=salaire;}
bool Employee:: ajouter(){
    QSqlQuery query;
    QString id_string= QString::number(matricule);
query.prepare("INSERT INTO EMPLOYEE (MATRICULE,NOM,PRENOM,E_MAIL,DATE_EMBAUCHE,SALAIRE,MOT_DE_PASSE)"
              "VALUES (:matricule,:nom,:prenom,:e_mail,:date_embauche,:salaire,:mot_de_passe)");
         query.bindValue(":matricule", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":e_mail", e_mail);
         query.bindValue(":date_embauche", date_embauche);
         query.bindValue(":salaire", salaire);
         query.bindValue(":mot_de_passe", mot_de_passe);
         return query.exec();

}
QSqlQueryModel* Employee::afficher(){


    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM employee");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'embauche"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("mot de passe"));

    return model;
}

bool Employee::supprimer(int matricule){
    bool success = false;

   if (userExists(matricule))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM employee WHERE matricule=:matricule");
        QString res2=QString::number(matricule);
                 queryDelete.bindValue(":matricule", res2);

        success = queryDelete.exec();

        if(!success)
            qDebug() << "Delete user failure:" << queryDelete.lastError();
        else
            qDebug() << "User successfully deleted" << matricule;


    }
    else
    {
        qDebug() << "Error deleting user: user does not exist";
    }

    return success;
}
bool Employee:: userExists(const int& matricule) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT matricule FROM employee WHERE matricule = (:matricule)");
    checkQuery.bindValue(":matricule", matricule);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
    }

    return exists;
}
Employee Employee::chercher(int matricule){

        Employee E1;

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM employee WHERE matricule = (:matricule)");
        checkQuery.bindValue(":matricule", matricule);

        if (checkQuery.exec())
        {
            if (checkQuery.next())
            {
                E1.setmatricule(checkQuery.value(0).toInt());
                E1.setnom(checkQuery.value(1).toString());
                E1.setprenom(checkQuery.value(2).toString());
                E1.sete_mail(checkQuery.value(3).toString());
                E1.setdate_embauche(checkQuery.value(4).toDate());
                E1.setsalaire(checkQuery.value(5).toInt());
                E1.setmot_de_passe(checkQuery.value(6).toString());

                return E1;
            }
        }
        else
        {
            qDebug() << "User not found:" << checkQuery.lastError();
        }
E1.setnom("vide");
return E1;
    }


bool Employee::modifier(int matricule,QString nom,QString prenom,QString e_mail,QDate date_embauche,int salaire,QString mot_de_passe)
{
    QSqlQuery query;
    query.prepare("update employee set matricule=:matricule,nom=:nom,prenom=:prenom,e_mail=:e_mail,date_embauche=:date_embauche,salaire=:salaire,mot_de_passe=:mot_de_passe where matricule=:matricule");
    query.bindValue(":matricule",matricule);
     query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
          query.bindValue(":e_mail", e_mail);
              query.bindValue(":date_embauche", date_embauche);
                  query.bindValue(":salaire", salaire);
                      query.bindValue(":mot_de_passe", mot_de_passe);
    return    query.exec();
}
