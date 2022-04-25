#include "map.h"
#include "ui_map.h"
#include <QQuickItem>

Map::Map(QWidget *parent,int a) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));
if(a==0)
{
    emit setCenter(36.86052, 10.15860);//coordonnees Ariana
           emit addMarker(36.86052, 10.15860);//coordonnees Ariana
}
else if (a==1)
{

            emit setCenter(37.27561,9.86718);;//coordonnees Bizerte
            emit addMarker(37.27561, 9.86718);//coordonnees Bizerte
}
else if (a==2)
{

            emit setCenter(35.82995, 10.61260);//coordonnees Sousse
            emit addMarker(35.82995, 10.61260);//coordonnees Sousse
}
else if (a==3)
{

            emit setCenter(35.6710101,10.10062);;//coordonnees Kairouan
            emit addMarker(35.6710101,10.10062);//coordonnees Kairouan
}
else if (a==4)
{

    emit setCenter(34.73963, 10.75642);//coordonnees Sfax
           emit addMarker(34.73963, 10.75642);//coordonnees Sfax
}
else if (a==5)
{

    emit setCenter(36.7236241,9.1853919);//coordonnees BEJA
           emit addMarker(36.7236241,9.1853919);//coordonnees BEJA
}
else if (a==6)
{

    emit setCenter(33.80481, 10.99150);//coordonnees Djerba
            emit addMarker(33.80481, 10.99150);//coordonnees Djerba
}
}

Map::~Map()
{
    delete ui;
}
