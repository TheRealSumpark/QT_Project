
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
    equipements.cpp \
    evenement.cpp \
    event.cpp \
    fournisseur.cpp \
    gestion_equipe.cpp \
    gestion_joueur.cpp \
    guests.cpp \
    logo.cpp \
    main.cpp \
    mainwindow.cpp \
    match_main.cpp \
    media_player.cpp \
    modifier_equipe.cpp \
    modifier_joueur.cpp \
    qcustomplot.cpp \
    replay.cpp \
    statclass.cpp \
    stati.cpp \
    supprimer_equipe.cpp \
    supprimer_joueur.cpp \
    tournoi_main.cpp \
    video_stream.cpp

HEADERS += \
    Ajouter_joueur.h \
    afficher_equipe.h \
    afficher_joueur.h \
    ajouter_equipe.h \
    ajouter_joueur_equipe.h \
    connection.h \
    equipements.h \
    evenement.h \
    event.h \
    fournisseur.h \
    gestion_equipe.h \
    gestion_joueur.h \
    guests.h \
    logo.h \
    mainwindow.h \
    match_main.h \
    media_player.h \
    modifier_equipe.h \
    modifier_joueur.h \
    qcustomplot.h \
    replay.h \
    statclass.h \
    stati.h \
    supprimer_equipe.h \
    supprimer_joueur.h \
    tournoi_main.h \
    video_stream.h

FORMS += \
    Ajouter_joueur.ui \
    afficher_equipe.ui \
    afficher_joueur.ui \
    ajouter_equipe.ui \
    ajouter_joueur_equipe.ui \
    equipements.ui \
    evenement.ui \
    fournisseur.ui \
    gestion_equipe.ui \
    gestion_joueur.ui \
    logo.ui \
    mainwindow.ui \
    match_main.ui \
    media_player.ui \
    modifier_equipe.ui \
    modifier_joueur.ui \
    replay.ui \
    stati.ui \
    supprimer_equipe.ui \
    supprimer_joueur.ui \
    tournoi_main.ui \
    video_stream.ui
QT += core gui
QT +=sql
QT +=core sql
QT += widgets
QT += printsupport
QT += core gui  multimedia multimediawidgets
QT += core gui widgets
QT += multimedia



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RESOURCES += resources.qrc

