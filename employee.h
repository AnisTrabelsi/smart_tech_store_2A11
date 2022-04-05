#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>


class Employee
{
public:
    Employee();
    Employee(int,QString,QString,QString,QDate,int,QString,int);
    int getmatricule();
    QString getnom();
    QString getprenom();
    QString gete_mail();
    QDate getdate_embauche();
    QString getmot_de_passe();
    int getsalaire();
    int getcode();
    void setmatricule(int);
    void setnom(QString);
    void setprenom(QString);
    void sete_mail(QString);
    void setdate_embauche(QDate);
    void setmot_de_passe(QString);
    void setsalaire(int);
    void setcode(int);
    bool ajouter();
    QSqlQueryModel* afficher(int);
    QSqlQueryModel* afficherarchive();
    bool ajouterarchive();
    bool supprimer(int);
     bool supprimerarchive(int);
      bool supprimerdefinitif(int);
    bool userExists(const int& matricule) const;
    bool userExistsarchive(const int& matricule) const;
    bool modifier(int,QString,QString,QString,QDate,int,QString,int);
    Employee chercher(int matricule);
    Employee chercherarchive(int matricule);
    int cherchercode(int code);
     QSqlQueryModel* trier();
      int mdp_oub(QString code);
      int searchbycode(QString code);
      bool modifmdp(QString,int);
private:
int matricule;
QString nom,prenom,e_mail,mot_de_passe;
QDate date_embauche;
int salaire,code;
};

#endif // EMPLOYEE_H
