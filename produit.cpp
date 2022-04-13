#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTextStream>
Produit::Produit()
{
    Ref_produit=0;Quantite=0;IDCategorie=0;IDFournisseur=0;
    Libelle_produit="";
    Prix=0;
}

Produit::Produit(int Ref_produit ,QString Libelle_produit,int Prix,int Quantite,int IDCategorie,int IDFournisseur)
{this->Ref_produit=Ref_produit;
    this->Libelle_produit=Libelle_produit;
    this->Prix=Prix;
    this->Quantite=Quantite;
    this->IDCategorie=IDCategorie;
    this->IDFournisseur=IDFournisseur;

}
int Produit::getRef_produit(){return Ref_produit;}
QString Produit::getLibelle_produit(){return Libelle_produit;}
int Produit::getprix(){return Prix;}
int Produit::getquantite(){return Quantite;}
int Produit::getcategorie(){return IDCategorie;}
int Produit::getfournisseur(){return IDFournisseur;}

void Produit::setRef_produit(int Ref_produit){this->Ref_produit=Ref_produit;}
void Produit::setLibelle_produit(QString Libelle_produit){this->Libelle_produit=Libelle_produit;}
void Produit::setprix(int Prix){this->Prix=Prix;}
void Produit::setquantite(int Quantite){this->Quantite=Quantite;}
void Produit::setcategorie(int IDCategorie){this->IDCategorie=IDCategorie;}
void Produit::setfournisseur(int IDFournisseur){this->IDFournisseur=IDFournisseur;}

bool Produit::ajouter(){
    QSqlQuery query;
    QString Ref_produit_string= QString::number(Ref_produit);
    QString Prix_string= QString::number(Prix);
    QString Quantite_string= QString::number(Quantite);
    QString IDCategorie_string= QString::number(IDCategorie);
    QString IDFournisseur_string= QString::number(IDFournisseur);

    query.prepare("INSERT INTO Produit (Ref_produit,Libelle_produit,Prix,Quantite,IDCategorie,IDFournisseur) "
                  "VALUES (:Ref_produit,:Libelle_produit,:Prix,:Quantite,:IDCategorie,:IDFournisseur)");
    query.bindValue(0, Ref_produit_string);
    query.bindValue(1, Libelle_produit);
    query.bindValue(2, Prix_string);
    query.bindValue(3, Quantite_string);
    query.bindValue(4, IDCategorie_string);
    query.bindValue(5, IDFournisseur_string);

    return query.exec();
}

bool Produit::supprimer(int Ref_produit){
   bool test=false;
    if (Existence_produit(Ref_produit))
    {QSqlQuery query;

          query.prepare("Delete from Produit where Ref_produit=:Ref_produit");
          query.bindValue(0, Ref_produit);


test=query.exec();
if(!test)
qDebug() << "suppression echouée:" << query.lastError();
else
    qDebug() << "suppression de produit réussie:" << Ref_produit ;
    }
    else
    {
        qDebug() << "la référence du produit n'existe pas";
    }
    return test;

}


QSqlQueryModel* Produit::afficher()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libéllé_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCatégorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFournisseur"));

    return model;
}


bool Produit::modifier(int Ref_produit,QString Libelle_produit,int Prix,int Quantite,int IDCategorie,int IDFournisseur)
{
    QSqlQuery query;
    query.prepare("update Produit set Ref_produit=:Ref_produit,Libelle_produit=:Libelle_produit,Prix=:Prix,Quantite=:Quantite,IDCategorie=:IDCategorie,IDFournisseur=:IDFournisseur where Ref_produit=:Ref_produit ");
    query.bindValue(":Ref_produit",Ref_produit);
    query.bindValue(":Libelle_produit", Libelle_produit);
    query.bindValue(":Prix", Prix);
    query.bindValue(":Quantite", Quantite);
    query.bindValue(":IDCategorie", IDCategorie);
    query.bindValue(":IDFournisseur", IDFournisseur);
    return    query.exec();
}

bool Produit:: Existence_produit(const int& Ref_produit) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Ref_produit FROM Produit WHERE Ref_produit=:Ref_produit");
    checkQuery.bindValue(":Ref_produit", Ref_produit);

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
Produit Produit::chercher(int Ref_produit){

    Produit P1;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Produit WHERE Ref_produit = :Ref_produit");
    checkQuery.bindValue(":Ref_produit", Ref_produit);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            P1.setRef_produit(checkQuery.value(0).toInt());
            P1.setLibelle_produit(checkQuery.value(1).toString());
            P1.setprix(checkQuery.value(2).toInt());
            P1.setquantite(checkQuery.value(3).toInt());
            P1.setcategorie(checkQuery.value(4).toInt());
            P1.setfournisseur(checkQuery.value(5).toInt());


            return P1;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
        P1.setLibelle_produit("vide");
    }

    return P1;
}

///////////////////metiers/////////////////////

QSqlQueryModel* Produit::tri_croissant()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Produit ORDER BY Prix");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCategorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFournisseur"));

    return model;
}

QSqlQueryModel* Produit::tri_decroissant()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Produit ORDER BY Prix DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCategorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFournisseur"));

    return model;
}


QSqlQueryModel* Produit::tri_ref()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Produit ORDER BY Ref_produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCategorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFournisseur"));

    return model;
}
QSqlQueryModel* Produit::tri_quantite()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Produit ORDER BY Quantite");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCategorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFournisseur"));

    return model;
}

QSqlQueryModel* Produit::tri_libelle()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT * FROM Produit ORDER BY Libelle_produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCategorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFournisseur"));

    return model;
}




QSqlQueryModel* Produit::afficher_produit(QString Ref_produit)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Produit WHERE Ref_produit=:Ref_produit ");
    query.bindValue(":Ref_produit",Ref_produit);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDCategorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDFournisseur"));

    return model;
}


void Produit::calculer(int IDcategorie,int pourcentage)
{// lors de l'ajout ou modif je recuppere pourcentage et IDcategorie et je fais mon calcul par la commande sql
    QSqlQuery query2;
    query2.prepare("update Produit set prix=((prix*:pourcentage)/100) where IDcategorie=:IDcategoriep  ");
    query2.bindValue(":pourcentage",100-pourcentage);
    query2.bindValue(":IDcategoriep",IDcategorie);

    query2.exec();
}

void Produit::calculerapressupp(int IDcategorie,int pourcentage)
{// lors de l'ajout ou modif je recuppere pourcentage et IDcategorie et je fais mon calcul par la commande sql
    QSqlQuery query2;
    query2.prepare("update Produit set prix=((prix*100)/:pourcentage) where IDcategorie=:IDcategoriep  ");
    query2.bindValue(":pourcentage",100-pourcentage);
    query2.bindValue(":IDcategoriep",IDcategorie);

    query2.exec();
}

void Produit::warning()
{// lors de l'ajout ou modif je recuppere pourcentage et IDcategorie et je fais mon calcul par la commande sql
    QSqlQuery query;
    query.prepare("update Produit set Quantite=0  ");
    query.exec();
}

