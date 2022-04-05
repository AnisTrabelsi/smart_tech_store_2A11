#include "fournisseur.h"
#include <QSqlQuery> //manipulation des requetes du sql
#include <QSqlQueryModel> //lire les donnés et les afficher (tableau)
#include <QSqlDatabase> //connect to database
#include <QObject> //private section class slots

Fournisseur::Fournisseur()
{
idfournisseur=0;
nom="";
description="";
}
Fournisseur::Fournisseur(int idfournisseur,QString nom,QDate dateajout,QDate dateexpr,QString description)
{
    this->idfournisseur=idfournisseur;
    this->nom=nom;
    this->dateajout=dateajout;
    this->dateexpr=dateexpr;
    this->description=description;
}
int Fournisseur::getid(){  return idfournisseur;}
QString Fournisseur::getnom(){return nom;}
QDate Fournisseur::getdateajout(){return dateajout;}
QDate Fournisseur::getdateexpr(){return dateexpr;}
QString Fournisseur::getdescription(){return description;}
void Fournisseur::setid(int idfournisseur){this->idfournisseur=idfournisseur;}
void Fournisseur::setnom(QString nom){  this->nom=nom;}
void Fournisseur::setdateajout(QDate dateajout){this->dateajout=dateajout;}
void Fournisseur::setdateexpr(QDate dateexpr){this->dateexpr=dateexpr;}
void Fournisseur::setdescription(QString description){ this->description=description;}
bool Fournisseur::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(idfournisseur);
    query.prepare("INSERT INTO FOURNISSEUR (IDFOURNISSEUR, NOM, DATEAJOUT, DATEEXPR, DESCRIPTION) "
                  "VALUES (:idfournisseur, :nom, :dateajout, :dateexpr, :description)");
    query.bindValue(":idfournisseur", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":dateajout", dateajout);
     query.bindValue(":dateexpr", dateexpr);
      query.bindValue(":description", description);
            return query.exec();
}
bool Fournisseur::supprimer(int idfournisseur){
    bool success = false;
       if (userExists(idfournisseur))
        {
            QSqlQuery queryDelete;
            queryDelete.prepare("DELETE FROM fournisseur WHERE idfournisseur=:idfournisseur");
            QString res2=QString::number(idfournisseur);
                     queryDelete.bindValue(":idfournisseur", res2);

            success = queryDelete.exec();

            if(!success)
                qDebug() << "Delete user failure:" << queryDelete.lastError();
            else
                qDebug() << "User successfully deleted" << idfournisseur;


        }
        else
        {
            qDebug() << "Error deleting user: user does not exist";
        }

        return success;
}
   QSqlQueryModel* Fournisseur::afficher()
   {
      QSqlQueryModel* model=new QSqlQueryModel();
            model->setQuery("SELECT* FROM FOURNISSEUR");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("date d'ajout"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("date d'expiration"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));



      return model;
   }

   bool Fournisseur:: userExists(const int& idfournisseur) const
   {
       bool exists = false;

       QSqlQuery checkQuery;
       checkQuery.prepare("SELECT idfournisseur FROM fournisseur WHERE idfournisseur=:idfournisseur");
       checkQuery.bindValue(":idfournisseur", idfournisseur); //tab3th lvaleur mte3na lel bd

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
  Fournisseur Fournisseur::chercher(int idfournisseur){

           Fournisseur E1;

           QSqlQuery checkQuery;
           checkQuery.prepare("SELECT * FROM fournisseur WHERE idfournisseur = :idfournisseur");
           checkQuery.bindValue(":idfournisseur", idfournisseur);

           if (checkQuery.exec())
           {
               if (checkQuery.next())
               {
                   E1.setid(checkQuery.value(0).toInt());
                   E1.setnom(checkQuery.value(1).toString());
                   E1.setdateajout(checkQuery.value(2).toDate());
                   E1.setdateexpr(checkQuery.value(3).toDate());
                   E1.setdescription(checkQuery.value(4).toString());


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

  bool Fournisseur::modifier(int idfournisseur,QString nom,QDate dateajout,QDate dateexpr,QString description)
  {
      QSqlQuery query;
      query.prepare("update fournisseur set nom=:nom,dateajout=:dateajout,dateexpr=:dateexpr,description=:description  WHERE idfournisseur = :idfournisseur");
      query.bindValue(":idfournisseur",idfournisseur);
       query.bindValue(":nom", nom);
        query.bindValue(":dateajout", dateajout);
            query.bindValue(":dateexpr", dateexpr);
                query.bindValue(":description", description);
      return    query.exec();
  }
  QSqlQueryModel* Fournisseur::trier()
  {
      QSqlQueryModel* model=new QSqlQueryModel();
            model->setQuery("SELECT* FROM FOURNISSEUR ORDER BY dateajout");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("date d'ajout"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("date d'expiration"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));



      return model;
  }


  int Fournisseur::cherchersys(){

           Fournisseur E1;

           QSqlQuery checkQuery;
           checkQuery.prepare("SELECT * FROM fournisseur WHERE to_date(dateexpr,'dd-mm-yy')<to_date(sysdate,'dd-mm-yy')");
           checkQuery.bindValue(":dateexpr", dateexpr);


           if (checkQuery.exec())
           {
               if (checkQuery.next())
               {
                   E1.setid(checkQuery.value(0).toInt());
                   E1.setnom(checkQuery.value(1).toString());
                   E1.setdateajout(checkQuery.value(2).toDate());
                   E1.setdateexpr(checkQuery.value(3).toDate());
                   E1.setdescription(checkQuery.value(4).toString());


                   return E1.getid();
               }
           }
           else
           {
               qDebug() << "User not found:" << checkQuery.lastError();
           }
   E1.setnom("vide");
   return E1.getid();
       }


  bool Fournisseur::supprimersys(){
      bool success = false;
         if (userExistsys(dateexpr))
          {
             Fournisseur F;
              QSqlQuery queryDelete;
              int idfournisseur=F.cherchersys();
              queryDelete.prepare("DELETE FROM fournisseur WHERE to_date(dateexpr,'dd-mm-yy')<to_date(sysdate,'dd-mm-yy')");
                       queryDelete.bindValue(":idfournisseur", idfournisseur);
queryDelete.bindValue(":dateexpr", dateexpr);

              success = queryDelete.exec();

              if(!success)
                  qDebug() << "Delete user failure:" << queryDelete.lastError();
              else
                  qDebug() << "User successfully deleted" << idfournisseur;


          }
          else
          {
              qDebug() << "Error deleting user: user does not exist";
          }

          return success;
  }

  bool Fournisseur:: userExistsys(const QDate &dateexpr) const
  {
      bool exists = false;

      QSqlQuery checkQuery;
      checkQuery.prepare("SELECT idfournisseur FROM fournisseur WHERE to_date(dateexpr,'dd-mm-yy')<to_date(sysdate,'dd-mm-yy')");
      checkQuery.bindValue(":dateexpr", dateexpr); //tab3th lvaleur mte3na lel bd

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
