#include "statistiques_clients.h"
#include "statistic.h"
#include "ui_statistiques.h"
#include"client.h"
statistics::statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistics)
{
    {
     ui->setupUi(this);
    this->setWindowTitle("STATISTIQUES");
           QPieSeries *series = new QPieSeries();

          client  c;
          // Crud_Menu m;

          int  total_classe = c.total_classe_a()+c.total_classe_b()+c.total_classe_c();

          series->append("total_classe_a",c.total_classe_a());
          series->append("total_classe_b",c.total_classe_b());
          series->append("total_classe_c",c.total_classe_c());
           series->setHoleSize(0.2);
           QPieSlice *slice = series->slices().at(0);
           slice->setLabelVisible();

           QPieSlice *slice1 = series->slices().at(1);
           slice1->setExploded();
           slice1->setLabelVisible();

           QPieSlice *slice2 = series->slices().at(2);
           slice2->setLabelVisible();

           QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("  classee  :");
           chart->legend()->hide();
           chart->setAnimationOptions(QChart::SeriesAnimations);

           QChartView *chartview = new QChartView(chart);
           chartview->setRenderHint(QPainter::Antialiasing);
           chartview->setParent(ui->horizontalFrame);
       }
   }



statistics::~statistics()
{
    delete ui;
}
