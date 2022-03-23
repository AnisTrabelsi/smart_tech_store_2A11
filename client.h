#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <qsqlquerymodel.h>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <list>
class client
{
public:
    client();
    client(int,QString,QString,int,QString,QString);


    int getid();
    QString getnom();
    QString getprenom();
    int getnb_points();
    QString getclasse();
    QString getcadeau_client();

     void setid(int);
    void setnb_points(int);
    void setnom(QString );
    void setprenom(QString );
    void setclasse(QString );
    void setcadeau_client(QString );




    bool ajouter_client();
    QSqlQueryModel* afficher();
    bool supprimer(int);



    bool chercher_client_bool(const int& id_client) const; //traja3 bool bech nesthakoha fel modifier w supprimer //
    client chercher_client(int);

    bool modifier_client(int,QString,QString,int,QString,QString);
 QString historique(int,client);

    ///tri///
    QSqlQueryModel* trier_nom();
    QSqlQueryModel* trier_prenom();
    QSqlQueryModel* trier_nb_pts();
        QString client_du_mois();
     void afficher_un_client(int);

     //stats//
     QSqlQueryModel * stat_nb_clients();
 QSqlQueryModel * stat_classe_c();
 QSqlQueryModel * stat_classe_b();
 QSqlQueryModel * stat_classe_a();

 int total_classe_a();
 int total_classe_b();
 int total_classe_c();
 void classification_client();
 void statistique(QVector<double>* ticks,QVector<QString> *labels);
void maj_classe_b();
void maj_classe_a();


private :
    int id_client;
    QString nom ;
    QString prenom;
    int nb_points;
    QString classe;
    QString cadeau_client;


};



#endif // CLIENT_H
