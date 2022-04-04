#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>


#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
class Employee
{
public:
    Employee();
    Employee(int,QString,QString,QString,QDate,int,QString);
    int getmatricule();
    QString getnom();
    QString getprenom();
    QString gete_mail();
    QDate getdate_embauche();
    QString getmot_de_passe();
    int getsalaire();
    void setmatricule(int);
    void setnom(QString);
    void setprenom(QString);
    void sete_mail(QString);
    void setdate_embauche(QDate);
    void setmot_de_passe(QString);
    void setsalaire(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool userExists(const int& matricule) const;
    bool modifier(int,QString,QString,QString,QDate,int,QString);
    Employee chercher(int matricule);
     QSqlQueryModel* trier();
     // QSqlQueryModel * statistic();
      void stat();
private:
int matricule;
QString nom,prenom,e_mail,mot_de_passe;
QDate date_embauche;
int salaire;
};

#endif // EMPLOYEE_H
