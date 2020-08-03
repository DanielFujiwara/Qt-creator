#-------------------------------------------------
#
# Project created by QtCreator 2020-07-27T17:41:35
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stagetwo_smart_apartment_sys
TEMPLATE = app

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
        accountctrl.cpp \
        addnewrepair.cpp \
        caular.cpp \
        createacount.cpp \
        gamewindows.cpp \
        keyclass.cpp \
        main.cpp \
        mainwindow.cpp \
        manwindows.cpp \
        myskiplabel.cpp \
        newslabel.cpp \
        orderstatus.cpp \
        peoplegame.cpp \
        photoview.cpp \
        readrfidid.cpp \
        repairectrl.cpp \
        rfidclassthread.cpp \
        softkey.cpp \
        stopwatchgame.cpp \
        textfileinfo.cpp \
        textmainwindow.cpp \
        user_management.cpp \
        usermovie.cpp \
        userppt.cpp \
        userwindow.cpp \
        v4l2.cpp \
        videodisplay.cpp \
        weatherclock.cpp \
        welcomeppt.cpp

HEADERS += \
        accountctrl.h \
        addnewrepair.h \
        caular.h \
        countdata.h \
        createacount.h \
        fifotomplayer.h \
        gamewindows.h \
        keyclass.h \
        mainwindow.h \
        manwindows.h \
        myskiplabel.h \
        newslabel.h \
        orderstatus.h \
        peoplegame.h \
        photoview.h \
        readrfidid.h \
        repairectrl.h \
        rfidclassthread.h \
        softkey.h \
        stopwatchgame.h \
        textfileinfo.h \
        textmainwindow.h \
        ui_photoview.h \
        ui_videodisplay.h \
        user_management.h \
        usermovie.h \
        userppt.h \
        userwindow.h \
        v4l2.h \
        videodisplay.h \
        weatherclock.h \
        welcomeppt.h

FORMS += \
        addnewrepair.ui \
        caular.ui \
        createacount.ui \
        gamewindows.ui \
        mainwindow.ui \
        manwindows.ui \
        newslabel.ui \
        orderstatus.ui \
        peoplegame.ui \
        photoview.ui \
        repairectrl.ui \
        softkey.ui \
        stopwatchgame.ui \
        textfileinfo.ui \
        textmainwindow.ui \
        user_management.ui \
        usermovie.ui \
        userppt.ui \
        userwindow.ui \
        videodisplay.ui \
        weatherclock.ui \
        welcomeppt.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    photo.qrc
