#pragma once
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{


public:
    Connection();
    bool createconnect();
    void closeConnection();
};
