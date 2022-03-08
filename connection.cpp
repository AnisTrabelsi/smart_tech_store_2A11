#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("NexTech");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("1001");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
