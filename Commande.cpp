#include "Commande.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>

Commande::Commande()
{
    idCommande = 0;
    mode_Livraison = "";
    quantity = 0;
    Paiment_Valide = 0;
}
Commande::Commande(int id, int num, int quant, int Paiment, QString Livraison, QDate date)
{
    this->idCommande = id;
    this->mode_Livraison = Livraison;
    this->date_Commande = date;
    this->num_Tel = num;
    this->quantity = quant;
    this->Paiment_Valide = Paiment;
}
int Commande::getIdCommande()
{
    return idCommande;
}
int Commande::getNumTel()
{
    return num_Tel;
}

int Commande::getQuantity()
{
    return quantity;
}

int Commande::getPaimentValide()
{
    return Paiment_Valide;
}

QString Commande::getModeLivraison()
{
    return mode_Livraison;
}

QDate Commande::getDateCommande()
{
    return date_Commande;
}

void Commande::setIdCommande(int a)
{
    idCommande = a;
}

void Commande::setNumTel(int a)
{
    num_Tel = a;
}

void Commande::setQuantity(int a)
{
    quantity = a;
}

void Commande::setPaimentValide(int a)
{
    Paiment_Valide = a;
}

void Commande::setModeLivraison(QString a)
{
    mode_Livraison = a;
}

void Commande::setDateCommande(QDate a)
{
    date_Commande = a;
}

bool Commande::ajouterCommande()
{

    QSqlQuery query;
    //QString idcommnade_string = QString::number(idCommande);
    query.prepare("INSERT INTO Commande (ID_COMMANDE,DATE_COMMANDE,MODE_LIVRAISON,NUM_TEL,ID_CLIENT,PAIMENT_VALIDE) "
                  "VALUES (:idCommande,:date_Commande,:mode_Livraison, :num_Tel, :quantity , :paiment)");
    query.bindValue(":idCommande", idCommande);
    query.bindValue(":mode_Livraison", mode_Livraison);
    query.bindValue(":date_Commande", date_Commande);
    query.bindValue(":num_Tel", num_Tel);
    query.bindValue(":quantity", quantity);
     query.bindValue(":paiment", Paiment_Valide);
    return query.exec();
}
bool Commande::ajouterCommandeA()
{

    QSqlQuery query;
    //QString idcommnade_string = QString::number(idCommande);
    query.prepare("INSERT INTO COMMANDEA (ID_COMMANDE,DATE_COMMANDE,MODE_LIVRAISON,NUM_TEL,ID_CLIENT,PAIMENT_VALIDE) "
                  "VALUES (:idCommande,:date_Commande,:mode_Livraison, :num_Tel, :quantity , :paiment)");
    query.bindValue(":idCommande", idCommande);
    query.bindValue(":mode_Livraison", mode_Livraison);
    query.bindValue(":date_Commande", date_Commande);
    query.bindValue(":num_Tel", num_Tel);
    query.bindValue(":quantity", quantity);
     query.bindValue(":paiment", Paiment_Valide);
    return query.exec();
}
bool Commande::modifier_Commande(int id, int paiment, int Tel, int quant, QString Livraison, QDate date)
{
    QSqlQuery query;
    query.prepare("update COMMANDE set id_Commande=:idCommande,mode_Livraison=:mode_Livraison,date_Commande=:date_Commande,num_Tel=:num_Tel,PAIMENT_VALIDE=:paiment,id_client=:quantity");
    query.bindValue(":idCommande", id);
    query.bindValue(":mode_Livraison", Livraison);
    query.bindValue(":date_Commande", date);
    query.bindValue(":num_Tel", Tel);
    query.bindValue(":quantity", quant);
    query.bindValue(":paiment", paiment);
    return query.exec();
}

bool Commande::supprimerCommande(int id)
{
    Commande c2;
    bool success = false;

    if (CommandeExists(id))
    {
        c2=chercher_Commande(id);
        c2.ajouterCommandeA();
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Commande WHERE id_Commande=:idCommande");
        queryDelete.bindValue(":idCommande", id);

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
QSqlQueryModel *Commande::afficherCommande(int a)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT* FROM Commande");
    if(a==1)
    {
          model->setQuery("SELECT* FROM Commande order by NUM_TEL");
}
    else if(a==2)
    {
        model->setQuery("SELECT* FROM Commande order by ID_CLIENT");
    }
    else if (a==3)
    {
        model->setQuery("SELECT* FROM Commande order by ID_COMMANDE");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mode_Livraison"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero_Tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Paiment Valide"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Commande"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CLIENT"));

    return model;
}

bool Commande::CommandeExists(const int &id) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id_Commande FROM Commande WHERE id_Commande=:idCommande");
    checkQuery.bindValue(":idCommande", id);

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
Commande Commande::chercher_Commande(const int &id)
{

    Commande C1;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Commande WHERE id_Commande = :idCommande");
    checkQuery.bindValue(":idCommande", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            C1.setIdCommande(checkQuery.value(0).toInt());
            C1.setModeLivraison(checkQuery.value(2).toString());
            C1.setDateCommande(checkQuery.value(1).toDate());
            C1.setNumTel(checkQuery.value(3).toInt());
            C1.setPaimentValide(checkQuery.value(5).toInt());
            C1.setQuantity(checkQuery.value(4).toInt());

            return C1;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
    }
    C1.setModeLivraison("vide");
    return C1;
}


