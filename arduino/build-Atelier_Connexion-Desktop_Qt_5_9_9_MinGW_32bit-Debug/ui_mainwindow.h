/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *background;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QTableView *view;
    QRadioButton *NUM;
    QRadioButton *PAIMENT;
    QRadioButton *ID;
    QPlainTextEdit *plainTextEdit;
    QWidget *AjouterCategorie;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_9;
    QPushButton *reset_ajouter_2;
    QPushButton *valider;
    QLineEdit *ID_CATEGORIE;
    QLineEdit *REMISE;
    QLineEdit *LIBELLE;
    QLabel *label_11;
    QWidget *tab;
    QGroupBox *suppression;
    QLabel *label_12;
    QLineEdit *supp;
    QPushButton *pb_supprimer;
    QWidget *tab_2;
    QGroupBox *suppression_2;
    QLabel *label_14;
    QLineEdit *idmodif;
    QPushButton *cherchermodif;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_25;
    QPushButton *reset_ajouter_4;
    QPushButton *valider_3;
    QLineEdit *idCategorie_3;
    QLineEdit *LIBELLE_3;
    QLineEdit *REMISE_3;
    QLabel *label_27;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1234, 729);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        background = new QLabel(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-40, -10, 1261, 711));
        background->setPixmap(QPixmap(QString::fromUtf8("../../../../Users/Adam/Desktop/background.png")));
        background->setScaledContents(true);
        background->setTextInteractionFlags(Qt::NoTextInteraction);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(160, 20, 841, 611));
        QFont font;
        font.setKerning(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QLatin1String("QWidget{background:transparent} QTabWidget::pane{border: 1px;border-color:red;background-color: transparent;} \n"
"QTabBar::tab {background-color: transparent;color: #ccc;width: 280px;height:48px;font-size:15px} \n"
"\n"
"QTabBar::tab:hover{\n"
"color: white;\n"
"background-color:#D81515;\n"
"border-width: 2px;\n"
"border-color: #000000;;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 20px;\n"
"\n"
"\n"
"}"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(20, 20));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        view = new QTableView(tab_4);
        view->setObjectName(QStringLiteral("view"));
        view->setGeometry(QRect(10, 20, 821, 311));
        view->setStyleSheet(QLatin1String("QTableView\n"
"{\n"
"    alternate-background-color: #1F1F1F;\n"
"    gridline-color: white;\n"
"    color: white;\n"
"\n"
"    font: 75 9pt \"MS Shell Dlg 2\";\n"
"}\n"
"QTableView::item \n"
"{\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView::item:focus\n"
"{\n"
"    color: gray;\n"
"    background: #0063cd;\n"
"}\n"
"QTableView::item:selected\n"
"{\n"
"    color: red;\n"
"    background: #0063cd;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked, QCheckBox::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 1px;\n"
"    width: 7px;\n"
"    height: 7px;\n"
"    margin: 0px 5px 0 5px;\n"
"}\n"
"\n"
"    padding-left:10px;\n"
"    height:100px;\n"
"    width:180px;\n"
"    color: #5a5a5a;\n"
"    border-bottom :1px solid #f0f0f0;"));
        NUM = new QRadioButton(tab_4);
        NUM->setObjectName(QStringLiteral("NUM"));
        NUM->setGeometry(QRect(652, 447, 91, 31));
        NUM->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        PAIMENT = new QRadioButton(tab_4);
        PAIMENT->setObjectName(QStringLiteral("PAIMENT"));
        PAIMENT->setGeometry(QRect(652, 477, 91, 21));
        PAIMENT->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        ID = new QRadioButton(tab_4);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(652, 500, 91, 21));
        ID->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        plainTextEdit = new QPlainTextEdit(tab_4);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(600, 410, 101, 31));
        plainTextEdit->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 14pt \"MS Shell Dlg 2\";"));
        tabWidget->addTab(tab_4, QString());
        AjouterCategorie = new QWidget();
        AjouterCategorie->setObjectName(QStringLiteral("AjouterCategorie"));
        groupBox = new QGroupBox(AjouterCategorie);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(40, 30, 721, 451));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setTabletTracking(false);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 100, 151, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush3(QColor(255, 255, 255, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 127, 127, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 170, 170, 0));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(255, 255, 255, 127));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_3->setPalette(palette1);
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setStyleStrategy(QFont::PreferDefault);
        label_3->setFont(font2);
        label_3->setAutoFillBackground(false);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 200, 231, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_9->setPalette(palette2);
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_9->setFont(font3);
        reset_ajouter_2 = new QPushButton(groupBox);
        reset_ajouter_2->setObjectName(QStringLiteral("reset_ajouter_2"));
        reset_ajouter_2->setGeometry(QRect(430, 390, 131, 41));
        reset_ajouter_2->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        valider = new QPushButton(groupBox);
        valider->setObjectName(QStringLiteral("valider"));
        valider->setGeometry(QRect(260, 390, 131, 41));
        valider->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}"));
        ID_CATEGORIE = new QLineEdit(groupBox);
        ID_CATEGORIE->setObjectName(QStringLiteral("ID_CATEGORIE"));
        ID_CATEGORIE->setGeometry(QRect(340, 100, 221, 31));
        ID_CATEGORIE->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        REMISE = new QLineEdit(groupBox);
        REMISE->setObjectName(QStringLiteral("REMISE"));
        REMISE->setGeometry(QRect(340, 180, 221, 31));
        REMISE->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        LIBELLE = new QLineEdit(groupBox);
        LIBELLE->setObjectName(QStringLiteral("LIBELLE"));
        LIBELLE->setGeometry(QRect(340, 260, 221, 31));
        LIBELLE->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(80, 270, 91, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_11->setPalette(palette3);
        label_11->setFont(font3);
        tabWidget->addTab(AjouterCategorie, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        suppression = new QGroupBox(tab);
        suppression->setObjectName(QStringLiteral("suppression"));
        suppression->setGeometry(QRect(90, 70, 631, 361));
        suppression->setStyleSheet(QLatin1String("\n"
"font: 75 15pt \"MS Shell Dlg 2\";\n"
"color:white"));
        label_12 = new QLabel(suppression);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(190, 120, 31, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_12->setPalette(palette4);
        QFont font4;
        font4.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font4.setPointSize(15);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        label_12->setFont(font4);
        supp = new QLineEdit(suppression);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(230, 120, 181, 41));
        supp->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        pb_supprimer = new QPushButton(suppression);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(270, 190, 93, 28));
        pb_supprimer->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        suppression_2 = new QGroupBox(tab_2);
        suppression_2->setObjectName(QStringLiteral("suppression_2"));
        suppression_2->setGeometry(QRect(120, 10, 591, 131));
        suppression_2->setStyleSheet(QLatin1String("\n"
"font: 75 15pt \"MS Shell Dlg 2\";\n"
"color:white"));
        label_14 = new QLabel(suppression_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(180, 30, 31, 41));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_14->setPalette(palette5);
        label_14->setFont(font4);
        idmodif = new QLineEdit(suppression_2);
        idmodif->setObjectName(QStringLiteral("idmodif"));
        idmodif->setGeometry(QRect(220, 30, 181, 41));
        idmodif->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        cherchermodif = new QPushButton(suppression_2);
        cherchermodif->setObjectName(QStringLiteral("cherchermodif"));
        cherchermodif->setGeometry(QRect(260, 90, 93, 28));
        cherchermodif->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(90, 150, 651, 401));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox_3->setPalette(palette6);
        groupBox_3->setFont(font1);
        groupBox_3->setTabletTracking(false);
        groupBox_3->setAutoFillBackground(false);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 80, 151, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_6->setPalette(palette7);
        label_6->setFont(font2);
        label_6->setAutoFillBackground(false);
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(80, 180, 231, 21));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_25->setPalette(palette8);
        label_25->setFont(font3);
        reset_ajouter_4 = new QPushButton(groupBox_3);
        reset_ajouter_4->setObjectName(QStringLiteral("reset_ajouter_4"));
        reset_ajouter_4->setGeometry(QRect(420, 340, 131, 41));
        reset_ajouter_4->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        valider_3 = new QPushButton(groupBox_3);
        valider_3->setObjectName(QStringLiteral("valider_3"));
        valider_3->setGeometry(QRect(150, 340, 131, 41));
        valider_3->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}"));
        idCategorie_3 = new QLineEdit(groupBox_3);
        idCategorie_3->setObjectName(QStringLiteral("idCategorie_3"));
        idCategorie_3->setGeometry(QRect(280, 80, 221, 31));
        idCategorie_3->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        LIBELLE_3 = new QLineEdit(groupBox_3);
        LIBELLE_3->setObjectName(QStringLiteral("LIBELLE_3"));
        LIBELLE_3->setGeometry(QRect(280, 170, 221, 31));
        LIBELLE_3->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        REMISE_3 = new QLineEdit(groupBox_3);
        REMISE_3->setObjectName(QStringLiteral("REMISE_3"));
        REMISE_3->setGeometry(QRect(280, 260, 221, 31));
        REMISE_3->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(80, 270, 91, 21));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label_27->setPalette(palette9);
        label_27->setFont(font3);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1234, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        background->setText(QString());
        NUM->setText(QApplication::translate("MainWindow", "Libelle", Q_NULLPTR));
        PAIMENT->setText(QApplication::translate("MainWindow", "Remise", Q_NULLPTR));
        ID->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "TRI PAR :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Afficher Categorie", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajouter Categorie", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "IdCategorie", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Remise", Q_NULLPTR));
        reset_ajouter_2->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        valider->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "LIBELLE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(AjouterCategorie), QApplication::translate("MainWindow", "Ajouter Categorie", Q_NULLPTR));
        suppression->setTitle(QApplication::translate("MainWindow", "Suppression", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        supp->setText(QString());
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Supprimer Categorie", Q_NULLPTR));
        suppression_2->setTitle(QApplication::translate("MainWindow", "Chercher", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        idmodif->setText(QString());
        cherchermodif->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Ajouter Commande", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "IdCategorie", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "LIBELLE", Q_NULLPTR));
        reset_ajouter_4->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        valider_3->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "REMISE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Modifier Categorie", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
