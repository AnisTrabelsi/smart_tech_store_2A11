/*#include "historique.h"
#include "ui_historique.h"
#include "client.h"
#include "historique.h"
historique::historique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historique)
{
    ui->setupUi(this);
    client c;




   QSqlQueryModel* model=new QSqlQueryModel();
    historique h;
     model->setQuery("SELECT* FROM CLIENT ");
     model->setHeaderData(h.text, Qt::Horizontal, QObject::tr("identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr(""));

     return  model;





}

historique::~historique()
{
    delete ui;
}
*/
