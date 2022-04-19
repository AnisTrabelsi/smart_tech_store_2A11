#include "incendie.h"
#include "ui_incendie.h"
#include "arduino.h"
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
incendie::incendie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incendie)
{
    ui->setupUi(this);
    QMediaPlayer *music = new QMediaPlayer();
                   music->setMedia(QUrl("qrc:/sons/sons/Danger Alarm Meme Sound Effect.wav"));
                   music->play();

                   QMovie *movie = new QMovie(":/sons/sons/gif2.gif");
                   ui->mrigl ->setMovie (movie);
                   movie->start ();
}

incendie::~incendie()
{
    delete ui;
}


