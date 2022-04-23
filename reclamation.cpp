#include "reclamation.h"

#include <QSqlQuery> //manipulation des requetes du sql
#include <QSqlQueryModel> //lire les donnés et les afficher (tableau)
#include <QSqlDatabase> //connect to database
#include <QObject> //private section class slots

reclamation::reclamation()
{
idreclamation=0;
description="";
}
reclamation::reclamation(int idreclamation,QDate datereclamation,QString description,int idfournisseur)
{
    this->idreclamation=idreclamation;
    this->datereclamation=datereclamation;
    this->description=description;
      this->idfournisseur=idfournisseur;
}
int reclamation::getid(){  return idreclamation;}
QDate reclamation::getdatereclamation(){return datereclamation;}
int reclamation::getidfournisseur(){return idfournisseur;}
QString reclamation::getdescription(){return description;}
void reclamation::setid(int idreclamation){this->idreclamation=idreclamation;}
void reclamation::setdatereclamation(QDate datereclamation){this->datereclamation=datereclamation;}
void reclamation::setdescription(QString description){ this->description=description;}
void reclamation::setidfournisseur(int idfournisseur){this->idfournisseur=idfournisseur;}
bool reclamation::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(idreclamation);
    query.prepare("INSERT INTO reclamation (IDreclamation, datereclamation, DESCRIPTION, idfournisseur) "
                  "VALUES (:idreclamation, :datereclamation, :description, :idfournisseur)");
    query.bindValue(":idreclamation", id_string);
    query.bindValue(":datereclamation", datereclamation);
      query.bindValue(":description", description);
           query.bindValue(":idfournisseur", idfournisseur);
            return query.exec();
}
bool reclamation::supprimer(int idreclamation){
    bool success = false;

       if (userExists(idreclamation))
        {
            QSqlQuery queryDelete;
            queryDelete.prepare("DELETE FROM reclamation WHERE idreclamation=:idreclamation");
            QString res2=QString::number(idreclamation);
                     queryDelete.bindValue(":idreclamation", res2);

            success = queryDelete.exec();

            if(!success)
                qDebug() << "Delete user failure:" << queryDelete.lastError();
            else
                qDebug() << "User successfully deleted" << idreclamation;


        }
        else
        {
            qDebug() << "Error deleting user: user does not exist";
        }

        return success;
}
   QSqlQueryModel* reclamation::afficher()
   {
      QSqlQueryModel* model=new QSqlQueryModel();
            model->setQuery("SELECT* FROM reclamation");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("date reclamation"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("idfournisseur"));



      return model;
   }

   bool reclamation:: userExists(const int& idreclamation) const
   {
       bool exists = false;

       QSqlQuery checkQuery;
       checkQuery.prepare("SELECT idreclamation FROM reclamation WHERE idreclamation=:idreclamation");
       checkQuery.bindValue(":idreclamation", idreclamation); //tab3th lvaleur mte3na lel bd

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
  reclamation reclamation::chercher(int idreclamation){

           reclamation E1;

           QSqlQuery checkQuery;
           checkQuery.prepare("SELECT * FROM reclamation WHERE idreclamation = :idreclamation");
           checkQuery.bindValue(":idreclamation", idreclamation);

           if (checkQuery.exec())
           {
               if (checkQuery.next())
               {
                   E1.setid(checkQuery.value(0).toInt());
                   E1.setdatereclamation(checkQuery.value(2).toDate());
                         E1.setdescription(checkQuery.value(3).toString());
                   E1.setidfournisseur(checkQuery.value(4).toInt());



                   return E1;
               }
           }
           else
           {
               qDebug() << "User not found:" << checkQuery.lastError();
           }
   E1.setid(0);
   return E1;
       }

