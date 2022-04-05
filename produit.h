#ifndef PRODUIT_H
#define PRODUIT_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>


class Produit
{
public:
    Produit();
    Produit(int,QString,int,int,int,int);
    int getRef_produit();
    QString getLibelle_produit();
     int getprix();
     int getquantite();
     int getcategorie();
     int getfournisseur();

     void setRef_produit(int);
      void setLibelle_produit(QString);
       void setprix(int);
        void setquantite(int);
        void setcategorie(int);
        void setfournisseur(int);

        bool ajouter();
        bool supprimer(int);
        bool Existence_produit(const int& Ref_produit) const;
        bool modifier(int,QString,int,int,int,int);
        QSqlQueryModel* afficher();
        QSqlQueryModel* tri_croissant();
        QSqlQueryModel* tri_decroissant();
        QSqlQueryModel* tri_ref();
        QSqlQueryModel* tri_libelle();
        QSqlQueryModel* tri_quantite();
        Produit chercher(int Ref_produit);
        QSqlQueryModel* afficher_produit(QString Ref_produit);
        void calculer(int,int);
        void calculerapressupp(int,int);

private:
 int Ref_produit,Quantite,IDCategorie,IDFournisseur;
 QString Libelle_produit;
 int Prix;

};

#endif // PRODUIT_H
