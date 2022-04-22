#ifndef FACTURE_H
#define FACTURE_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include<QPrinter>
#include<QPrintDialog>
#include<QPainter>
#include<QTextDocument>
class facture
{

    int nfacture;
    int etat;
    int tva;
    int total_tva;
    int total_ht;
    int total_ttc;
    int modedereglement;
    int remise;
    int matricule;
    int id_commande;
    QDate datedecreation;
    QString remarque;
QString nom;
public:
    facture();
    facture(int,int,int,int,int,int,int,int,int,int,QDate,QString );
     bool ajouter();
     bool supprimer(int idfacture,QString table);
QSqlQueryModel* afficherho(QString name,int a);
     bool userExists(const int& nfacture) const;
     bool modifier(int,int,int,int,int,int,int,int,int,int,QDate,QString);
     void regrouper(QString name);
facture chercher(int idfacture,QString table);
QSqlQueryModel* trier();
QSqlQueryModel* afficherpar(QString name,int a);
bool copytotable(QString name,facture f);
void imprimer();
void cherchers(QString &nom,QString &prenom,int idfacture );

     int get_nfacture(){return nfacture;}
     int get_etat(){return etat;}
     int get_tva(){return tva;}
     int get_total_tva(){return total_tva;}
     int get_total_ht(){return total_ht;}
     int get_total_ttc(){return total_ttc;}
     int get_modedereglement(){return modedereglement;}
     int get_remise(){return remise;}
     int  get_matricule(){return matricule;}
     int get_id_commande(){return id_commande;}
     QDate get_datedecreation(){return datedecreation;}
     QString get_remarque(){return remarque;}
     QString get_nom(){return nom;}

     void set_nfacture(int n){nfacture=n;}
     void set_etat(int n){ etat=n;}
     void set_tva(int n){ tva=n;}
     void set_total_tva(int n){ total_tva=n;}
     void set_total_ht(int n){ total_ht=n;}
     void set_total_ttc(int n){ total_ttc=n;}
     void set_modedereglement(int n){ modedereglement=n;}
     void set_remise(int n){ remise=n;}
     void set_matricule(int n){ matricule=n;}
     void set_id_commande(int n){ id_commande=n;}
     void set_datedecreation(QDate n){ datedecreation=n;}
     void set_remarque(QString n){ remarque=n;}
     void set_nom(QString n){ nom=n;}


};

#endif // FACTURE_H
