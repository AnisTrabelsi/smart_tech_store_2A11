#ifndef CATEGORIEW_H
#define CATEGORIEW_H

#include <QDialog>

namespace Ui {
class Categoriew;
}

class Categoriew : public QDialog
{
    Q_OBJECT

public:
    explicit Categoriew(QWidget *parent = nullptr);
    ~Categoriew();

private:
    Ui::Categoriew *ui;
};

#endif // CATEGORIEW_H
