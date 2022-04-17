#pragma once
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
class Categorie
{
    int ID_CATEGORIE;
    QString LIBELLE;
    int REMISE;
public:
    Categorie();
    Categorie(int,QString,int);
    //*****GETTERS*****//
    int getID();
    int getREMISE();
    QString getLIBELLE();
    //*****SETTERS******//
    void setID(int);
    void setREMISE(int);
    void setLIBELLE(QString);
    //********METHODS******//
    bool ajouterCategorie();
    bool supprimerCategorie(int);
    QSqlQueryModel *afficherCategorie(int);
    bool CategorieExists(const int &idCategorie) const;
    bool modifier_Categorie(int, QString,int);
    bool ajouterCategorieA();
    Categorie chercher_Categorie(const int &idCategorie);

};


