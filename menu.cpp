#include "menu.h"
#include "ui_menu.h"
#include"home.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_employeeW_clicked()
{

home h(nullptr);

     this->hide();
     h.setModal(this);
     h.exec();
  }
