#include "incendie.h"
#include "ui_incendie.h"
#include "arduino.h"
incendie::incendie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incendie)
{
    ui->setupUi(this);
}

incendie::~incendie()
{
    delete ui;
}

void incendie::on_stop_clicked()
{
     A.write_to_arduino("3"); //envoyer 1 à arduino
}
