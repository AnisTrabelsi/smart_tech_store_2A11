#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>  //affichage (interaction entre code bd et qt)
#include <QDebug> //debug
#include <QSqlError> //afficher les erreurs spécifiquement
class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,QDate,QDate,QString);
    int getid();
    QString getnom();
    QDate getdateajout();
    QDate getdateexpr();
    QString getdescription();
    void setid(int);
        void setnom(QString);
    void setdateajout(QDate);
    void setdateexpr(QDate);
    void setdescription(QString);
  bool ajouter();
    bool supprimer(int);
      bool supprimersys();
  QSqlQueryModel* afficher();
    QSqlQueryModel* trier();
      bool userExists(const int& idfournisseur) const;
        bool userExistsys(const QDate& dateexpr) const;
      bool modifier(int,QString,QDate,QDate,QString);
      Fournisseur chercher(int idfournisseur);
       int cherchersys();
private:
    int idfournisseur;
    QString nom, description;
    QDate dateajout, dateexpr;


};

#endif // FOURNISSEUR_H
