#include "menu.h"
#include "facturew.h"
#include "fournisseurw.h"
#include "ui_menu.h"
#include"home.h"
#include "clientw.h"
#include "produitw.h"
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

void menu::on_factureW_clicked()
{
    factureW f(nullptr);

         this->hide();
         f.setModal(this);
         f.exec();

}

void menu::on_clientW_clicked()
{   clientw c(nullptr);

    this->hide();
    c.setModal(this);
    c.exec();


}

void menu::on_produitW_clicked()
{produitw p(nullptr);

    this->hide();
    p.setModal(this);
    p.exec();

}

void menu::on_fournisseurW_clicked()
{
    fournisseurw f(nullptr);

         this->hide();
         f.setModal(this);
         f.exec();

}
