#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QDialog>

namespace Ui {
class historique;
}

class historique : public QDialog
{
    Q_OBJECT

public:
    explicit historique(QWidget *parent = nullptr);
    ~historique();
    QString text;

private:
    Ui::historique *ui;
};

#endif // HISTORIQUE_H
