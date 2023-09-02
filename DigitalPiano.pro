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
    Sounds/House/CSound.wav \
    Sounds/House/DSound.wav \
    Sounds/House/ESound.wav \
    Sounds/House/FSound.wav \
    Sounds/House/GSound.wav \
    Sounds/House/ASound.wav \
    Sounds/House/BSound.wav \
    Sounds/House/CSharpSound.wav \
    Sounds/House/FSharpSound.wav \
    Sounds/House/GSharpSound.wav \
    Sounds/House/DSharpSound.wav \
    Sounds/House/ASharpSound.wav

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
