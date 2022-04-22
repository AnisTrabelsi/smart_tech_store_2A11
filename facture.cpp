#include "facture.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>//declarer classe
#include<QString>
#include<QDate>
#include<QTableWidget>
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
void facture::cherchers(QString &nom,QString &prenom,int idfacture ){



         QSqlQuery checkQuery;

  checkQuery.prepare("select client.nom,client.prenom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) where(facture.nfacture=:idfacture)");

checkQuery.bindValue(":idfacture",idfacture);

         if (checkQuery.exec())
         {
             if (checkQuery.next())
             {
nom=checkQuery.value(0).toString();
prenom=checkQuery.value(1).toString();


     }
         }




     }

void facture::imprimer(){
QString nom,prenom;
int y2=4600,y1=3200,y0=2000;
    facture f1=chercher(nfacture,"FACTURE");
    cherchers(nom,prenom,f1.get_nfacture());
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFileName("facture.pdf");

    QPainter painter(&printer);
    painter.begin(&printer);
        painter.setFont(QFont("Verdana",30));
     painter.drawText(200,1000,"FACTURE");
    painter.setFont(QFont("Verdana",12));
    painter.drawText(400,y0,"Nom de la compagine : NexTech");painter.drawText(6000,y0,"Date de creation : "+f1.get_datedecreation().toString());y0+=250;
    painter.drawText(400,y0,"Adresse postale: 9000"); painter.drawText(6000,y0,"id_facture : "+QString::number(f1.get_nfacture()));             y0+=250;
    painter.drawText(400,y0,"NUM : 56108211");                    y0+=250;
    painter.drawText(400,y0,"Mail :djpa@esprit.tn");y0+=250;


    painter.drawText(200,y1,"ENVOYER A :");y1+=250;
    painter.drawText(200,y1,"Nom :"+nom);y1+=250;
    painter.drawText(200,y1,"Prenom :"+prenom);y1+=250;

    painter.drawText(200,y2,"DESCRIPTION :");y2+=250;

    painter.drawText(300,y2,"tva :"+QString::number(f1.get_tva()));y2+=250;
    painter.drawText(300,y2,"total_tva :"+QString::number(f1.get_total_tva()));y2+=250;
    painter.drawText(300,y2,"total_ttc :"+QString::number(f1.get_total_ttc()));y2+=250;
    painter.drawText(300,y2,"total_ht :"+QString::number(f1.get_total_ht()));y2+=250;

    switch (f1.get_modedereglement()) {
    case 1:  painter.drawText(300,y2,"mode de reglement : espece"); ;
    case 2:painter.drawText(300,y2,"mode de reglement : cheques bancaires");  ;
    case 3: painter.drawText(300,y2,"mode de reglement : virement"); ;
    case 4:painter.drawText(300,y2,"mode de reglement : cartes de crédit");  ;
    default:painter.drawText(300,y2,"mode de reglement : inconnue"); ;

    }y2+=250;

    painter.drawText(300,y2,"remise :"+QString::number(f1.get_remise())+"%");y2+=250;






};


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
qDebug() << "User successfully deleted" << QDateTime::currentDateTime() ;
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
    query.bindValue(":datedecreation", QDateTime::currentDateTime());
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

/*
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
}*/



bool facture::copytotable(QString name,facture f){
    QSqlQuery query;
    if(name!="FACTURE_ARCHIVE"){
    query.prepare("INSERT INTO FACTURE_ARCHIVE  (NFACTURE,ETAT,TVA,TOTAL_TVA,TOTAL_HT,TOTAL_TTC,MODEDEREGLEMENT,REMISE,MATRICULE,ID_COMMANDE,DATECREATION,REMARQUE) "
                  "VALUES (:nfacture, :etat, :tva, :total_tva, :total_ht, :total_ttc,:modedereglement, :remise, :matricule, :id_commande, :datedecreation, :remarque)");
    }else
    {
    query.prepare("INSERT INTO FACTURE (NFACTURE,ETAT,TVA,TOTAL_TVA,TOTAL_HT,TOTAL_TTC,MODEDEREGLEMENT,REMISE,MATRICULE,ID_COMMANDE,DATECREATION,REMARQUE) "
                      "VALUES (:nfacture, :etat, :tva, :total_tva, :total_ht, :total_ttc,:modedereglement, :remise, :matricule, :id_commande, :datedecreation, :remarque)");



    }

    query.bindValue(":nfacture", f.get_nfacture());
    query.bindValue(":etat", f.get_etat());
    query.bindValue(":tva", f.get_tva());
    query.bindValue(":total_tva", f.get_total_tva());
    query.bindValue(":total_ht", f.get_total_ht());
    query.bindValue(":total_ttc", f.get_total_ttc());
    query.bindValue(":modedereglement", f.get_modedereglement());
    query.bindValue(":remise", f.get_remise());
    query.bindValue(":matricule", f.get_matricule());
    query.bindValue(":id_commande", f.get_id_commande());
    query.bindValue(":datedecreation", f.get_datedecreation());
    query.bindValue(":remarque", f.get_remarque());
    return query.exec();
}

