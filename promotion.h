#ifndef PROMOTION_H
#define PROMOTION_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QDate>
#include "produit.h"

class Promotion
{
public:
    Promotion();
    Promotion(int,QString,QString,QString,int,int);
    int getIDpromotion();
    QString getDate_debut();
     QString getDate_fin();
     QString getDescription();
     int getpourcentage();
     int getIDcategorie();

     void setIDpromotion(int);
      void setDate_debut(QString);
       void setDate_fin(QString);
        void setDescription(QString);
        void setpourcentage(int);
        void setIDcategorie(int);

        bool ajouterpromotion(int);
        QSqlQueryModel* afficherp();


        bool supprimerpromotion(int);
        bool actualiser();

        bool Existence_Promotion(const int& Ref_Promotion) const;
        bool Existence_categ(const int& IDcategorie) const;

        bool modifierpromotion(int,QString,QString,QString,int,int);
        Promotion chercherpromotion(int Ref_Promotion);
        Promotion cherchercateg();

        QSqlQueryModel* afficher_Promotion(QString Ref_Promotion);


        QSqlQueryModel* tri_IDcategorie();
        QSqlQueryModel* tri_datedebut();
        QSqlQueryModel* tri_datefin();
        QSqlQueryModel* tri_pourcentagecroissant();
        QSqlQueryModel* tri_pourcentagedecroissant();
        QSqlQueryModel* statisticpromotion();

private:
        int IDpromotion;QString Date_debut;QString Date_fin;
        QString Description;int pourcentage;int IDcategorie;
};





#endif // Promotion_H
