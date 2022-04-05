
#include "promotion.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTextStream>

Promotion::Promotion()
 {
        IDpromotion=0;Description="";
        pourcentage=0;
        pourcentage=0;
    }

Promotion::Promotion(int IDpromotion,QString Date_debut,QString Date_fin,QString Description,int pourcentage,int IDcategorie)
{this->IDpromotion=IDpromotion;
    this->Date_debut=Date_debut;
    this->Date_fin=Date_fin;
    this->Description=Description;
    this->pourcentage=pourcentage;
    this->IDcategorie=IDcategorie;}

    int Promotion::getIDpromotion(){return IDpromotion;}
    QString Promotion::getDate_debut(){return Date_debut;}
    QString Promotion::getDate_fin(){return Date_fin;}
    QString Promotion::getDescription(){return Description;}
    int Promotion::getpourcentage(){return pourcentage;}
    int Promotion::getIDcategorie(){return IDcategorie;}

    void Promotion::setIDpromotion(int IDpromotion){this->IDpromotion=IDpromotion;}
    void Promotion::setDate_debut(QString Date_debut){this->Date_debut=Date_debut;}
    void Promotion::setDate_fin(QString Date_fin){this->Date_fin=Date_fin;}
    void Promotion::setDescription(QString Description){this->Description=Description;}
    void Promotion::setpourcentage(int pourcentage){this->pourcentage=pourcentage;}
    void Promotion::setIDcategorie(int IDcategorie){this->IDcategorie=IDcategorie;}







bool Promotion::ajouterpromotion(int IDcategorie){
   Produit P;
    QSqlQuery query;
    QString IDpromotion_string= QString::number(IDpromotion);
    QString pourcentage_string= QString::number(pourcentage);
    QString IDcategorie_string= QString::number(IDcategorie);
 if (!Existence_categ(IDcategorie)){
    query.prepare("INSERT INTO Promotion (IDpromotion,Date_debut,Date_fin,Description,pourcentage,IDcategorie) "
                  "VALUES (:IDpromotion,:Date_debut,:Date_fin,:Description,:IDcategorie,:IDcategorie)");


    query.bindValue(0, IDpromotion_string);
    query.bindValue(1, Date_debut);
    query.bindValue(2, Date_fin);
    query.bindValue(3, Description);
    query.bindValue(4, pourcentage_string);
    query.bindValue(5, IDcategorie_string);
}
         else {
         qDebug() << "categorie existante:" << IDcategorie ;


}
    return query.exec();
}

QSqlQueryModel* Promotion::afficherp( )
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Promotion");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromotion"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_debut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("pourcentage"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDcategorie"));

    return model;
}


bool Promotion::supprimerpromotion(int IDpromotion){
   bool test=false;
   Produit P;
    if (Existence_Promotion(IDpromotion))
    {QSqlQuery query;
QSqlQuery checkQuery;
          query.prepare("Delete from Promotion where IDpromotion=:IDpromotion");
          query.bindValue(0, IDpromotion);


test=query.exec();
if(!test)
qDebug() << "suppression echouée:" << query.lastError();
else
    qDebug() << "suppression de produit réussie:" << IDpromotion ;
    }
    else
    {
        qDebug() << "la référence du produit n'existe pas";
    }
    return test;

}

bool Promotion:: Existence_Promotion(const int& IDpromotion) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT IDpromotion FROM Promotion WHERE IDpromotion=:IDpromotion");
    checkQuery.bindValue(":IDpromotion", IDpromotion);

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

bool Promotion:: Existence_categ(const int& IDcategorie) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT IDcategorie FROM Promotion WHERE IDcategorie=:IDcategorie");
    checkQuery.bindValue(":IDcategorie", IDcategorie);

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



Promotion Promotion::chercherpromotion(int IDpromotion){

    Promotion P1;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Promotion WHERE IDpromotion = :IDpromotion");
    checkQuery.bindValue(":IDpromotion", IDpromotion);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            P1.setIDpromotion(checkQuery.value(0).toInt());
            P1.setDate_debut(checkQuery.value(1).toString());
            P1.setDate_fin(checkQuery.value(2).toString());
            P1.setDescription(checkQuery.value(3).toString());
            P1.setpourcentage(checkQuery.value(4).toInt());
            P1.setIDcategorie(checkQuery.value(5).toInt());


            return P1;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
    }

    return P1;
}

    bool Promotion::modifierpromotion(int IDpromotion,QString Date_debut,QString Date_fin,QString Description,int pourcentage,int IDcategorie)
    {
        QSqlQuery query;
        query.prepare("update Promotion set IDpromotion=:IDpromotion,Date_debut=:Date_debut,Date_fin=:Date_fin,Description=:Description,pourcentage=:pourcentage,IDcategorie=:IDcategorie where IDpromotion=:IDpromotion ");
        query.bindValue(":IDpromotion",IDpromotion);
        query.bindValue(":Date_debut", Date_debut);
        query.bindValue(":Date_fin", Date_fin);
        query.bindValue(":Description", Description);
        query.bindValue(":pourcentage", pourcentage);
        query.bindValue(":IDcategorie", IDcategorie);
        return    query.exec();
    }




    QSqlQueryModel* Promotion::afficher_Promotion(QString IDpromotion)
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM Promotion WHERE IDpromotion=:IDpromotion ");
        query.bindValue(":IDpromotion",IDpromotion);
        QSqlQueryModel* model= new QSqlQueryModel();
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromotion"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_debut"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("pourcentage"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDcategorie"));

        return model;
    }

    QSqlQueryModel* Promotion::tri_IDcategorie()
    {
        QSqlQueryModel* model=new  QSqlQueryModel();

        model->setQuery("SELECT * FROM Promotion ORDER BY IDcategorie");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromotion"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_debut"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("pourcentage"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDcategorie"));

        return model;
    }



    QSqlQueryModel* Promotion::tri_datedebut()
    {
        QSqlQueryModel* model=new  QSqlQueryModel();

        model->setQuery("SELECT * FROM Promotion ORDER BY Date_debut");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromotion"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_debut"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("pourcentage"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDcategorie"));

        return model;
    }


    QSqlQueryModel* Promotion::tri_datefin()
    {
        QSqlQueryModel* model=new  QSqlQueryModel();

        model->setQuery("SELECT * FROM Promotion ORDER BY Date_fin");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromotion"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_debut"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("pourcentage"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDcategorie"));

        return model;
    }

    QSqlQueryModel* Promotion::tri_pourcentagecroissant()
    {
        QSqlQueryModel* model=new  QSqlQueryModel();

        model->setQuery("SELECT * FROM Promotion ORDER BY pourcentage ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromotion"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_debut"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("pourcentage"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDcategorie"));

        return model;
    }

    QSqlQueryModel* Promotion::tri_pourcentagedecroissant()
    {
        QSqlQueryModel* model=new  QSqlQueryModel();

        model->setQuery("SELECT * FROM Promotion ORDER BY pourcentage DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDpromotion"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_debut"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("pourcentage"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDcategorie"));

        return model;
    }






