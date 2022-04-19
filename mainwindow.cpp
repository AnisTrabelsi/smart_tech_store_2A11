#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include "promotion.h"
#include"exportexcel.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlDatabase>
#include <QtCore>
#include <QtWidgets/QApplication>
#include <QSound>
#include <QFileDialog>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /////////////controle de saisie produits/////////////////////
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

 ///////////////////////controle de saisie promotion///////////////

    ui->le_idp->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_idc->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_Pour->setValidator(new QIntValidator(0, 9999999, this));

    ui->le_idp_mod->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_idc_mod->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_pour_mod->setValidator(new QIntValidator(0, 9999999, this));

    /////////////Affichage/////////////////////

    ui->tab_produit->setModel(P.afficher());
    ui->tab_promotion->setModel(P1.afficherp());

    ////////////son//////////////////////////
    son=new QSound(":/sons/sons/not.wav");
    son1=new QSound(":/sons/sons/not2.wav");
    son2=new QSound(":/sons/sons/not3.wav");
    son3=new QSound(":/sons/sons/not4.wav");
    son4=new QSound(":/sons/sons/not5.wav");
    son5=new QSound(":/sons/sons/not6.wav");

    ////////////////////////mail///////////////////////
    //des fonctions predefines par smtp.cpp
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));


    ///////////////////////chat//////////////////
    mSocket=new QTcpSocket(this);
       connect(mSocket,&QTcpSocket::readyRead,[&]()
       { QTextStream T(mSocket);
          auto text=T.readAll();
          ui->textEdit->append(text);
       });

       ////////////////////time/////////////////
       timer = new QTimer(this);
       connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
       timer->start(1000);
