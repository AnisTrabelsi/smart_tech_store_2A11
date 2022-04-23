#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql printsupport
QT       += charts
QT       += serialport
QT       += core gui multimedia multimediawidgets sql location \
    quick
QT += widgets charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app
QT += sql
QT += core gui
QT += core gui charts
QT += multimedia

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    client.cpp \
    clientw.cpp \
    employee.cpp \
    exportexcel.cpp \
    facture.cpp \
    facturew.cpp \
    gagnant.cpp \
    home.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    mdp_oub.cpp \
    menu.cpp \
    qcustomplot.cpp

HEADERS += \
    arduino.h \
    client.h \
    clientw.h \
    employee.h \
    exportexcel.h \
    facture.h \
    facturew.h \
    gagnant.h \
    home.h \
        mainwindow.h \
    connection.h \
    mdp_oub.h \
    menu.h \
    qcustomplot.h

FORMS += \
        clientw.ui \
        facturew.ui \
        gagnant.ui \
        historique.ui \
        home.ui \
        mainwindow.ui \
        mdp_oub.ui \
        menu.ui \
        statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    congratulations.qrc \
    res.qrc

DISTFILES += \
    congratulations.mp3 \
    congratulations.wav \
    test.txt \
    winner.jpg
