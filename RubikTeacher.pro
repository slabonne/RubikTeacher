QT += gui network xml widgets openglwidgets

SOURCES += src/variables.cpp \
    src/couleurpalette.cpp \
    src/mainwindow.cpp \
    src/mystandarditem.cpp \
    src/palette.cpp \
    src/qpushbuttonmovecube.cpp \
    src/qthreadmvtface.cpp \
    src/rubikplat.cpp \
    src/rubikplateditor.cpp \
    src/rubik_croix_carres.cpp \
    src/rubik_croix.cpp \
    src/main.cpp \
    src/glrubik.cpp \
    src/Cube.cpp \
    src/qdisplaysoluce.cpp \
    src/resolution.cpp \
    src/resolution_Layer_by_Layer.cpp \
    src/resolution_friedriech.cpp \
    src/Regression.cpp \
    src/helpclass.cpp \
    src/qdisplaydescription.cpp \
    src/QComparatif_Frame.cpp
HEADERS += src/variables.h \
    src/couleurpalette.h \
    src/mainwindow.h \
    src/mystandarditem.h \
    src/palette.h \
    src/qpushbuttonmovecube.h \
    src/qthreadmvtface.h \
    src/rubikplat.h \
    src/rubikplateditor.h \
    src/rubik_croix_carres.h \
    src/rubik_croix.h \
    src/glrubik.h \
    src/Cube.h \
    src/qdisplaysoluce.h \
    src/resolution.h \
    src/Regression.h \
    src/helpclass.h \
    src/qdisplaydescription.h \
    src/QComparatif_Frame.h \
    src/constants.h

RESOURCES += ressources.qrc \
    src/ressources.qrc

LIBS += -lopengl32

RC_FILE = qtRubik.rc

FORMS += \
    src/mainwindow.ui \
    src/palette.ui \
    src/rubikplat.ui \
    src/rubikplateditor.ui

TRANSLATIONS = rubik_en.ts rubik_fr.ts
