#ifndef MDP_OUB_H
#define MDP_OUB_H

#include <QDialog>

namespace Ui {
class mdp_oub;
}

class mdp_oub : public QDialog
{
    Q_OBJECT

public:
    explicit mdp_oub(QWidget *parent = nullptr);
    ~mdp_oub();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mdp_oub *ui;
};

#endif // MDP_OUB_H
