#pragma once
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
class Commande
{
    //*****attributs
    int idCommande, num_Tel, quantity, Paiment_Valide;
    QString mode_Livraison;
    QDate date_Commande;

public:
    // CONSTRUCT
    Commande();
    Commande(int, int, int, int, QString, QDate);
    // GETTERS
    int getIdCommande();
    int getNumTel();
    int getQuantity();
    int getPaimentValide();
    QString getModeLivraison();
    QDate getDateCommande();
    // SETTERS
    void setIdCommande(int);
    void setNumTel(int);
    void setQuantity(int);
    void setPaimentValide(int);
    void setModeLivraison(QString);
    void setDateCommande(QDate);
    //***Methods
    bool ajouterCommande();
    bool supprimerCommande(int);
    QSqlQueryModel *afficherCommande();
    bool userExists(const int &idCommande) const;
    bool modifier_Commande(int, int, int, int, QString, QDate);
    Commande chercher_Commande(const int &idCommande);
};
