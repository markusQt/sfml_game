TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lsfml-window
LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lsfml-system
LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lsfml-graphics
LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lsfml-network
LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lsfml-audio


INCLUDEPATH += $$PWD/../../../../usr/include/SFML
DEPENDPATH += $$PWD/../../../../usr/include/SFML












