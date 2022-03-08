#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QDate>
#include <QString>
#include <QSqlQueryModel>  //create table
#include <QDebug> //check errors
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
  QSqlQueryModel* afficher();
      bool userExists(const int& idfournisseur) const;
      bool modifier(int,QString,QDate,QDate,QString);
      Fournisseur chercher(int idfournisseur);
private:
    int idfournisseur;
    QString nom, description;
    QDate dateajout, dateexpr;


};

#endif // FOURNISSEUR_H
