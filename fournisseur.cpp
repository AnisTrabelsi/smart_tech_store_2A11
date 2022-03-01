#include "fournisseur.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
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
    QSqlQuery query;
query.prepare("DELETE from fournisseur where idfournisseur=:idfournisseur");
         query.bindValue(0, idfournisseur);

         return query.exec();
}
   QSqlQueryModel* Fournisseur::afficher()
   {
      QSqlQueryModel* model=new QSqlQueryModel();
            model->setQuery("SELECT* FROM FOURNISSEUR");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("date d'ajout"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("date d'expiration"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));



      return model;
   }
