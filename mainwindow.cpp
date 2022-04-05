#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QString>
#include "gagnant.h"
#include <QSoundEffect>
#include <QMediaPlayer>
#include"qcustomplot.h"
#include"QApplication"
#include"QIntValidator"
#include"QSqlQuery"
#include "exportexcel.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QTime time =QTime::currentTime();

     QString time_text = time.toString("hh:mm:ss");


    ui->setupUi(this);
    ui->id->setValidator( new QIntValidator(0, 9999999, this));
    ui->nbpts->setValidator( new QIntValidator(0, 9999999, this));

    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->nom->setValidator(validator);
    ui->prenom->setValidator(validator);
    ui->cadeau_client->setValidator(validator);


    QRegExp classe("[a-c]+");
    QValidator *validator_classe = new QRegExpValidator(rx, this);
    ui->classe->setValidator(validator_classe);



    ui->tab_client->setModel(C.afficher());

/* back ground music
    QMediaPlayer *backmusic = new QMediaPlayer();
    backmusic->setMedia(QUrl("qrc:/sound/congratulations.wav"));
    backmusic->play();
*/
}




MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id_client=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    /*int nb_points=ui->nbpts->text().toInt();
    QString cadeau_client=ui->cadeau_client->text();
    QString classe=ui->classe->text();*/

    client c(id_client,nom,prenom,0,"c","rien");



bool test=c.ajouter_client();
QMessageBox msgBox;
if(test)
   { msgBox.setText("ajout avec success !");
ui->tab_client->setModel(c.afficher());

}
else
msgBox.setText("ajout échoué !");
msgBox.exec();


}





void MainWindow::on_pb_supprimer_clicked()
{
    client c1;
    c1.setid(ui->id_supp->text().toInt());



    QMessageBox msgBox;
    if( c1.supprimer(c1.getid()))
       { msgBox.setText("suppression avec success !");
         msgBox.exec();
    ui->tab_client->setModel(c1.afficher());
       }
       else
    {    QMessageBox msgBox;
       msgBox.setText("suppression echouée !");
    msgBox.exec();
    }

}





