#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_employeeW_clicked();

    void on_factureW_clicked();

    void on_clientW_clicked();

    void on_produitW_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
