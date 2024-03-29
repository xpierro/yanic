# #####################################################################
# Automatically generated by qmake (2.01a) lun. mars 9 13:06:16 2009
# #####################################################################
TEMPLATE = app
TARGET = bin/yANIC
DEPENDPATH += .
INCLUDEPATH += .
QT += network \
    xml

# Input
HEADERS += src/gui/LineEdit.h \
    src/gui/ui/ServerList.h \
    src/tools/XmlConfManager.h \
    src/gui/ChanList.h \
    src/engine/NonNativeIrcEngine.h \
    src/engine/IIrcEngine.h \
    src/gui/Nickname.h \
    src/gui/NickList.h \
    src/gui/PrivateMessage.h \
    src/gui/MainWindowView.h \
    src/gui/MainWindow.h \
    src/gui/List.h \
    src/tools/Exceptions.h \
    src/tools/DccThread.h \
    src/tools/DccServer.h \
    src/tools/DccGet.h \
    src/tools/AbstractMess.h \
    src/gui/AbstractCentralWidget.h \
    src/gui/Chan.h \
    src/main.h
SOURCES += src/gui/LineEdit.cpp \
    src/gui/ui/ServerList.cpp \
    src/tools/XmlConfManager.cpp \
    src/gui/ChanList.cpp \
    src/engine/NonNativeIrcEngine.cpp \
    src/gui/PrivateMessage.cpp \
    src/gui/Nickname.cpp \
    src/gui/NickList.cpp \
    src/gui/MainWindowView.cpp \
    src/gui/MainWindow.cpp \
    src/gui/List.cpp \
    src/tools/DccThread.cpp \
    src/tools/DccServer.cpp \
    src/tools/DccGet.cpp \
    src/tools/AbstractMess.cpp \
    src/gui/AbstractCentralWidget.cpp \
    src/gui/Chan.cpp \
    src/main.cpp
FORMS = src/gui/ui/ServerList.ui
UI_DIR = src/gui/ui
