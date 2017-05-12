
QT += gui core widgets

HEADERS += \
    Board.h \
    BoardHex.h \
    HexAttr.h \
    Pieces.h \
    Uni.h \
    wargame.h \
    Minimap.h

SOURCES += \
    Board.cpp \
    BoardHex.cpp \
    main.cpp \
    Pieces.cpp \
    Terrain.cpp \
    wargame.cpp \
    Weather.cpp \
    Minimap.cpp

FORMS += \
    wargame.ui

DISTFILES += \
    assets/butterfly.png
