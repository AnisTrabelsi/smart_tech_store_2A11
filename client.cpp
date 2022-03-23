 #include "client.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include "string.h"
#include <QFile>
#include <QTextStream>
#include <QMediaPlayer>
#include <QTextStream>
client::client()
{
id_client =0;
nom="";
prenom="";
classe=""; //  aana 3 types : ABC par defaut lclient yabda classe c //
nb_points=0;
cadeau_client="";

}







//constructor//
client::client(int id_client,QString nom,QString prenom,int nb_points,QString classe,QString cadeau_client)
{

this->id_client=id_client;
this->nom=nom;
this->prenom=prenom;
this->nb_points=nb_points;
this->classe=classe;
this->cadeau_client=cadeau_client;
}


//getter  w setter //
int client::getid() { return id_client ;}
QString client::getnom() {  return nom; }
QString client::getprenom() {return prenom;}
int client::getnb_points() {return nb_points;}
QString client::getclasse(){return (classe);}
QString client::getcadeau_client(){return (cadeau_client);}

void client::setid(int id_client) { this->id_client=id_client;}
void client::setnb_points(int nb_points) { this->nb_points=nb_points;}
void client::setnom(QString nom){ this->nom=nom;}
void client::setprenom(QString prenom){ this->prenom=prenom;}
void client::setclasse(QString classe){ this->classe=classe;}
void client::setcadeau_client(QString cadeau_client){ this->cadeau_client=cadeau_client;}


//////////////////////cruds ////////////
bool client::ajouter_client()
{



    QSqlQuery query;

    QString id_string=QString::number(id_client);
    QString nb_points_string=QString::number(nb_points);

    query.prepare("INSERT INTO client (id_client,nom,prenom,nb_points,classe,cadeau_client) "
                  "VALUES (:id_client, :nom, :prenom, :nb_points, :classe, :cadeau_client)");
    query.bindValue(0,id_string);
    query.bindValue(1, nom);
    query.bindValue(2 ,prenom);
    query.bindValue(3,"0");
    query.bindValue(4 ,"c");
    query.bindValue(5 ,"rien");

    client c;
    int cas;
    cas=1;
   /* historique(cas,c);*/


    return  query.exec();

}





bool client:: supprimer(int id)
{
    QSqlQuery query;
client c1;

if(c1.chercher_client_bool(id)==true)
{



      ///archivage//

    client c;
   c=c1.chercher_client(id);

   QString nom_client_file= c.nom;
   QString prenom_client_file= c.prenom;
   QString nom_fichier=QString("%1_%2").arg(nom_client_file,prenom_client_file);//fichier b esm lclient///


    // Création d'un objet QFile
    QFile file(nom_fichier+".txt");
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
qDebug() << "fichier echouée:" << query.lastError();
    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream flux(&file);
    // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
    flux.setCodec("UTF-8");
    // Écriture des différentes lignes dans le fichier
    flux <<"'le nom du'id du  client est :  " << c.getid() <<" \n le nom du client est :  " << c.getnom() <<" \n prenom est : " <<c.getprenom() <<"\n nombre des points est  :  " <<c.getnb_points() <<"\n sa classe est  :  " <<c.getclasse()  <<  endl;

///historique//
    int cas;
    cas=1;
    /*historique(cas,c1);*/



//suppression//
    query.prepare("DELETE  FROM client where id_client=:id ");
query.bindValue(0, id);
return query.exec();

}

else
{QMessageBox msgBox;
          msgBox.setText("client introuvable !");
       msgBox.exec();
    return false;}

}



bool client::modifier_client(int id_client, QString nom , QString prenom,int nb_pts, QString classe , QString cadeau_client)
  {QSqlQuery query;
  query.prepare("update client set nom=:nom,prenom=:prenom,nb_points=:nb_points,classe=:classe,cadeau_client=:cadeau_client WHERE id_client=:id_client");


  query.bindValue(":id_client",id_client);
   query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":nb_points", nb_pts);
     query.bindValue(":classe", classe);
     query.bindValue(":cadeau_client",cadeau_client);

      ///historique//
       client c1;
       c1=c1.chercher_client(id_client);
         int cas;
         cas=3;
         /*historique(cas,c1);*/

  return    query.exec();
}



