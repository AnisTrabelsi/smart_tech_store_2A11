#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include "fournisseur.h"
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

ui->view->setModel(F.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valider_clicked()
{
    int idfournisseur=ui->idfournisseur->text().toInt();
  QString nom=ui->nom->text();
  QDate dateajout=ui->dateajout->date();
  QDate dateexpr=ui->dateexpr->date();
  QString description=ui->description->text();
  Fournisseur F(idfournisseur,nom,dateajout,dateexpr,description);
  bool test=F.ajouter();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher());
    }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      ui->idfournisseur->clear();
      ui->nom->clear();
      ui->dateajout->clear();
       ui->dateexpr->clear();
        ui->description->clear();


}



void MainWindow::on_pb_supprimer_clicked()
{
   Fournisseur F1; F1.setid(ui->supp->text().toInt());
        bool test=F1.supprimer(F1.getid());

        if(test)

      {
      QMessageBox::information(nullptr, QObject::tr("supprimer un fournisseur"),
                        QObject::tr("Employee supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
ui->view->setModel(F.afficher());
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        ui->supp->clear();


}
