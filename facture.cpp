#include "facture.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
#include<QString>
#include<QDate>
facture::facture()
{
     nfacture=0;
     etat=0;
     tva=0;
     total_tva=0;
     total_ht=0;
     total_ttc=0;
     modedereglement=0;
     remise=0;
     matricule=0;

     id_commande=0;
}

facture::facture(int nfacture,int etat,int tva,int total_tva,int total_ht,int total_ttc,int modedereglement,int remise,int matricule,int id_commande,QDate datedecreation,QString remarque){
    this->nfacture=nfacture;
    this->etat=etat;
    this->tva=tva;
    this->total_tva=total_tva;
    this->total_ht=total_ht;
    this->total_ttc=total_ttc;
    this->modedereglement=modedereglement;
    this->remise=remise;
    this->matricule=matricule;
    this->id_commande=id_commande;
    this->datedecreation=datedecreation;
    this->remarque=remarque;

}


bool facture::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FACTURE (NFACTURE,ETAT,TVA,TOTAL_TVA,TOTAL_HT,TOTAL_TTC,MODEDEREGLEMENT,REMISE,MATRICULE,ID_COMMANDE,DATECREATION,REMARQUE) "
                  "VALUES (:nfacture, :etat, :tva, :total_tva, :total_ht, :total_ttc,:modedereglement, :remise, :matricule, :id_commande, :datedecreation, :remarque)");

    query.bindValue(":nfacture", nfacture);
    query.bindValue(":etat", etat);
    query.bindValue(":tva", tva);
    query.bindValue(":total_tva", total_tva);
    query.bindValue(":total_ht", total_ht);
    query.bindValue(":total_ttc", total_ttc);
    query.bindValue(":modedereglement", modedereglement);
    query.bindValue(":remise", remise);
    query.bindValue(":matricule", matricule);
    query.bindValue(":id_commande", id_commande);
    query.bindValue(":datedecreation", datedecreation);
    query.bindValue(":remarque", remarque);
    return query.exec();
}

bool facture:: userExists(const int& nfacture) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT nfacture FROM FACTURE WHERE NFACTURE=:nfacture");
    checkQuery.bindValue(":nfacture", nfacture);

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


bool facture::supprimer(int idfacture){
    bool success = false;

       if (userExists(idfacture))
        {
            QSqlQuery queryDelete;
            queryDelete.prepare("DELETE FROM FACTURE WHERE NFACTURE=:NFACTURE");
            queryDelete.bindValue(":NFACTURE", idfacture);
            success = queryDelete.exec();

            if(!success)
                qDebug() << "Delete user failure:" << queryDelete.lastError();
            else
                qDebug() << "User successfully deleted" << nfacture;


        }
        else
        {
            qDebug() << "Error deleting user: user does not exist";
        }

        return success;
}


facture facture::chercher(int idfacture){

    facture F1;

         QSqlQuery checkQuery;
         checkQuery.prepare("SELECT * FROM FACTURE WHERE NFACTURE=:idfacture");
         checkQuery.bindValue(":idfacture",idfacture);

         if (checkQuery.exec())
         {
             if (checkQuery.next())
             {

                  F1.set_nfacture(checkQuery.value(0).toInt() );
                  F1.set_etat(checkQuery.value(1).toInt() );
                  F1.set_tva(checkQuery.value(2).toInt() );
                  F1.set_total_tva(checkQuery.value(3).toInt() );
                  F1.set_total_ht(checkQuery.value(4).toInt() );
                  F1.set_total_ttc(checkQuery.value(5).toInt() );
                  F1.set_modedereglement(checkQuery.value(6).toInt() );
                  F1.set_remise( checkQuery.value(7).toInt());
                  F1.set_matricule(checkQuery.value(8).toInt() );
                  F1.set_id_commande(checkQuery.value(9).toInt() );
                  F1.set_datedecreation( checkQuery.value(10).toDate());
                  F1.set_remarque(checkQuery.value(11).toString() );


             }
         }
         else
         {
             qDebug() << "User not found:" << checkQuery.lastError();
         F1.set_remarque("user not found");
         }



 return F1;
     }


bool facture::modifier(int nfacture,int etat,int tva,int total_tva,int total_ht,int total_ttc,int modedereglement,int remise,int matricule,int id_commande,QDate datedecreation,QString remarque)
{
    QSqlQuery query;
    query.prepare("update FACTURE set NFACTURE=:nfacture,ETAT=:etat,TVA=:tva,TOTAL_TVA=:total_tva,TOTAL_HT=:total_ht,TOTAL_TTC=:total_ttc,MODEDEREGLEMENT=:modedereglement,REMISE=:remise,MATRICULE=:matricule,ID_COMMANDE=:id_commande,DATECREATION=:datedecreation,REMARQUE=:remarque");
    query.bindValue(":nfacture", nfacture);
    query.bindValue(":etat", etat);
    query.bindValue(":tva", tva);
    query.bindValue(":total_tva", total_tva);
    query.bindValue(":total_ht", total_ht);
    query.bindValue(":total_ttc", total_ttc);
    query.bindValue(":modedereglement", modedereglement);
    query.bindValue(":remise", remise);
    query.bindValue(":matricule", matricule);
    query.bindValue(":id_commande", id_commande);
    query.bindValue(":datedecreation", datedecreation);
    query.bindValue(":remarque", remarque);
    return    query.exec();
}


QSqlQueryModel* facture::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM FACTURE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("nfacture"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("tva"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("total_tva"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("total_ht"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("total_ttc"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("modedereglement"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("remise"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("matricule"));
         model->setHeaderData(9, Qt::Horizontal, QObject::tr("id_commande"));
         model->setHeaderData(10, Qt::Horizontal, QObject::tr("datedecreation"));
         model->setHeaderData(11, Qt::Horizontal, QObject::tr("remarque"));


   return model;
}
