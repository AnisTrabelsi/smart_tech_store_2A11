#pragma once
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;

public:
    Connection();
    bool createconnect();
    void closeConnection();
};
