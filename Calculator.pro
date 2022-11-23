QT -= gui
QT += widgets
QT += core gui
RC_ICONS = calculator.ico

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        addition.cpp \
        calculator.cpp \
        division.cpp \
        main.cpp \
        multiplication.cpp \
        operation.cpp \
        operationfactory.cpp \
        subtraction.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    addition.h \
    calculator.h \
    division.h \
    multiplication.h \
    operation.h \
    operationfactory.h \
    subtraction.h

RESOURCES += \
    icons.qrc
