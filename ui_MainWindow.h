/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QLabel *m_oLabelWidget;
    QPushButton *m_oBtnAddPrefixSuffix;
    QPushButton *m_oBtnAddRemoveLineBreaks;
    QPushButton *m_oBtnDelimitedExtractor;
    QPushButton *m_oBtnFindAndReplace;
    QPushButton *m_oBtnJoinMerge;
    QPushButton *m_oBtnRemoveDuplicateLines;
    QPushButton *m_oBtnRemoveEmptyLines;
    QPushButton *m_oBtnRemoveExtraSpaces;
    QPushButton *m_oBtnRemoveLinesContaining;
    QPushButton *m_oBtnSortTextLines;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWindow)
    {
        if (CMainWindow->objectName().isEmpty())
            CMainWindow->setObjectName(QStringLiteral("CMainWindow"));
        CMainWindow->resize(809, 630);
        actionOpen = new QAction(CMainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(CMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_oLabelWidget = new QLabel(centralWidget);
        m_oLabelWidget->setObjectName(QStringLiteral("m_oLabelWidget"));
        m_oLabelWidget->setGeometry(QRect(30, 10, 340, 37));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        m_oLabelWidget->setFont(font);
        m_oLabelWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        m_oBtnAddPrefixSuffix = new QPushButton(centralWidget);
        m_oBtnAddPrefixSuffix->setObjectName(QStringLiteral("m_oBtnAddPrefixSuffix"));
        m_oBtnAddPrefixSuffix->setGeometry(QRect(20, 300, 190, 50));
        m_oBtnAddPrefixSuffix->setMinimumSize(QSize(190, 50));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        m_oBtnAddPrefixSuffix->setFont(font1);
        m_oBtnAddRemoveLineBreaks = new QPushButton(centralWidget);
        m_oBtnAddRemoveLineBreaks->setObjectName(QStringLiteral("m_oBtnAddRemoveLineBreaks"));
        m_oBtnAddRemoveLineBreaks->setGeometry(QRect(220, 300, 190, 50));
        m_oBtnAddRemoveLineBreaks->setMinimumSize(QSize(190, 50));
        m_oBtnAddRemoveLineBreaks->setFont(font1);
        m_oBtnDelimitedExtractor = new QPushButton(centralWidget);
        m_oBtnDelimitedExtractor->setObjectName(QStringLiteral("m_oBtnDelimitedExtractor"));
        m_oBtnDelimitedExtractor->setGeometry(QRect(430, 300, 190, 50));
        m_oBtnDelimitedExtractor->setMinimumSize(QSize(190, 50));
        m_oBtnDelimitedExtractor->setFont(font1);
        m_oBtnFindAndReplace = new QPushButton(centralWidget);
        m_oBtnFindAndReplace->setObjectName(QStringLiteral("m_oBtnFindAndReplace"));
        m_oBtnFindAndReplace->setGeometry(QRect(20, 360, 190, 50));
        m_oBtnFindAndReplace->setMinimumSize(QSize(190, 50));
        m_oBtnFindAndReplace->setFont(font1);
        m_oBtnJoinMerge = new QPushButton(centralWidget);
        m_oBtnJoinMerge->setObjectName(QStringLiteral("m_oBtnJoinMerge"));
        m_oBtnJoinMerge->setGeometry(QRect(220, 360, 190, 50));
        m_oBtnJoinMerge->setMinimumSize(QSize(190, 50));
        m_oBtnJoinMerge->setFont(font1);
        m_oBtnRemoveDuplicateLines = new QPushButton(centralWidget);
        m_oBtnRemoveDuplicateLines->setObjectName(QStringLiteral("m_oBtnRemoveDuplicateLines"));
        m_oBtnRemoveDuplicateLines->setGeometry(QRect(430, 360, 190, 50));
        m_oBtnRemoveDuplicateLines->setMinimumSize(QSize(190, 50));
        m_oBtnRemoveDuplicateLines->setFont(font1);
        m_oBtnRemoveEmptyLines = new QPushButton(centralWidget);
        m_oBtnRemoveEmptyLines->setObjectName(QStringLiteral("m_oBtnRemoveEmptyLines"));
        m_oBtnRemoveEmptyLines->setGeometry(QRect(10, 410, 190, 50));
        m_oBtnRemoveEmptyLines->setMinimumSize(QSize(190, 50));
        m_oBtnRemoveEmptyLines->setFont(font1);
        m_oBtnRemoveExtraSpaces = new QPushButton(centralWidget);
        m_oBtnRemoveExtraSpaces->setObjectName(QStringLiteral("m_oBtnRemoveExtraSpaces"));
        m_oBtnRemoveExtraSpaces->setGeometry(QRect(220, 410, 190, 50));
        m_oBtnRemoveExtraSpaces->setMinimumSize(QSize(190, 50));
        m_oBtnRemoveExtraSpaces->setFont(font1);
        m_oBtnRemoveLinesContaining = new QPushButton(centralWidget);
        m_oBtnRemoveLinesContaining->setObjectName(QStringLiteral("m_oBtnRemoveLinesContaining"));
        m_oBtnRemoveLinesContaining->setGeometry(QRect(430, 410, 190, 50));
        m_oBtnRemoveLinesContaining->setMinimumSize(QSize(190, 50));
        m_oBtnRemoveLinesContaining->setFont(font1);
        m_oBtnSortTextLines = new QPushButton(centralWidget);
        m_oBtnSortTextLines->setObjectName(QStringLiteral("m_oBtnSortTextLines"));
        m_oBtnSortTextLines->setGeometry(QRect(10, 460, 190, 50));
        m_oBtnSortTextLines->setMinimumSize(QSize(190, 50));
        m_oBtnSortTextLines->setFont(font1);
        CMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 809, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        CMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        CMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(CMainWindow);

        QMetaObject::connectSlotsByName(CMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindow)
    {
        CMainWindow->setWindowTitle(QApplication::translate("CMainWindow", "TextTool", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("CMainWindow", "Open", Q_NULLPTR));
        m_oLabelWidget->setText(QApplication::translate("CMainWindow", "Popular Tools", Q_NULLPTR));
        m_oBtnAddPrefixSuffix->setText(QApplication::translate("CMainWindow", "Add Prefix/Suffix into Line", Q_NULLPTR));
        m_oBtnAddRemoveLineBreaks->setText(QApplication::translate("CMainWindow", "Add/Remove Line Breaks", Q_NULLPTR));
        m_oBtnDelimitedExtractor->setText(QApplication::translate("CMainWindow", "Delimited Column Extractor", Q_NULLPTR));
        m_oBtnFindAndReplace->setText(QApplication::translate("CMainWindow", "Find and Replace Text", Q_NULLPTR));
        m_oBtnJoinMerge->setText(QApplication::translate("CMainWindow", "Join/Merge Text", Q_NULLPTR));
        m_oBtnRemoveDuplicateLines->setText(QApplication::translate("CMainWindow", "Remove Duplicate Lines", Q_NULLPTR));
        m_oBtnRemoveEmptyLines->setText(QApplication::translate("CMainWindow", "Remove Empty Lines", Q_NULLPTR));
        m_oBtnRemoveExtraSpaces->setText(QApplication::translate("CMainWindow", "Remove Extra Spaces", Q_NULLPTR));
        m_oBtnRemoveLinesContaining->setText(QApplication::translate("CMainWindow", "Remove Lines Containing..", Q_NULLPTR));
        m_oBtnSortTextLines->setText(QApplication::translate("CMainWindow", "Sort Text Lines", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("CMainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CMainWindow: public Ui_CMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
