#include "categoriew.h"
#include "ui_categoriew.h"

Categoriew::Categoriew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categoriew)
{
    ui->setupUi(this);
}

Categoriew::~Categoriew()
{
    delete ui;
}