QSqlQueryModel* client::afficher()
{


    ////classification tee clients////
   /* fel ligne hedha maach yheb yekhdm*/
    QSqlQuery q1;

    q1.exec("update client set classe='b' WHERE (select count(*) from commande where (client.id_client = commande.id_client))>=2");



    QSqlQuery q2;

    q2.exec("update client set classe='a' WHERE (select count(*) from commande where (client.id_client = commande.id_client))>=4");




///////aafichage///
QSqlQueryModel* model=new QSqlQueryModel();


  model->setQuery("SELECT* FROM CLIENT ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre des points "));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe du client "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("cadeau client"));
  return  model;


}







//////////////////////metiers ////////////

client  client::chercher_client(int id_client)
 {

        client c1;

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM CLIENT  WHERE id_client = :id_client");
        checkQuery.bindValue(":id_client",id_client);

        if (checkQuery.exec())
        {

            if (checkQuery.next())
            { QMessageBox msgBox;
                msgBox.setText("client trouvé ! ");
                msgBox.exec();
                c1.setid(checkQuery.value(0).toInt());
               c1.setnom(checkQuery.value(1).toString());
                c1.setprenom(checkQuery.value(2).toString());
                c1.setnb_points(checkQuery.value(3).toInt());
                c1.setclasse(checkQuery.value(4).toString());
                c1.setcadeau_client(checkQuery.value(5).toString());



                return c1 ;
            }
        }
        else
        {
            qDebug() << "User not found:" << checkQuery.lastError();
        }
c1.setnom("vide");
return c1;
      }



bool client::chercher_client_bool(const int& id_client) const
 {



    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id_client FROM client WHERE id_client=:id_client");
    checkQuery.bindValue(":id_client", id_client);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            QMessageBox msgBox;
            msgBox.setText("client trouvé! ");
            msgBox.exec();
            qDebug() << " found:" << checkQuery.lastError();
            return  true;
        }
    }
    else
    {QMessageBox msgBox;
        msgBox.setText("client introuvable ! ");
        msgBox.exec();
        qDebug() << " not found:" << checkQuery.lastError();
        return  false;
    }


      }











/****tr**********/

QSqlQueryModel* client::trier_nom()
{

QSqlQueryModel* model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM CLIENT order by nom");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre des points "));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe du client "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("cadeau client"));
  return  model;


}

QSqlQueryModel* client::trier_prenom()
{

QSqlQueryModel* model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM CLIENT order by prenom");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre des points "));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe du client "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("cadeau client"));
  return  model;


}



QSqlQueryModel* client::trier_nb_pts()
{

QSqlQueryModel* model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM CLIENT order by nb_points DESC");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre des points "));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe du client "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("cadeau client"));
  return  model;


}

///******client_du_mois***/
   QString client::client_du_mois()
{client c1;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT nom,prenom FROM  (SELECT nom,prenom FROM client  ORDER BY dbms_random.value) WHERE rownum =1");



    QString nom_gagnant;
     QString prenom_gagnant;
                 checkQuery.bindValue(":prenom",prenom_gagnant);
                 checkQuery.bindValue(":nom", nom_gagnant);



     if (checkQuery.exec())
     {
         if (checkQuery.next())
         {
             QMediaPlayer * music = new QMediaPlayer();
             music->setMedia(QUrl("qrc:/sound/congratulations.wav"));
             music->play();


             QString nom_gagnant= checkQuery.value(0).toString();
             QString prenom_gagnant= checkQuery.value(1).toString();

             QString message =QString("    %1 %2 ").arg(prenom_gagnant,nom_gagnant);


             return message ;

             qDebug() << " found:" << checkQuery.lastError();

         }
     }





}






void client::afficher_un_client(int id_client)
  {QSqlQueryModel* model=new QSqlQueryModel();
client c1;
  c1=c1.chercher_client(id_client);



  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre des points "));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe du client "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("cadeau client"));



}






void client::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select nom||' '||prenom from client");
    while (q.next())
    {
        QString classe = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<classe;
    }
}



QString client:: historique(int a,client c)
{  QString text;
    if(a==1)
      { text=QString(" le client  '%1   '%2' a ete ajouté \n ").arg(c.getnom(),c.prenom);}

    else if(a==2)
      { text=QString(" le client  '%1   '%2' a ete modifié \n ").arg(c.getnom(),c.prenom);}


else { text=QString(" le client  '%1   '%2' a ete supprimé \n ").arg(c.getnom(),c.prenom);}


    return text;
}







