#include "commandew.h"
#include "ui_commandew.h"

commandeW::commandeW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commandeW)
{
    ui->setupUi(this);
}

commandeW::~commandeW()
{
    delete ui;
}
