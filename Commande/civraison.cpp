#include "civraison.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>

CIVRAISON::CIVRAISON()
{
    idlivraison=0;
}
CIVRAISON::CIVRAISON(int a,int b,QString c,QString d,QDate e)
{
    this->idlivraison=a;
    this->code_postal=b;
    this->Region=c;
    this->Ville=d;
    this->date_livraison=e;
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
    QSqlQuery query1;
    query1.prepare("INSERT INTO LIVRAISON (ID_LIVRAISON,REGION,VILLE,CODE_POSTAL,DATE_DE_LIVRAISON) "
                  "VALUES (:idlivraison,:Region,:Ville,:code,:date_livraison)");
    query1.bindValue(":idlivraison",idlivraison);
    query1.bindValue(":Region",Region);
    query1.bindValue(":Ville",Ville);
    query1.bindValue(":code",code_postal);
    query1.bindValue(":date_livraison",date_livraison);
    return query1.exec();

}
