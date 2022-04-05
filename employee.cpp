#include "employee.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
Employee::Employee()
{
matricule=0;
}
Employee::Employee(int matricule,QString nom,QString prenom,QString e_mail,QDate date_embauche,int salaire,QString mot_de_passe,int code){
    this->matricule=matricule; this->nom=nom; this->prenom=prenom; this->e_mail=e_mail; this->date_embauche=date_embauche; this->mot_de_passe=mot_de_passe; this->salaire=salaire; this->code=code;
}
int Employee:: getmatricule(){return matricule;}
QString Employee:: getnom(){return nom;}
QString Employee:: getprenom(){return prenom;}
QString Employee:: gete_mail(){return e_mail;}
QDate Employee:: getdate_embauche(){return date_embauche;}
QString Employee::getmot_de_passe(){return mot_de_passe;}
int Employee:: getsalaire(){return salaire;}
int Employee:: getcode(){return code;}
void Employee:: setmatricule(int matricule){this->matricule=matricule;}
void Employee:: setnom(QString nom){this->nom=nom;}
void Employee:: setprenom(QString prenom){this->prenom=prenom;}
void Employee:: sete_mail(QString e_mail){this->e_mail=e_mail;}
void Employee:: setdate_embauche(QDate date_embauche){this->date_embauche=date_embauche;}
void Employee:: setmot_de_passe(QString mot_de_passe){this->mot_de_passe=mot_de_passe;}
void Employee:: setsalaire(int salaire){this->salaire=salaire;}
void Employee:: setcode(int code){this->code=code;}


bool Employee:: ajouter(){
    QSqlQuery query;
    QString id_string= QString::number(matricule);
query.prepare("INSERT INTO EMPLOYEE (MATRICULE,NOM,PRENOM,E_MAIL,DATE_EMBAUCHE,SALAIRE,MOT_DE_PASSE,CODE)"
              "VALUES (:matricule,:nom,:prenom,:e_mail,:date_embauche,:salaire,:mot_de_passe,:code)");
         query.bindValue(":matricule", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":e_mail", e_mail);
         query.bindValue(":date_embauche", date_embauche);
         query.bindValue(":salaire", salaire);
         query.bindValue(":mot_de_passe", mot_de_passe);
         query.bindValue(":code", code);
         return query.exec();

}
QSqlQueryModel* Employee::afficher(int a){


    QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT *  FROM employee");
          if(a==0)
          {
              model->setQuery("SELECT *  FROM employee order by matricule");
          }
          else if(a==1){
              model->setQuery("SELECT *  FROM employee order by nom");
          }
          else if(a==2){
              model->setQuery("SELECT *  FROM employee order by prenom");
          }
          else if(a==3){
              model->setQuery("SELECT *  FROM employee order by date_embauche");
          }
          else if(a==4){
              model->setQuery("SELECT *  FROM employee order by salaire");
          }
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'embauche"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("mot de passe"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("code"));

    return model;
}
QSqlQueryModel* Employee::afficherarchive(){


    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM archiveemp");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'embauche"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("mot de passe"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("code"));

    return model;
}
bool Employee:: ajouterarchive(){
    QSqlQuery query;
    QString id_string= QString::number(matricule);
query.prepare("INSERT INTO ARCHIVEEMP (MATRICULE,NOM,PRENOM,E_MAIL,DATE_EMBAUCHE,SALAIRE,MOT_DE_PASSE,CODE)"
              "VALUES (:matricule,:nom,:prenom,:e_mail,:date_embauche,:salaire,:mot_de_passe,:code)");
         query.bindValue(":matricule", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":e_mail", e_mail);
         query.bindValue(":date_embauche", date_embauche);
         query.bindValue(":salaire", salaire);
         query.bindValue(":mot_de_passe", mot_de_passe);
         query.bindValue(":code", code);
         return query.exec();

}
bool Employee::supprimer(int matricule){
    bool success = false;

   if (userExists(matricule))
    {
       Employee E1=chercher(matricule);
       bool test=E1.ajouterarchive();
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

bool Employee::supprimerarchive(int matricule){
    bool success = false;

   if (userExistsarchive(matricule))
    {
       Employee E1=chercherarchive(matricule);
       bool test=E1.ajouter();
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM archiveemp WHERE matricule=:matricule");
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
bool Employee::supprimerdefinitif(int matricule){
    bool success = false;

   if (userExistsarchive(matricule))
    {
       Employee E1=chercherarchive(matricule);
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM archiveemp WHERE matricule=:matricule");
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
bool Employee:: userExistsarchive(const int& matricule) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT matricule FROM archiveemp WHERE matricule = (:matricule)");
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
int Employee::cherchercode(int code){

    QSqlDatabase bd = QSqlDatabase::database();
int matricule;
        QSqlQuery query;
        query.prepare("SELECT matricule FROM employee WHERE code =:code");
 query.bindValue(":code", code);

        query.exec();
        if (query.next())
        {

            matricule=query.value(0).toInt();
             return matricule;
        }
        else {
            return -1;
        }

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
                E1.setcode(checkQuery.value(7).toInt());

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

Employee Employee::chercherarchive(int matricule){

        Employee E1;

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM archiveemp WHERE matricule = (:matricule)");
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
                E1.setcode(checkQuery.value(7).toInt());

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

bool Employee::modifier(int matricule,QString nom,QString prenom,QString e_mail,QDate date_embauche,int salaire,QString mot_de_passe,int code)
{
    QSqlQuery query;
    query.prepare("update employee set matricule=:matricule,nom=:nom,prenom=:prenom,e_mail=:e_mail,date_embauche=:date_embauche,salaire=:salaire,mot_de_passe=:mot_de_passe,code=:code WHERE matricule=:matricule");
    query.bindValue(":matricule",matricule);
     query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
          query.bindValue(":e_mail", e_mail);
              query.bindValue(":date_embauche", date_embauche);
                  query.bindValue(":salaire", salaire);
                      query.bindValue(":mot_de_passe", mot_de_passe);
                      query.bindValue(":code", code);
    return    query.exec();
}
QSqlQueryModel* Employee::trier()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM employee ORDER BY matricule");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prénom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date d'embauche"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("mot de passe"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("code"));

    return model;
}
/*QSqlQueryModel * Employee::statistic()
{
    QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("select matricule,(count(matricule)*100/ (select count(*)from employee)) as pourcentage from employee group by matricule");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("percentage"));
       return model;


}*/

int Employee::mdp_oub(QString code)
{
    QSqlDatabase bd = QSqlDatabase::database();
int matricule;
        QSqlQuery query;
        query.prepare("SELECT matricule FROM employee WHERE code =:code");
 query.bindValue(":code", code);

        query.exec();
        if (query.next())
        {

            matricule=query.value(0).toInt();
             return matricule;
        }
        else {
            return -1;
        }



}

bool Employee::modifmdp(QString mot_de_passe,int matricule){
    QSqlQuery query;
    query.prepare("update employee set mot_de_passe=:mot_de_passe where matricule=:matricule");
                      query.bindValue(":mot_de_passe", mot_de_passe);
                       query.bindValue(":matricule", matricule);
    return    query.exec();

}
