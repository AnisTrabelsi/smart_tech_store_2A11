#include "categorie.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>


Categorie::Categorie()
{
    ID_CATEGORIE = 0;
    LIBELLE = "";
    REMISE = 0;

}
Categorie::Categorie(int id, QString LIBELLE,int REMISE)
{
    this->ID_CATEGORIE = id;
    this->LIBELLE = LIBELLE;
    this->REMISE = REMISE;
}
int Categorie::getID()
{
    return ID_CATEGORIE;
}
int Categorie::getREMISE()
{
    return REMISE;
}

QString Categorie::getLIBELLE()
{
    return LIBELLE;
}

void Categorie::setID(int a)
{
    ID_CATEGORIE = a;
}


void Categorie::setREMISE(int a)
{
    REMISE = a;
}


void Categorie::setLIBELLE(QString a)
{
    LIBELLE = a;
}

bool Categorie::ajouterCategorie()
{

    QSqlQuery query;
    //QString idcommnade_string = QString::number(ID_CATEGORIE);
    query.prepare("INSERT INTO Categorie (ID_Categorie,LIBELLE,REMISE) "
                  "VALUES (:ID_CATEGORIE,:LIBELLE,:REMISE)");
    query.bindValue(":ID_CATEGORIE", ID_CATEGORIE);
    query.bindValue(":LIBELLE", LIBELLE);
    query.bindValue(":REMISE", REMISE);
    return query.exec();
}
bool Categorie::ajouterCategorieA()
{

    QSqlQuery query;
    //QString idcommnade_string = QString::number(ID_CATEGORIE);
    query.prepare("INSERT INTO CategorieA (ID_Categorie,LIBELLE,REMISE) "
                  "VALUES (:ID_CATEGORIE,:LIBELLE,:REMISE)");
    query.bindValue(":ID_CATEGORIE", ID_CATEGORIE);
    query.bindValue(":LIBELLE", LIBELLE);
    query.bindValue(":REMISE", REMISE);;
    return query.exec();
}
bool Categorie::modifier_Categorie(int id, QString LIBELLE,int REMISE)
{
    QSqlQuery query;
    query.prepare("update Categorie set ID_CATEGORIE=:ID_CATEGORIE,LIBELLE=:LIBELLE,REMISE=:REMISE");
    query.bindValue(":ID_CATEGORIE", id);
    query.bindValue(":LIBELLE", LIBELLE);
    query.bindValue(":REMISE",REMISE);
    return query.exec();
}

bool Categorie::supprimerCategorie(int id)
{
    Categorie c2;
    bool success = false;

    if (CategorieExists(id))
    {
        c2=chercher_Categorie(id);
        c2.ajouterCategorieA();
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Categorie WHERE id_Categorie=:ID_CATEGORIE");
        queryDelete.bindValue(":ID_CATEGORIE", id);

        success = queryDelete.exec();

        if (!success)
            qDebug() << "Delete user failure:" << queryDelete.lastError();
        else
            qDebug() << "User successfully deleted" << id;
    }
    else
    {
        qDebug() << "Error deleting user: user does not exist";
    }

    return success;
}
QSqlQueryModel *Categorie::afficherCategorie(int a)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM Categorie");
    if(a==1)
    {
          model->setQuery("SELECT* FROM Categorie order by LIBELLE");
}
    else if(a==2)
    {
        model->setQuery("SELECT* FROM Categorie order by REMISE");
    }
    else if (a==3)
    {
        model->setQuery("SELECT* FROM Categorie order by ID_Categorie");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REMISE"));

    return model;
}

bool Categorie::CategorieExists(const int &id) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id_Categorie FROM Categorie WHERE id_Categorie=:ID_CATEGORIE");
    checkQuery.bindValue(":ID_CATEGORIE", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
    }

    return exists;
}
Categorie Categorie::chercher_Categorie(const int &id)
{

    Categorie C1;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM CATEGORIE WHERE id_Categorie = :ID_CATEGORIE");
    checkQuery.bindValue(":ID_CATEGORIE", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            C1.setID(checkQuery.value(0).toInt());
            C1.setLIBELLE(checkQuery.value(1).toString());
            C1.setREMISE(checkQuery.value(2).toInt());

            return C1;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
    }
    C1.setLIBELLE("vide");
    return C1;
}


