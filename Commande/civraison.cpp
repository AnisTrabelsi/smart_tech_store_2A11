#include "civraison.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
CIVRAISON::CIVRAISON()
{
    idlivraison=0;
    code_postal=0;
    Region="";
    Ville="";
}
CIVRAISON::CIVRAISON(int a,int b,QString c,QString d,QDate e)
{
    idlivraison=a;
    code_postal=b;
    Region=c;
    Ville=d;
    date_livraison=e;
}

int CIVRAISON::getIdLivraison()
{
    return idlivraison;
}
int CIVRAISON::getCodePostal()
{
    return code_postal;
}
QString CIVRAISON::getRegion()
{
    return Region;
}
QString CIVRAISON::getVille()
{
    return Ville;
}
QDate CIVRAISON::getDateL()
{
    return date_livraison;
}

void CIVRAISON::setIdLivraison(int a)
{
    idlivraison=a;
}
void CIVRAISON::setCodePostal(int a)
{
    code_postal=a;
}
void CIVRAISON::setRegion(QString a)
{
    Region=a;
}
void CIVRAISON::setVille(QString a)
{
    Ville=a;
}
void CIVRAISON::setDateL(QDate a)
{
    date_livraison=a;
}
bool CIVRAISON::ajouterLivraison()
{
    QSqlQuery query;
    query.prepare("INSERT INTO LIVRAISON (ID_LIVRAISON,REGION,VILLE,CODE_POSTAL,DATE_DE_LIVRAISON) "
                  "VALUES (:idlivraison,:Region,:Ville,:code,:date_livraison)");
    query.bindValue(":idlivraison",idlivraison);
    query.bindValue(":Region",Region);
    query.bindValue(":Ville",Ville);
    query.bindValue(":code",code_postal);
    query.bindValue(":date_livraison",date_livraison);
    return query.exec();

}
