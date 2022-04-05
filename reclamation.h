#ifndef RECLAMATION_H
#define RECLAMATION_H


#include <QDate>
#include <QString>
#include <QSqlQueryModel>  //affichage (interaction entre code bd et qt)
#include <QDebug> //debug
#include <QSqlError> //afficher les erreurs spécifiquement
class reclamation
{
public:
    reclamation();
    reclamation(int,QDate,QString,int);
    int getid();
    QDate getdatereclamation();
    QString getdescription();
     int getidfournisseur();
    void setid(int);
    void setdatereclamation(QDate);
    void setdescription(QString);
       void setidfournisseur(int);
  bool ajouter();

    bool supprimer(int);
      bool archiver(int);
  QSqlQueryModel* afficher();
      bool userExists(const int& idreclamation) const;
      reclamation chercher(int idreclamation);
private:
    int idreclamation, idfournisseur;
    QString description;
    QDate datereclamation;


};

#endif // RECLAMATION_H
