#-------------------------------------------------
#
# Project created by QtCreator 2018-09-27T13:02:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextTool
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    AddPrefixSuffixWidget.cpp \
    AddRemLineBreaksWidget.cpp \
    FindReplaceWidget.cpp \
    DelimitedColumnExtractor.cpp \
    JoinMergeTextWidget.cpp \
    RemoveDuplicatedLinesWidget.cpp \
    RemoveEmptyLinesWidget.cpp \
    RemoveExtraSpacesWidget.cpp \
    RemoveLinesContainingWidget.cpp \
    SortTextLinesWidget.cpp \
    EditLineManager.cpp \
    StringTools.cpp

HEADERS  += MainWindow.h \
    AddPrefixSuffixWidget.h \
    AddRemLineBreaksWidget.h \
    FindReplaceWidget.h \
    DelimitedColumnExtractor.h \
    JoinMergeTextWidget.h \
    RemoveDuplicatedLinesWidget.h \
    RemoveEmptyLinesWidget.h \
    RemoveExtraSpacesWidget.h \
    RemoveLinesContainingWidget.h \
    SortTextLinesWidget.h \
    EditLineManager.h \
    StringTools.h

FORMS    += MainWindow.ui \
    AddPrefixSuffixWidget.ui \
    AddRemLineBreaksWidget.ui \
    FindReplaceWidget.ui \
    DelimitedColumnExtractor.ui \
    JoinMergeTextWidget.ui \
    RemoveDuplicatedLinesWidget.ui \
    RemoveEmptyLinesWidget.ui \
    RemoveExtraSpacesWidget.ui \
    RemoveLinesContainingWidget.ui \
    SortTextLinesWidget.ui

RESOURCES += \
    texttool.qrc
