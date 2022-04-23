#ifndef GAGNANT_H
#define GAGNANT_H

#include <QDialog>

namespace Ui {
class gagnant;
}

class gagnant : public QDialog
{
    Q_OBJECT

public:
    explicit gagnant(QWidget *parent = nullptr);
    ~gagnant();

private:
    Ui::gagnant *ui;
};

#endif // GAGNANT_H
