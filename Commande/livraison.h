#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QWidget>

namespace Ui {
class Livraison;
}

class Livraison : public QWidget
{
    Q_OBJECT

public:
    explicit Livraison(QWidget *parent = nullptr);
    ~Livraison();

private slots:
    void on_valider_clicked();

private:
    Ui::Livraison *ui;
};

#endif // LIVRAISON_H
