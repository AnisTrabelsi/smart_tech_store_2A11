#include "connection.h"
//
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("NexTech");
db.setUserName("djapa");//inserer nom de l'utilisateur
db.setPassword("djapa");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
int Connection::Authentification(QString login,QString pwd)
{
    QSqlDatabase bd = QSqlDatabase::database();

        QSqlQuery query;
        QSqlQuery query2;

        query.prepare("SELECT matricule FROM employee WHERE matricule = \'"+login+"\' AND mot_de_passe =\'"+pwd+"\'");
        query2.prepare("SELECT * FROM SYNDIQUE where LOGIN_SY=\'"+login+"\' AND MDP_SY=\'"+pwd+"\'");

        query.exec();
        query2.exec();
        if (query.next())
        {
             return 1;
        }
        /*if (query2.next())
        {
             return 2;
        }*/
        else {
            return 0;
        }



}
