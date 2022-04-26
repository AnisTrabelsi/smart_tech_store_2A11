#include "panier.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTextStream>
Panier::Panier()
{
    Ref_produit=0;ID_client=0;ID_commande=0;Quantite=0,Numero=0;

}

Panier::Panier(int Numero,int Ref_produit ,int Quantite,int ID_commande,int ID_client)
{   this->Numero=Numero;
    this->Ref_produit=Ref_produit;
    this->Quantite=Quantite;
    this->ID_commande=ID_commande;
    this->ID_client=ID_client;

}
int Panier::getnumero(){return Numero;}
int Panier::getRef_produit(){return Ref_produit;}
int Panier::getQuantite(){return Quantite;}
int Panier::getID_commande(){return ID_commande;}
int Panier::getID_client(){return ID_client;}


void Panier::setnumero(int Numero){this->Numero=Numero;}
void Panier::setRef_produit(int Ref_produit){this->Ref_produit=Ref_produit;}
void Panier::setQuantite(int Quantite){this->Quantite=Quantite;}
void Panier::setID_commande(int ID_commande){this->ID_commande=ID_commande;}
void Panier::setID_client(int ID_client){this->ID_client=ID_client;}


bool Panier::ajouter(){
    QSqlQuery query;
    QString Numero_string= QString::number(Numero);
    QString Ref_produit_string= QString::number(Ref_produit);
    QString Quantite_string= QString::number(Quantite);
    QString ID_commande_string= QString::number(ID_commande);
    QString ID_client_string= QString::number(ID_client);

    query.prepare("INSERT INTO Acheter (Numero,Ref_produit,Quantite,ID_commande,ID_client) "
                  "VALUES (:Numero,:Ref_produit,:Quantite,:ID_commande,:ID_client)");
   query.bindValue(0, Numero_string);
    query.bindValue(1, Ref_produit_string);
    query.bindValue(2, Quantite_string);
    query.bindValue(3, ID_commande_string);
    query.bindValue(4, ID_client_string);



    return query.exec();
}

bool Panier::supprimer(int Numero){
   bool test=false;
    if (Existence_numero(Numero))
    {QSqlQuery query;

          query.prepare("Delete from Acheter where Numero=:Numero");
          query.bindValue(0, Numero);


test=query.exec();
if(!test)
qDebug() << "suppression echouée:" << query.lastError();
else
    qDebug() << "suppression de Numero réussie:" << Numero ;
    }
    else
    {
        qDebug() << "le Numero n'existe pas";
    }
    return test;

}

bool Panier::supprimerparid(int id){
   bool test=false;
QSqlQuery query;

          query.prepare("Delete from Acheter where ID_COMMANDE=:id");
          query.bindValue(0, id);


test=query.exec();
if(!test)
qDebug() << "suppression echouée:" << query.lastError();
else
    qDebug() << "suppression de Numero réussie:" << id ;


    return test;

}



QSqlQueryModel* Panier::afficher()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Acheter");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_commande"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_client"));

    return model;
}


QSqlQueryModel* Panier::afficher_panier(QString Numero)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Acheter WHERE Numero=:Numero ");
    query.bindValue(":Numero",Numero);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Ref_produit"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantité"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_commande"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_client"));

    return model;
}


bool Panier::modifier(int Numero,int Ref_produit,int Quantite,int ID_commande,int ID_client)
{
    QSqlQuery query;
    query.prepare("update Acheter set Numero=:Numero,Ref_produit=:Ref_produit,Quantite=:Quantite,ID_commande=:ID_commande,ID_client=:ID_client where Numero=:Numero");
    query.bindValue(":Ref_produit",Ref_produit);
    query.bindValue(":ID_client", ID_client);
    query.bindValue(":ID_commande", ID_commande);
    query.bindValue(":Quantite", Quantite);
query.bindValue(":Numero", Numero);
    return    query.exec();
}

bool Panier:: Existence_numero(const int& Numero) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Numero FROM Acheter WHERE Numero=:Numero");
    checkQuery.bindValue(":Numero", Numero);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "numero not found:" << checkQuery.lastError();
    }

    return exists;
}

bool Panier:: Existence_quantite(const int& Quantite) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Quantite FROM Produit WHERE Quantite>:Quantite");
    checkQuery.bindValue(":Quantite", Quantite);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "pas de stock:" << checkQuery.lastError();
    }

    return exists;
}



Panier Panier::chercher(int Numero){

    Panier P2;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Acheter WHERE Numero=:Numero");
    checkQuery.bindValue(":Numero", Numero);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {            P2.setnumero(checkQuery.value(0).toInt());
            P2.setRef_produit(checkQuery.value(1).toInt());
            P2.setQuantite(checkQuery.value(2).toInt());

            P2.setID_commande(checkQuery.value(3).toInt());
  P2.setID_client(checkQuery.value(4).toInt());


            return P2;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();

    }

    return P2;
}


void Panier::modifierquantiteproduit(int Quantite,int Ref_produit)
{
    QSqlQuery query;

    query.prepare("update Produit set Quantite=(Quantite-(:Quantite)) where Ref_produit=:Ref_produit ");
    query.bindValue(":Quantite",Quantite);
        query.bindValue(":Ref_produit",Ref_produit);
    query.exec();
}

void Panier::modifierquantiteproduit_apres_supp_acheter(int Quantite,int Ref_produit)
{
    QSqlQuery query;

    query.prepare("update Produit set Quantite=(Quantite+(:Quantite)) where Ref_produit=:Ref_produit ");
    query.bindValue(":Quantite",Quantite);
        query.bindValue(":Ref_produit",Ref_produit);
    query.exec();
}

