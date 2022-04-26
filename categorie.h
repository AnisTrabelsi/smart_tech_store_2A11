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
    QString REMISE;
public:
    Categorie();
    Categorie(int,QString,QString);
    //*****GETTERS*****//
    int getID();
    QString getREMISE();
    QString getLIBELLE();
    //*****SETTERS******//
    void setID(int);
    void setREMISE(QString);
    void setLIBELLE(QString);
    //********METHODS******//
    bool ajouterCategorie();
    bool supprimerCategorie(int);
    QSqlQueryModel *afficherCategorie(int);
    bool CategorieExists(const int &idCategorie) const;
    bool modifier_Categorie(int, QString,QString);
    bool ajouterCategorieA();
    Categorie chercher_Categorie(const int &idCategorie);

};


