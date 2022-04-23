#ifndef PANIER_H
#define PANIER_H


#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>


class Panier
{
public:
    Panier();
    Panier(int,int,int,int,int);
    int getnumero();
    int getRef_produit();
  int getID_client();
  int getID_commande();
    int getQuantite();


    void setnumero(int);
       void setRef_produit(int);
        void setID_client(int);
        void setID_commande(int);
        void setQuantite(int);

        bool ajouter();
        bool supprimer(int);
        bool Existence_numero(const int& Numero) const;
        bool Existence_quantite(const int& Quantite) const;

        bool modifier(int,int,int,int,int);
        QSqlQueryModel* afficher();
        QSqlQueryModel* afficher_panier(QString);
          Panier chercher(int ID_commande);
          void modifierquantiteproduit(int,int);
void modifierquantiteproduit_apres_supp_acheter(int,int);

private:
 int Numero,Ref_produit,Quantite,ID_commande,ID_client;


};


#endif // PANIER_H