//Starts or restarts the timer with a timeout of duration msec milliseconds.

       /////////////////camera////////////////
       //Camera
                    mCamera = new QCamera (this);
                    mCameraViewfinder = new QCameraViewfinder(this);
                    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
                    mLayout = new QVBoxLayout;
                    mOptionMenu = new QMenu ("Option", this);
                    mTurnOnAction = new QAction ("Turn on", this);
                    mTurnOffAction = new QAction ("Turn off", this);
                    mCaptureAction = new QAction ("Capture", this);

                    mOptionMenu->addActions({mTurnOnAction, mTurnOffAction, mCaptureAction});
                    ui->pb_camera->setMenu(mOptionMenu);
                    mCamera->setViewfinder(mCameraViewfinder);
                    mLayout->addWidget(mCameraViewfinder);
                    mLayout->setMargin(0);
                    ui->scrollArea->setLayout(mLayout);
                    connect (mTurnOnAction, &QAction::triggered, [&]()
                    {
                       mCamera->start();
                    });
                    connect (mTurnOffAction, &QAction::triggered, [&]()
                    {
                        mCamera->stop();
                    });
                    connect (mCaptureAction, &QAction::triggered, [&]()
                    {
                        auto filename=QFileDialog::getSaveFileName(this, "capture", "/", "Image (*.jpg; *.jpeg)");

                        if (filename.isEmpty())
                        {
                            return;
                        }
                        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
                        QImageEncoderSettings imageEncoderSettings;
                        imageEncoderSettings.setCodec("image/jpeg");
                        imageEncoderSettings.setResolution(1600,1200);
                        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
                        mCamera->setCaptureMode(QCamera::CaptureStillImage);
                        mCamera->start();
                        mCamera->searchAndLock();
                        mCameraImageCapture->capture(filename);
                        mCamera->unlock();
                    });
         ////////////////////////Arduino
                    int ret=A.connect_arduino(); // lancer la connexion à arduino
                    switch(ret){
                    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                        break;
                    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                       break;
                    case(-1):qDebug() << "arduino is not available";
                    }
                     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                     //le slot update_label suite à la reception du signal readyRead (reception des données).




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
        son1->play();

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
    ui->tab_produit->setModel(P.afficher());
    son->play();


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
            son2->play();

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
{
    Produit P;
    P=P.chercher(ui->chercher_aff->text().toInt());


        if(P.getRef_produit()!=0){
    QString input = ui->chercher_aff->text();


        ui->tab_produit->setModel(P.afficher_produit(input));
        son3->play();
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
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Produit where Prix < 1000 ");
    float Prix1=model->rowCount(); //calculer le nb de lignes
    model->setQuery("select * from Produit where Prix  between 1000 and 1500 ");
    float Prix2=model->rowCount();
    model->setQuery("select * from Produit where Prix >1500 ");
    float Prix3=model->rowCount();
    float total=Prix1+Prix2+Prix3;
    QString a=QString("moins de 1000 dt "+QString::number((Prix1*100)/total,'f',2)+"%" );  //legende
    QString b=QString("entre 1000 dt et 1500 dt "+QString::number((Prix2*100)/total,'f',2)+"%" );
    QString c=QString("+1500 dt "+QString::number((Prix3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,Prix1); //affecter chaque valeur prix a la legende a ou b ou c
    series->append(b,Prix2);
    series->append(c,Prix3);
if (Prix1!=0)
{QPieSlice *slice = series->slices().at(0);
slice->setLabelVisible(); //afficher qstring a
slice->setPen(QPen()); //The pen defines how to draw lines and outlines, and it also defines the text color.
}
if ( Prix2!=0)
{
     // Add label, explode and define brush for 2nd slice
     QPieSlice *slice1 = series->slices().at(1);
     //slice1->setExploded();
     slice1->setLabelVisible();
}
if(Prix3!=0)
{
     // Add labels to rest of slices
     QPieSlice *slice2 = series->slices().at(2);
     //slice1->setExploded();
     slice2->setLabelVisible();
}
    // Create the chart widget
    QChart *chart = new QChart(); //The QChart class manages the graphical representation of the chart's series, legends, and axes. More...

    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage par prix de n Produits ave n= "+ QString::number(total));
    chart->legend()->hide(); //ne pas afficher la legende des stats

    // The QChartView is a standalone widget that can display charts
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); //Sets the given render hints on the painter if on is true; otherwise clears the render hints.
    chartView->resize(1000,500);  //page size
    chartView->show();  //afficher la page des stats
    son4->play();


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

void MainWindow::on_export_but_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            exportExcel obj(fileName, "mydata", ui->tab_produit);

            //colums to export
            obj.addField(0, "Ref_produit", "char(20)");
            obj.addField(1, "Libelle_produit", "char(20)");
            obj.addField(2, "Prix", "char(20)");
            obj.addField(3, "Quantite", "char(20)");
            obj.addField(4, "IDCategorie", "char(20)");
            obj.addField(5, "IDFournisseur", "char(20)");



            int retVal = obj.export2Excel();
            if( retVal > 0)
            {
                QMessageBox::information(this, tr("Done"),
                                         QString(tr("%1 records exported!")).arg(retVal)
                                         );
            }
}

//////////////promotion///////////////
void MainWindow::on_pb_ajouterp_clicked()
{  int IDpromotion=ui->le_idp->text().toInt();
    QString Date_debut=ui->la_dated->text();
    QString Date_fin=ui->la_datef->text();
    QString Description=ui->le_desc->text();
    int pourcentage=ui->le_Pour->text().toInt();
    int IDcategorie=ui->le_idc->text().toInt();


    Promotion P1(IDpromotion,Date_debut,Date_fin,Description,pourcentage,IDcategorie);
    bool test=P1.ajouterpromotion(IDcategorie);
    QMessageBox msgBox;
    if(test)
    { msgBox.setText("ajout avec success !");
        P.calculer(IDcategorie,pourcentage);
        ui->tab_promotion->setModel(P1.afficherp());
        ui->tab_produit->setModel(P.afficher());
        son1->play();

    }
    else
        msgBox.setText("ajout echoué !");
    msgBox.exec();

}

void MainWindow::on_reset_ajouter_p_clicked()
{    ui->le_idp->clear();
     ui->le_idc->clear();
      ui->le_Pour->clear();
       ui->la_dated->clear();
        ui->la_datef->clear();
         ui->le_desc->clear();

}


void MainWindow::on_pb_supprimerp_clicked()
{
    Promotion P1,P2;
    Produit P;
    P1.setIDpromotion(ui->le_num_supp_2->text().toInt());
    P2=P2.chercherpromotion(P1.getIDpromotion());
    bool test=P1.supprimerpromotion(P1.getIDpromotion());

    QMessageBox msgBox;
    if(test)
       { msgBox.setText("suppression réussie !");
        P.calculerapressupp(P2.getIDcategorie(),P2.getpourcentage());
    ui->tab_promotion->setModel(P1.afficherp());
    ui->tab_produit->setModel(P.afficher());

    son->play();

    }
    else
    msgBox.setText("suppression echouée !");
    msgBox.exec();
    }



void MainWindow::on_pb_chercher_p_clicked()
{Promotion P1;
    P1=P1.chercherpromotion(ui->la_recherchep->text().toInt());

    if(P1.getIDpromotion()!=0)
    {

        ui->le_idp_mod->setText(QString::number(P1.getIDpromotion())) ;
        ui->la_dated_mod->setText(P1.getDate_debut()) ;
        ui->la_datef_mod->setText (P1.getDate_fin()) ;
        ui->la_dec_mod->setText(P1.getDescription());
        ui->le_pour_mod->setText(QString::number(P1.getpourcentage()));
        ui->le_idc_mod->setText(QString::number(P1.getIDcategorie()));

        P.calculerapressupp(P1.getIDcategorie(),P1.getpourcentage());
        ui->tab_promotion->setModel(P1.afficherp());
        ui->tab_produit->setModel(P.afficher());

    }
    else //introuvable
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher une promotion"),
                              QObject::tr("promotion introuvable !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}}

void MainWindow::on_pb_modifiepr_clicked()
{
    int IDpromotion=ui->le_idp_mod->text().toInt();
       QString Date_debut=ui->la_dated_mod->text();
       QString Date_fin=ui->la_datef_mod->text();
       QString Description=ui->la_dec_mod->text();
       int pourcentage=ui->le_pour_mod->text().toInt();
       int IDcategorie=ui->le_idc_mod->text().toInt();

    Promotion P2(IDpromotion,Date_debut,Date_fin,Description,pourcentage,IDcategorie);

    Promotion P1;
    int test=P1.Existence_Promotion(IDpromotion);

    if(test==true)
    {int test1=P1.modifierpromotion(IDpromotion,Date_debut,Date_fin,Description,pourcentage,IDcategorie);
        if(test1==true){
            QMessageBox::information(nullptr, QObject::tr("modifier une promotion"),
                                     QObject::tr("produit modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

            P.calculer(IDcategorie,pourcentage);
            ui->tab_promotion->setModel(P1.afficherp());
            ui->tab_produit->setModel(P.afficher());
            ui->tab_promotion->setModel(P2.afficherp());
            son2->play();

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier une promotion"),
                                  QObject::tr("Erreur de modification!.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }

    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier une promotion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
}


void MainWindow::on_cherche_affp_clicked()
{ Promotion P1;
    P1=P1.chercherpromotion(ui->chercher_affpour->text().toInt());


        if(P1.getIDpromotion()!=0){
    QString input = ui->chercher_affpour->text();


        ui->tab_promotion->setModel(P1.afficher_Promotion(input));
        son3->play();
        }
        else //introuvable
        {
            QMessageBox::critical(nullptr, QObject::tr("chercher une promotion"),
                                  QObject::tr("promotion introuvable !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

}


////////////////mailing///////////////
void MainWindow::sendMail()
{//associé a un bouton grace a une fonction predefine par smtp.cpp
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{//status est une variable de retour
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    son5->play();

}


/////////////////////chat///////////////////////
void MainWindow::on_envoyer_clicked()
{ QTextStream T(mSocket);
    T<<ui->le_nickname->text()<<": "<<ui->le_message->text();
    mSocket->flush();
    ui->le_message->clear();
    son5->play();

}

void MainWindow::on_connecter_clicked()
{
    dumessengerconnectiondialog D(this);
    if(D.exec()==QDialog::Rejected)
    {
        return;

    }
    mSocket->connectToHost(D.hostname(),D.port());
}


//////////////////time///////////////
void MainWindow::myfunction()

{
    QTime time =QTime::currentTime();

    QString time_text = time.toString("hh:mm:ss");

    ui->time->setText(time_text);
}


void MainWindow::on_tri_idc_clicked()
{
    ui->tab_promotion->setModel(P1.tri_IDcategorie());

}

void MainWindow::on_tri_dated_clicked()
{
    ui->tab_promotion->setModel(P1.tri_datedebut());

}

void MainWindow::on_tri_datef_clicked()
{
    ui->tab_promotion->setModel(P1.tri_datefin());

}

void MainWindow::on_tri_croissant_pour_clicked()
{
    ui->tab_promotion->setModel(P1.tri_pourcentagecroissant());

}

void MainWindow::on_tri_decroissant_pour_clicked()
{
    ui->tab_promotion->setModel(P1.tri_pourcentagedecroissant());

}

void MainWindow::on_stat_pour_clicked()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Promotion where pourcentage < 35 ");
    float Pour1=model->rowCount();
    model->setQuery("select * from Promotion where pourcentage  between 35 and 75 ");
    float Pour2=model->rowCount();
    model->setQuery("select * from Promotion where pourcentage >75 ");
    float Pour3=model->rowCount();
    float total=Pour1+Pour2+Pour3;
    QString a=QString("moins de 35% "+QString::number((Pour1*100)/total,'f',2)+"%" );
    QString b=QString("entre 35% dt et 75%  "+QString::number((Pour2*100)/total,'f',2)+"%" );
    QString c=QString("+ 75%   dt "+QString::number((Pour3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,Pour1);
    series->append(b,Pour2);
    series->append(c,Pour3);
if (Pour1!=0)
{QPieSlice *slice = series->slices().at(0);
slice->setLabelVisible();
slice->setPen(QPen());}

if ( Pour2!=0)
{
     // Add label, explode and define brush for 2nd slice
     QPieSlice *slice1 = series->slices().at(1);
     //slice1->setExploded();
     slice1->setLabelVisible();
}
if(Pour3!=0)
{
     // Add labels to rest of slices
     QPieSlice *slice2 = series->slices().at(2);
     //slice1->setExploded();
     slice2->setLabelVisible();
}
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage par pourcentage de n categéories avec n = "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
    son4->play();


}

void MainWindow::on_export_but_pour_clicked()
{QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                 tr("Excel Files (*.xls)"));  //intitialisation du fichier excel
 if (fileName.isEmpty())
     return;

 exportExcel obj(fileName, "mydata", ui->tab_promotion);  //stocker les données afiichées dans le tableau

 //colums to export
 obj.addField(0, "IDpromotion", "char(20)");
 obj.addField(1, "Date_debut", "char(20)");
 obj.addField(2, "Date_fin", "char(20)");
 obj.addField(3, "Description", "char(20)");
 obj.addField(4, "pourcentage", "char(20)");
 obj.addField(5, "IDcategorie", "char(20)");



 int retVal = obj.export2Excel();  //export
 if( retVal > 0)
 {
     QMessageBox::information(this, tr("Done"),
                              QString(tr("%1 records exported!")).arg(retVal)
                              );
 }


}

void MainWindow::on_upload_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this, tr("choose"), "", tr("image (*.png *.jpg *.jpeg *.bmp *.gif)")); //The QFileDialog class provides a dialog that allow users to select files or directories
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            ui->image->setPixmap(QPixmap::fromImage(image)); //affichage de l'image
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Image non effectué.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        }
    }
}


void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="5")
{


       P.warning();
       ui->tab_produit->setModel(P.afficher());

       incendie i;
       i.setModal(true);
       i.exec();

    }}


void MainWindow::on_stop_clicked()
{
   A.write_to_arduino(("0"));
}