bool facture::supprimer(int idfacture,QString table){
    bool success = false;
facture f1=chercher(idfacture,table);
       if (f1.get_remarque()!="user not found")
        {

if(copytotable(table,f1)){

            QSqlQuery queryDelete;
            if(table=="FACTURE"){
            queryDelete.prepare("DELETE FROM FACTURE WHERE NFACTURE=:NFACTURE");}
            else{
                queryDelete.prepare("DELETE FROM FACTURE_ARCHIVE WHERE NFACTURE=:NFACTURE");

            }
            queryDelete.bindValue(":NFACTURE", idfacture);
            success = queryDelete.exec();

            if(!success)
                qDebug() << "Delete user failure:" << queryDelete.lastError();
            else
                qDebug() << "User successfully deleted" << nfacture;


        }}
        else
        {
            qDebug() << "Error deleting user: user does not exist";
        }

        return success;
}


facture facture::chercher(int idfacture,QString table){

    facture F1;

         QSqlQuery checkQuery;
if(table=="FACTURE"){
         checkQuery.prepare("select FACTURE.*,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) AND (facture.nfacture=:idfacture)");
}else{
    checkQuery.prepare("select FACTURE_ARCHIVE.*,client.nom from FACTURE_ARCHIVE INNER JOIN COMMANDE on (commande.id_commande=FACTURE_ARCHIVE.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) and(FACTURE_ARCHIVE.nfacture=:idfacture) ");


}
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
                  F1.set_nom(checkQuery.value(12).toString());


     }
         }
         else
         {
             qDebug() << "User not found:" << checkQuery.lastError();
         F1.set_remarque("user not found");
         }



 return F1;
     }

//recherche par matricule commun
//regroupement
//

bool facture::modifier(int nfacture,int etat,int tva,int total_tva,int total_ht,int total_ttc,int modedereglement,int remise,int matricule,int id_commande,QDate datedecreation,QString remarque)
{
    QSqlQuery query;
    query.prepare("update FACTURE set ETAT=:etat,TVA=:tva,TOTAL_TVA=:total_tva,TOTAL_HT=:total_ht,TOTAL_TTC=:total_ttc,MODEDEREGLEMENT=:modedereglement,REMISE=:remise,MATRICULE=:matricule,ID_COMMANDE=:id_commande,DATECREATION=:datedecreation,REMARQUE=:remarque where NFACTURE=:nfacture");
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



QSqlQueryModel* facture::trier()
{
   QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("select FACTURE.*,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) ORDER BY client.nom ");
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
         model->setHeaderData(12, Qt::Horizontal, QObject::tr("nom"));



   return model;
}


QSqlQueryModel* facture::afficherho(QString name,int a)
{
   QSqlQueryModel* model=new QSqlQueryModel();
   if(name=="facture"){
       if(a==0){
         model->setQuery("select FACTURE.*,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) ORDER BY FACTURE.DATECREATION ");
   }else if(a==1){
           model->setQuery("select FACTURE.*,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) ORDER BY FACTURE.TVA");


       }else {

           model->setQuery("select FACTURE.*,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) ORDER BY FACTURE.TOTAL_HT ");

       }


   }else
   {         model->setQuery("select FACTURE_ARCHIVE.*,client.nom from FACTURE_ARCHIVE INNER JOIN COMMANDE on (commande.id_commande=FACTURE_ARCHIVE.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) ");

   }
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
         model->setHeaderData(12, Qt::Horizontal, QObject::tr("nom"));



   return model;
}





/*
QSqlQueryModel* facture::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("select FACTURE.*,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) ");
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
         model->setHeaderData(12, Qt::Horizontal, QObject::tr("nom"));



   return model;
}*/



QSqlQueryModel* facture::afficherpar(QString name,int a)
{
   QSqlQueryModel* model=new QSqlQueryModel();
   QSqlQuery query;
   query.prepare("select FACTURE.*,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) and client.nom =:name ");
   query.bindValue(":name", name);
   query.exec();
model->setQuery(query);
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
         model->setHeaderData(12, Qt::Horizontal, QObject::tr("nom"));



   return model;
}

void facture::regrouper(QString name){
    QSqlQuery query,query1,query2;    facture F1;
   QSqlQueryModel* model=new QSqlQueryModel();
    query1.prepare("select facture.nfacture, facture.modedereglement,commande.id_commande,facture.remarque,client.nom from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) and client.nom =:name ");
    query1.bindValue(":name", name);
    query1.exec();

    query.prepare("select sum(facture.tva),sum(facture.total_tva),sum(facture.total_ht),sum(facture.total_ttc),sum(facture.remise) from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) and client.nom =:name  ");
    query.bindValue(":name", name);
    query.exec();

    query2.prepare("select count(facture.nfacture) from FACTURE INNER JOIN COMMANDE on (commande.id_commande=facture.id_commande) INNER JOIN CLIENT ON (client.id_client=commande.id_client) and client.nom =:name ");
    query2.bindValue(":name", name);
    query2.exec();
if(query1.next()){
    nfacture=(query1.value(0).toInt() );

   // F1.set_etat(query.value(1).toInt() );
     modedereglement=(query1.value(1).toInt() );
 matricule=1000;
   id_commande=(query1.value(2).toInt() );
    //F1.set_datedecreation();
set_datedecreation(QDate::currentDate());
   remarque=(query1.value(3).toString() );

}

    if (query.next())
    {

     tva=(query.value(0).toInt() );
     total_tva=(query.value(1).toInt() );
    total_ht=(query.value(2).toInt() );
     total_ttc=(query.value(3).toInt() );

    remise=( query.value(4).toInt());

}
    if(query2.next()){
int i=query2.value(0).toInt();
  model->setQuery(query1);
for (int j=0;j<i;j++) {

 int a=model->data(model->index(j,0,QModelIndex()),Qt::DisplayRole).toInt();


supprimer(a,"FACTURE");
}
ajouter();


}

    };

