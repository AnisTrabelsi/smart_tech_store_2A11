#ifndef COMMANDEW_H
#define COMMANDEW_H

#include <QDialog>

namespace Ui {
class commandeW;
}

class commandeW : public QDialog
{
    Q_OBJECT

public:
    explicit commandeW(QWidget *parent = nullptr);
    ~commandeW();

private:
    Ui::commandeW *ui;
};

#endif // COMMANDEW_H
