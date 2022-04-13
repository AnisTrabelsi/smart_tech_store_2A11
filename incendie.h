#ifndef INCENDIE_H
#define INCENDIE_H

#include <QDialog>
#include "arduino.h"
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
    void on_stop_clicked();

private:
    Ui::incendie *ui;

    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
};

#endif // INCENDIE_H
