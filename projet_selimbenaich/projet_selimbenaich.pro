QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ajouter_joueur.cpp \
    afficher_equipe.cpp \
    afficher_joueur.cpp \
    ajouter_equipe.cpp \
    ajouter_joueur_equipe.cpp \
    connection.cpp \
    gestion_equipe.cpp \
    gestion_joueur.cpp \
    main.cpp \
    mainwindow.cpp \
    modifier_equipe.cpp \
    modifier_joueur.cpp \
    supprimer_equipe.cpp \
    supprimer_joueur.cpp

HEADERS += \
    Ajouter_joueur.h \
    afficher_equipe.h \
    afficher_joueur.h \
    ajouter_equipe.h \
    ajouter_joueur_equipe.h \
    connection.h \
    gestion_equipe.h \
    gestion_joueur.h \
    mainwindow.h \
    modifier_equipe.h \
    modifier_joueur.h \
    supprimer_equipe.h \
    supprimer_joueur.h

FORMS += \
    Ajouter_joueur.ui \
    afficher_equipe.ui \
    afficher_joueur.ui \
    ajouter_equipe.ui \
    ajouter_joueur_equipe.ui \
    gestion_equipe.ui \
    gestion_joueur.ui \
    mainwindow.ui \
    modifier_equipe.ui \
    modifier_joueur.ui \
    supprimer_equipe.ui \
    supprimer_joueur.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
