#pragma once
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>

class CIVRAISON
{
    int idlivraison;
    int code_postal;
    QString Region;
    QString Ville;
    QDate date_livraison;
public:
    CIVRAISON();
    CIVRAISON(int,int,QString,QString,QDate);

    int getIdLivraison();
    int getCodePostal();
    QString getRegion();
    QString getVille();
    QDate getDateL();

    void setIdLivraison(int);
    void setCodePostal(int);
    void setRegion(QString);
    void setVille(QString);
    void setDateL(QDate);

    bool ajouterLivraison();
};


