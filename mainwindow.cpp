#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlDatabase>
#include <QtCore>
#include <QtWidgets/QApplication>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_Ref_produit->setValidator(new QIntValidator(0, 9999999, this));
    ui->la_categorie->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_fournisseur->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_Prix->setValidator(new QIntValidator(0, 9999999, this));
    ui->la_Quantite->setValidator(new QIntValidator(0, 9999999, this));

    ui->Ref_produit_mod->setValidator(new QIntValidator(0, 9999999, this));
    ui->categorie_mod->setValidator(new QIntValidator(0, 9999999, this));
    ui->fournisseur_mod->setValidator(new QIntValidator(0, 9999999, this));
    ui->prix_mod->setValidator(new QIntValidator(0, 9999999, this));
    ui->quantite_mod->setValidator(new QIntValidator(0, 9999999, this));

    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this);

    ui->le_Libelle_produit->setValidator(validator);
    ui->Libelle_produit_mod->setValidator(validator);


    ui->tab_produit->setModel(P.afficher());
    son=new QSound(":/sons/sons/not.wav");



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()

{
    int Ref_produit=ui->le_Ref_produit->text().toInt();
    QString Libelle_produit=ui->le_Libelle_produit->text();
    int Prix=ui->le_Prix->text().toInt();
    int Quantite=ui->la_Quantite->text().toInt();
    int IDCategorie=ui->la_categorie->text().toInt();
    int IDFournisseur=ui->le_fournisseur->text().toInt();

    Produit P1(Ref_produit,Libelle_produit,Prix,Quantite,IDCategorie,IDFournisseur);
    bool test=P1.ajouter();
    QMessageBox msgBox;
    if(test)
    { msgBox.setText("ajout avec success !");
        ui->tab_produit->setModel(P1.afficher());
    }
    else
        msgBox.setText("ajout echoué !");
    msgBox.exec();
}



void MainWindow::on_pb_supprimer_clicked()
{
    Produit P1;
    P1.setRef_produit(ui->le_num_supp->text().toInt());
    bool test=P1.supprimer(P1.getRef_produit());

    QMessageBox msgBox;
    if(test)
    { msgBox.setText("suppression réussie !");
        son->play();
        ui->tab_produit->setModel(P.afficher());
       /* // First we need to create an SmtpClient object
            // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

            SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

            // We need to set the username (your email address) and password
            // for smtp authentification.

            smtp.setUser("nextech116@gmail.com");
             smtp.setPassword("15012002Anis");


            // Now we create a MimeMessage object. This is the email.

            MimeMessage message;

          EmailAddress sender("trabelsi.anis@yahoo.com", "manager");
            message.setSender(&sender);

            EmailAddress to("trabelsi.anis@yahoo.com", "reciever");
            message.addRecipient(&to);

            message.setSubject("SmtpClient for Qt - Demo");

            // Now add some text to the email.
            // First we create a MimeText object.

            MimeText text;

            text.setText("Hi,\nThis is a simple email message.\n");

            // Now add it to the mail

            message.addPart(&text);

            // Now we can send the mail

            if (!smtp.connectToHost()) {
                qDebug() << "Failed to connect to host!" << endl;
            }

            if (!smtp.login()) {
                qDebug() << "Failed to login!" << endl;
            }

            if (!smtp.sendMail(message)) {
                qDebug() << "Failed to send mail!" << endl;
            }

            smtp.quit();*/

    }
    else
        msgBox.setText("suppression echouée !");
    msgBox.exec();
}




void MainWindow::on_pb_chercher_clicked()
{
    Produit P1;
    P1=P1.chercher(ui->la_recherche->text().toInt());

    if(P1.getRef_produit()!=0)
    {

        ui->Ref_produit_mod->setText(QString::number(P1.getRef_produit())) ;
        ui->Libelle_produit_mod->setText(P1.getLibelle_produit()) ;
        ui->prix_mod->setText (QString::number(P1.getprix())) ;
        ui->quantite_mod->setText(QString::number(P1.getquantite()));
        ui->categorie_mod->setText(QString::number(P1.getcategorie()));
        ui->fournisseur_mod->setText(QString::number(P1.getfournisseur()));
        ui->tab_produit->setModel(P1.afficher());
    }
    else //introuvable
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher un produit"),
                              QObject::tr("produit introuvable !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void MainWindow::on_pb_modifier_clicked()
{
    int Ref_produit=ui->Ref_produit_mod->text().toInt();
    QString Libelle_produit=ui->Libelle_produit_mod->text();
    int Prix=ui->prix_mod->text().toInt();
    int Quantite=ui->quantite_mod->text().toInt();
    int IDCategorie=ui->categorie_mod->text().toInt();
    int IDFournisseur=ui->fournisseur_mod->text().toInt();
    Produit P(Ref_produit,Libelle_produit,Prix,Quantite,IDCategorie,IDFournisseur);

    Produit P1;
    int test=P1.Existence_produit(Ref_produit);

    if(test==true)
    {int test1=P1.modifier(Ref_produit,Libelle_produit,Prix,Quantite,IDCategorie,IDFournisseur);
        if(test1==true){
            QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                                     QObject::tr("produit modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_produit->setModel(P.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un produit"),
                                  QObject::tr("Erreur de modification!.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }

    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un produit"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
}




void MainWindow::on_cherche_aff_clicked()
{       Produit P1;
        P1=P1.chercher(ui->chercher_aff->text().toInt());


            if(P1.getRef_produit()!=0)
            {     QString Ref_produit_string= QString::number(P1.getRef_produit());
                QString Ref_prix= QString::number(P1.getprix());
                QString Ref_quantite= QString::number(P1.getquantite());
                QMessageBox msg;

                msg.setText("la reference: " + Ref_produit_string + "\n" + "Le libéllé: "+P1.getLibelle_produit()+" \n "+"le prix: "+ Ref_prix+" \n la quantite: "+ Ref_quantite);

                msg.exec();

            }
            else //introuvable
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher un produit"),
                                      QObject::tr("produit introuvable !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

            }

}


void MainWindow::on_tri_croissant_clicked()
{Produit P;
    ui->tab_produit->setModel(P.tri_croissant());
}

void MainWindow::on_tri_decroissant_clicked()
{
    Produit P;
    ui->tab_produit->setModel(P.tri_decroissant());
}


void MainWindow::on_tri_ref_clicked()
{    ui->tab_produit->setModel(P.tri_ref());

}

void MainWindow::on_tri_quantite_clicked()
{
    ui->tab_produit->setModel(P.tri_quantite());
}

void MainWindow::on_tri_libelle_clicked()
{
    ui->tab_produit->setModel(P.tri_libelle());

}

void MainWindow::on_stat_clicked()
{Produit P;
    QMessageBox msg;
    ui->tab_produit->setModel(P.statistic());

    msg.setText("la referen");
    msg.exec();

}

void MainWindow::on_reset_ajouter_clicked()
{
    ui->le_Ref_produit->clear();
    ui->le_Libelle_produit->clear();
    ui->le_Prix->clear();
    ui->la_Quantite->clear();
    ui->la_categorie->clear();
    ui->le_fournisseur->clear();
}
