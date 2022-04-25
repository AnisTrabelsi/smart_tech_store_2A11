#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QDialog>
#include "civraison.h"

namespace Ui {
class Livraison;
}

class Livraison : public QDialog
{
    Q_OBJECT

public:
    explicit Livraison(QWidget *parent = nullptr);
    ~Livraison();

private slots:
    void on_valider_clicked();

private:
    Ui::Livraison *ui;
    CIVRAISON CI;
};

#endif // LIVRAISON_H
