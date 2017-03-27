QT += core gui
TEMPLATE = app
QT += widgets
HEADERS += \
    personaggio.h \
    oggetto.h \
    oggettodanno.h \
    oggettoprotezione.h \
    scudo.h \
    oggettoaiuto.h \
    pozione.h \
    arena.h \
    contenitoreoggetti.h \
    combattimento.h \
    arenasemplice.h \
    controller.h \
    listaobject.h \
    playwidget.h \
    gameboard.h \
    menuwidget.h \
    equipboardwidget.h \
    statistichewidget.h \
    ruleswidget.h \
    creapersonaggiowidget.h \
    finestragioco.h \
    completapersonaggioWidget.h \
    sceltapersonaggioWidget.h \
    listamercatowidget.h \
    listazainowidget.h \
    arma.h \
    presentationwidget.h \
    database.h

SOURCES += \
    personaggio.cpp \
    main.cpp \
    oggettodanno.cpp \
    oggetto.cpp \
    oggettoprotezione.cpp \
    scudo.cpp \
    oggettoaiuto.cpp \
    pozione.cpp \
    arena.cpp \
    contenitoreoggetti.cpp \
    combattimento.cpp \
    arenasemplice.cpp \
    controller.cpp \
    listaobject.cpp \
    playwidget.cpp \
    gameboard.cpp \
    menuwidget.cpp \
    equipboardwidget.cpp \
    statistichewidget.cpp \
    ruleswidget.cpp \
    creapersonaggiowidget.cpp \
    finestragioco.cpp \
    completapersonaggioWidget.cpp \
    sceltapersonaggioWidget.cpp \
    listamercatowidget.cpp \
    listazainowidget.cpp \
    arma.cpp \
    database.cpp

FORMS +=

RESOURCES += \
    immagini.qrc \
    database.qrc

DISTFILES +=
