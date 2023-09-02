QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SoundsManager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    SoundsManager.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    Sounds/1/C.wav \
    Sounds/1/D.wav \
    Sounds/1/E.wav \
    Sounds/1/F.wav \
    Sounds/1/G.wav \
    Sounds/1/A.wav \
    Sounds/1/B.wav \
    Sounds/1/CSharp.wav \
    Sounds/1/FSharp.wav \
    Sounds/1/GSharp.wav \
    Sounds/1/DSharp.wav \
    Sounds/1/ASharp.wav \
    Sounds/2/C.wav \
    Sounds/2/D.wav \
    Sounds/2/E.wav \
    Sounds/2/F.wav \
    Sounds/2/G.wav \
    Sounds/2/A.wav \
    Sounds/2/B.wav \
    Sounds/2/CSharp.wav \
    Sounds/2/FSharp.wav \
    Sounds/2/GSharp.wav \
    Sounds/2/DSharp.wav \
    Sounds/2/ASharp.wav \
    Sounds/3/C.wav \
    Sounds/3/D.wav \
    Sounds/3/E.wav \
    Sounds/3/F.wav \
    Sounds/3/G.wav \
    Sounds/3/A.wav \
    Sounds/3/B.wav \
    Sounds/3/CSharp.wav \
    Sounds/3/FSharp.wav \
    Sounds/3/GSharp.wav \
    Sounds/3/DSharp.wav \
    Sounds/3/ASharp.wav \
    Sounds/4/C.wav \
    Sounds/4/D.wav \
    Sounds/4/E.wav \
    Sounds/4/F.wav \
    Sounds/4/G.wav \
    Sounds/4/A.wav \
    Sounds/4/B.wav \
    Sounds/4/CSharp.wav \
    Sounds/4/FSharp.wav \
    Sounds/4/GSharp.wav \
    Sounds/4/DSharp.wav \
    Sounds/4/ASharp.wav \
    Sounds/5/C.wav \
    Sounds/5/D.wav \
    Sounds/5/E.wav \
    Sounds/5/F.wav \
    Sounds/5/G.wav \
    Sounds/5/A.wav \
    Sounds/5/B.wav \
    Sounds/5/CSharp.wav \
    Sounds/5/FSharp.wav \
    Sounds/5/GSharp.wav \
    Sounds/5/DSharp.wav \
    Sounds/5/ASharp.wav \
    Sounds/6/C.wav \
    Sounds/6/D.wav \
    Sounds/6/E.wav \
    Sounds/6/F.wav \
    Sounds/6/G.wav \
    Sounds/6/A.wav \
    Sounds/6/B.wav \
    Sounds/6/CSharp.wav \
    Sounds/6/FSharp.wav \
    Sounds/6/GSharp.wav \
    Sounds/6/DSharp.wav \
    Sounds/6/ASharp.wav

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
