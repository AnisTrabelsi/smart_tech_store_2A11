#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------
QT       += widgets quickwidgets
QT       += core gui sql printsupport
QT       += charts
QT       += serialport
QT       += core gui multimedia multimediawidgets sql location \
    quick
QT += widgets charts
QT       += qml quick

QT       += core gui sql \
quick
QT       += core gui charts
QT      += printsupport
QT  += core network
QT       += core gui network
QT  +=svg
QT += quick
QT += core gui multimedia multimediawidgets
QT += multimedia
QT       += core gui  serialport


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
    Commande.cpp \
    arduino.cpp \
    categorie.cpp \
    categoriew.cpp \
    chatserver.cpp \
    chatsocket.cpp \
    civraison.cpp \
    client.cpp \
    clientw.cpp \
    commandew.cpp \
    dumessengerconnectiondialog.cpp \
    employee.cpp \
    exportexcel.cpp \
    facture.cpp \
    facturew.cpp \
    fournisseur.cpp \
    fournisseurw.cpp \
    gagnant.cpp \
    home.cpp \
    incendie.cpp \
    livraison.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    map.cpp \
    mdp_oub.cpp \
    menu.cpp \
    panier.cpp \
    produit.cpp \
    produitw.cpp \
    promotion.cpp \
    qcustomplot.cpp \
    reclamation.cpp \
    smtp.cpp

HEADERS += \
    Commande.h \
    arduino.h \
    categorie.h \
    categoriew.h \
    chatserver.h \
    chatsocket.h \
    civraison.h \
    client.h \
    clientw.h \
    commandew.h \
    dumessengerconnectiondialog.h \
    employee.h \
    exportexcel.h \
    facture.h \
    facturew.h \
    fournisseur.h \
    fournisseurw.h \
    gagnant.h \
    home.h \
    incendie.h \
    livraison.h \
        mainwindow.h \
    connection.h \
    map.h \
    mdp_oub.h \
    menu.h \
    panier.h \
    produit.h \
    produitw.h \
    promotion.h \
    qcustomplot.h \
    reclamation.h \
    smtp.h

FORMS += \
        categoriew.ui \
        clientw.ui \
        commandew.ui \
        dumessengerconnectiondialog.ui \
        facturew.ui \
        fournisseurw.ui \
        gagnant.ui \
        historique.ui \
        home.ui \
        incendie.ui \
        livraison.ui \
        mainwindow.ui \
        map.ui \
        mdp_oub.ui \
        menu.ui \
        produitw.ui \
        statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    congratulations.qrc \
    congratulations.qrc \
    qml.qrc \
    res.qrc \
    res.qrc \
    ressource.qrc

DISTFILES += \
    Atelier_Connexion.pro.user \
    Atelier_Connexion.pro.user.5a00d41 \
    Atelier_Connexion.pro.user.725b3e0 \
    Atelier_Connexion.pro.user.d567f1b.4.8-pre1 \
    background.png \
    congratulations.mp3 \
    congratulations.wav \
    fire_background_for_your_videos.mp4 \
    libeay32.dll \
    smtp.exe \
    ssleay32.dll \
    test.txt \
    winner.jpg