////button chercher tee tableau modifier//
void MainWindow::on_pb_chercher_client_clicked()
{  client c1;
  c1=c1.chercher_client(ui->id_chercher->text().toInt());


     if(c1.getnom()!= "vide")
   {

       ui->id_client->setText( QString::number(c1.getid()) ) ;
       ui->id_nom->setText( c1.getnom() ) ;
       ui->id_prenom->setText( c1.getprenom() ) ;
       ui->id_nbpts->setText( QString::number(c1.getnb_points()) ) ;
       ui->id_cadeau->setText(c1.getcadeau_client());
      ui->id_classe->setText(c1.getclasse());


   }
     else //introuvable
     {
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                     QObject::tr("employee introuvable !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }

}







void MainWindow::on_pb_modifier_clicked()
{
    int id_client=ui->id_client->text().toInt();
    QString nom=ui->id_nom->text();
    QString prenom=ui->id_prenom->text();
    int  nbpts=ui->id_nbpts->text().toInt();
    QString cadeau_cl=ui->id_cadeau->text();
    QString classe=ui->id_classe->text();

    client c1;
    int test=c1.chercher_client_bool(id_client);

    if(test==true)
    {
        if(c1.modifier_client(id_client,nom,prenom,nbpts,classe,cadeau_cl) == true)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                              QObject::tr("client modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_client->setModel(c1.afficher()); //tee maj//
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un modifé"),
                        QObject::tr("Erreur de modification !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

    }
}









////////buttons tee tri////////
void MainWindow::on_radio_nom_clicked()
{client c1;
   ui->tab_client->setModel(c1.trier_nom());
}


void MainWindow::on_radio_prenom_clicked()
{
    client c1;
       ui->tab_client->setModel(c1.trier_prenom());
}






void MainWindow::on_radio_nb_pts_clicked()
{
    client c1;
       ui->tab_client->setModel(c1.trier_nb_pts());
}

void MainWindow::on_pb_client_dumois_clicked()
{ gagnant g;
     /*QMediaPlayer * music = new QMediaPlayer();
     music->setMedia(QUrl("qrc:/sound/congratulations.wav"));
     music->play();*/


    g.setModal(true);
     g.exec();


    /*client c1;
    c1.client_du_mois();*/
}





void MainWindow::on_pb_chercher_aff_clicked()
{   client c1;

    c1=c1.chercher_client(ui->id_barre->text().toInt());

     if(c1.getnom()!= "vide")
   {
QString id =QString::number(c1.getid());
QString nb =QString::number(c1.getnb_points());




QMessageBox msg;
msg.setText("le nom est : "+c1.getnom()+ "\n"+ "Le prenom est : "+c1.getprenom()+" \n "+"Le nombre des points  est :  "+ nb+" \n la classe est :  "+c1.getclasse()+" \n l'id est :"+id);
msg.exec();







   }
     else //introuvable
     {
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                     QObject::tr("employee introuvable !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }


}

void MainWindow::on_reset_clicked()
{
    ui->id->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->cadeau_client->clear();
    ui->id_nbpts->clear();

}






void MainWindow::on_tabWidget_currentChanged(int index)
{
    // background //
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(90, 90, 90));
              gradient.setColorAt(0.38, QColor(105, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plot->setBackground(QBrush(gradient));

              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //couleurs
              amande->setName("Repartition des clients selon nombre des points ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));

               //axe des abscisses
              QVector<double> ticks;
              QVector<QString> labels;

              client c;
              c.statistique(&ticks,&labels);

              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plot->xAxis->setTicker(textTicker);
              ui->plot->xAxis->setTickLabelRotation(60);
              ui->plot->xAxis->setSubTicks(false);
              ui->plot->xAxis->setTickLength(0, 4);
              ui->plot->xAxis->setRange(0,10);
              ui->plot->xAxis->setBasePen(QPen(Qt::white));
              ui->plot->xAxis->setTickPen(QPen(Qt::white));
              ui->plot->xAxis->grid()->setVisible(true);
              ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::white);
              ui->plot->xAxis->setLabelColor(Qt::white);

              // axe des ordonnées
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5);
              ui->plot->yAxis->setLabel("Statistiques");
              ui->plot->yAxis->setBasePen(QPen(Qt::white));
              ui->plot->yAxis->setTickPen(QPen(Qt::white));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::white);
              ui->plot->yAxis->setLabelColor(Qt::white);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

              // ajout des données  (statistiques des nb pts)//

              QVector<double> PlaceData;
              QSqlQuery q1("select nb_points from client ");
              while (q1.next()) {
                            int  nbr_points = q1.value(0).toInt();
                            PlaceData<< nbr_points;
                              }
              amande->setData(ticks, PlaceData);

              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(5);
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);





}




void MainWindow::on_exporter_clicked()
{QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                 tr("Excel Files (*.xls)"));
 if (fileName.isEmpty())
     return;

 exportExcel obj(fileName, "mydata", ui->tab_client);

 //colums to export
 obj.addField(0, "id_client", "char(20)");
 obj.addField(1, "nom", "char(20)");
 obj.addField(2, "prenom", "char(20)");
 obj.addField(3, "nb_pts", "char(20)");
 obj.addField(4, "classe", "char(20)");
 obj.addField(5, "cadeau", "char(20)");



 int retVal = obj.export2Excel();
 if( retVal > 0)
 {
     QMessageBox::information(this, tr("Done"),
                              QString(tr("%1 records exported!")).arg(retVal)
                              );
 }

}



void MainWindow::on_pb_historique_client_clicked()
{

client c;
QFile file("his.txt");
      if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0,"info",file.errorString());
               QTextStream lecture(&file);
               ui->textBrowser->setText(lecture.readAll());
               QString montext = lecture.readAll();
               QMessageBox::information(nullptr, QObject::tr("Text History is open"),
                           QObject::tr("Text History is successfully displayed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               //QMessageBox::information(this, "Fichier", montext);
               file.close();

}

void MainWindow::myfunction()

{
    QTime time =QTime::currentTime();

    QString time_text = time.toString("hh:mm:ss");

    ui->time->setText(time_text);
}





