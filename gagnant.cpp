#include "gagnant.h"
#include "ui_gagnant.h"
#include "client.h"
gagnant::gagnant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gagnant)
{client c;
    ui->setupUi(this);
ui->id_gagnant->setText(c.client_du_mois());



}

gagnant::~gagnant()
{
    delete ui;
}
