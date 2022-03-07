#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <qsqlquerymodel.h>
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



    bool chercher_client_bool(const int& id_client) const;; //traja3 bool bech nesthakoha fel modifier w supprimer //
    client chercher_client(int);


    bool modifier_client(int,QString,QString,int,QString,QString);

    QSqlQueryModel* trier_nom();
    QSqlQueryModel* trier_prenom();
    QSqlQueryModel* trier_nb_pts();

private :
    int id_client;
    QString nom ;
    QString prenom;
    int nb_points;
    QString classe;
    QString cadeau_client;


};

#endif // CLIENT_H
