#include "connexion.h"
///test test 123//
connexion::connexion()
{

}

bool connexion::ouvrirconnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Nextech");
db.setUserName("mahmoud");//inserer nom de l'utilisateur
db.setPassword("09092001");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
