#ifndef INCENDIE_H
#define INCENDIE_H

#include <QDialog>
#include "arduino.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QPixmap>
namespace Ui {
class incendie;
}

class incendie : public QDialog
{
    Q_OBJECT

public:
    explicit incendie(QWidget *parent = nullptr);
    ~incendie();

private slots:



private:
    Ui::incendie *ui;
QMediaPlayer *mMediaPlayer;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
};

#endif // INCENDIE_H
