/********************************************************************************
** Form generated from reading UI file 'FindReplaceWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDREPLACEWIDGET_H
#define UI_FINDREPLACEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CFindReplaceWidget
{
public:
    QTextEdit *m_pTextEditLookFor;
    QTextEdit *m_pTextEditInputOutput;
    QLabel *m_pLabelReplaceWith;
    QTextEdit *m_pTextEditReplaceWith;
    QPushButton *m_pBtnFindReplaceText;
    QCheckBox *m_pCheckBoxGlobalMatching;
    QCheckBox *m_pCheckBoxCaseSensitive;
    QPushButton *m_pBtnSelAllOutputText;
    QPushButton *m_pBtnClearAllOutputText;
    QPushButton *m_pBtnLoadFile;
    QPushButton *m_pBtnBrowse;
    QRadioButton *m_pRadioBtnDos;
    QPushButton *m_pBtnSaveAs;
    QRadioButton *m_pRadioBtnUnix;
    QLineEdit *m_pLineEditSaveAs;
    QLabel *m_pLabelWrapIs;
    QRadioButton *m_pRadioBtnWrapOn;
    QRadioButton *m_pRadioBtnWrapOff;
    QLabel *m_pFindThisLabel;
    QCheckBox *m_pCheckBoxRegularExp;
    QLabel *m_pLabelSelectedFile;
    QLabel *m_pLabelResult;

    void setupUi(QWidget *CFindReplaceWidget)
    {
        if (CFindReplaceWidget->objectName().isEmpty())
            CFindReplaceWidget->setObjectName(QStringLiteral("CFindReplaceWidget"));
        CFindReplaceWidget->resize(800, 600);
        m_pTextEditLookFor = new QTextEdit(CFindReplaceWidget);
        m_pTextEditLookFor->setObjectName(QStringLiteral("m_pTextEditLookFor"));
        m_pTextEditLookFor->setGeometry(QRect(10, 70, 780, 120));
        m_pTextEditInputOutput = new QTextEdit(CFindReplaceWidget);
        m_pTextEditInputOutput->setObjectName(QStringLiteral("m_pTextEditInputOutput"));
        m_pTextEditInputOutput->setGeometry(QRect(10, 380, 780, 120));
        m_pLabelReplaceWith = new QLabel(CFindReplaceWidget);
        m_pLabelReplaceWith->setObjectName(QStringLiteral("m_pLabelReplaceWith"));
        m_pLabelReplaceWith->setGeometry(QRect(10, 200, 100, 28));
        m_pTextEditReplaceWith = new QTextEdit(CFindReplaceWidget);
        m_pTextEditReplaceWith->setObjectName(QStringLiteral("m_pTextEditReplaceWith"));
        m_pTextEditReplaceWith->setGeometry(QRect(10, 230, 780, 90));
        m_pBtnFindReplaceText = new QPushButton(CFindReplaceWidget);
        m_pBtnFindReplaceText->setObjectName(QStringLiteral("m_pBtnFindReplaceText"));
        m_pBtnFindReplaceText->setGeometry(QRect(10, 350, 171, 28));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        m_pBtnFindReplaceText->setFont(font);
        m_pBtnFindReplaceText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pCheckBoxGlobalMatching = new QCheckBox(CFindReplaceWidget);
        m_pCheckBoxGlobalMatching->setObjectName(QStringLiteral("m_pCheckBoxGlobalMatching"));
        m_pCheckBoxGlobalMatching->setGeometry(QRect(200, 350, 121, 28));
        m_pCheckBoxCaseSensitive = new QCheckBox(CFindReplaceWidget);
        m_pCheckBoxCaseSensitive->setObjectName(QStringLiteral("m_pCheckBoxCaseSensitive"));
        m_pCheckBoxCaseSensitive->setGeometry(QRect(330, 350, 121, 28));
        m_pBtnSelAllOutputText = new QPushButton(CFindReplaceWidget);
        m_pBtnSelAllOutputText->setObjectName(QStringLiteral("m_pBtnSelAllOutputText"));
        m_pBtnSelAllOutputText->setGeometry(QRect(460, 350, 31, 28));
        m_pBtnSelAllOutputText->setFont(font);
        m_pBtnSelAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnClearAllOutputText = new QPushButton(CFindReplaceWidget);
        m_pBtnClearAllOutputText->setObjectName(QStringLiteral("m_pBtnClearAllOutputText"));
        m_pBtnClearAllOutputText->setGeometry(QRect(500, 350, 31, 28));
        m_pBtnClearAllOutputText->setFont(font);
        m_pBtnClearAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnLoadFile = new QPushButton(CFindReplaceWidget);
        m_pBtnLoadFile->setObjectName(QStringLiteral("m_pBtnLoadFile"));
        m_pBtnLoadFile->setGeometry(QRect(20, 530, 93, 28));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pBtnLoadFile->sizePolicy().hasHeightForWidth());
        m_pBtnLoadFile->setSizePolicy(sizePolicy);
        m_pBtnLoadFile->setFont(font);
        m_pBtnLoadFile->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnBrowse = new QPushButton(CFindReplaceWidget);
        m_pBtnBrowse->setObjectName(QStringLiteral("m_pBtnBrowse"));
        m_pBtnBrowse->setGeometry(QRect(120, 530, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnBrowse->sizePolicy().hasHeightForWidth());
        m_pBtnBrowse->setSizePolicy(sizePolicy);
        m_pRadioBtnDos = new QRadioButton(CFindReplaceWidget);
        m_pRadioBtnDos->setObjectName(QStringLiteral("m_pRadioBtnDos"));
        m_pRadioBtnDos->setGeometry(QRect(580, 530, 51, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnDos->sizePolicy().hasHeightForWidth());
        m_pRadioBtnDos->setSizePolicy(sizePolicy);
        m_pBtnSaveAs = new QPushButton(CFindReplaceWidget);
        m_pBtnSaveAs->setObjectName(QStringLiteral("m_pBtnSaveAs"));
        m_pBtnSaveAs->setGeometry(QRect(330, 530, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnSaveAs->sizePolicy().hasHeightForWidth());
        m_pBtnSaveAs->setSizePolicy(sizePolicy);
        m_pBtnSaveAs->setFont(font);
        m_pBtnSaveAs->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pRadioBtnUnix = new QRadioButton(CFindReplaceWidget);
        m_pRadioBtnUnix->setObjectName(QStringLiteral("m_pRadioBtnUnix"));
        m_pRadioBtnUnix->setGeometry(QRect(530, 530, 51, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnUnix->sizePolicy().hasHeightForWidth());
        m_pRadioBtnUnix->setSizePolicy(sizePolicy);
        m_pLineEditSaveAs = new QLineEdit(CFindReplaceWidget);
        m_pLineEditSaveAs->setObjectName(QStringLiteral("m_pLineEditSaveAs"));
        m_pLineEditSaveAs->setGeometry(QRect(420, 530, 101, 28));
        sizePolicy.setHeightForWidth(m_pLineEditSaveAs->sizePolicy().hasHeightForWidth());
        m_pLineEditSaveAs->setSizePolicy(sizePolicy);
        m_pLabelWrapIs = new QLabel(CFindReplaceWidget);
        m_pLabelWrapIs->setObjectName(QStringLiteral("m_pLabelWrapIs"));
        m_pLabelWrapIs->setGeometry(QRect(650, 530, 55, 20));
        m_pRadioBtnWrapOn = new QRadioButton(CFindReplaceWidget);
        m_pRadioBtnWrapOn->setObjectName(QStringLiteral("m_pRadioBtnWrapOn"));
        m_pRadioBtnWrapOn->setGeometry(QRect(700, 530, 41, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnWrapOn->sizePolicy().hasHeightForWidth());
        m_pRadioBtnWrapOn->setSizePolicy(sizePolicy);
        m_pRadioBtnWrapOff = new QRadioButton(CFindReplaceWidget);
        m_pRadioBtnWrapOff->setObjectName(QStringLiteral("m_pRadioBtnWrapOff"));
        m_pRadioBtnWrapOff->setGeometry(QRect(750, 530, 41, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnWrapOff->sizePolicy().hasHeightForWidth());
        m_pRadioBtnWrapOff->setSizePolicy(sizePolicy);
        m_pFindThisLabel = new QLabel(CFindReplaceWidget);
        m_pFindThisLabel->setObjectName(QStringLiteral("m_pFindThisLabel"));
        m_pFindThisLabel->setGeometry(QRect(20, 30, 61, 28));
        m_pCheckBoxRegularExp = new QCheckBox(CFindReplaceWidget);
        m_pCheckBoxRegularExp->setObjectName(QStringLiteral("m_pCheckBoxRegularExp"));
        m_pCheckBoxRegularExp->setGeometry(QRect(80, 30, 121, 28));
        m_pLabelSelectedFile = new QLabel(CFindReplaceWidget);
        m_pLabelSelectedFile->setObjectName(QStringLiteral("m_pLabelSelectedFile"));
        m_pLabelSelectedFile->setGeometry(QRect(220, 530, 81, 28));
        sizePolicy.setHeightForWidth(m_pLabelSelectedFile->sizePolicy().hasHeightForWidth());
        m_pLabelSelectedFile->setSizePolicy(sizePolicy);
        m_pLabelResult = new QLabel(CFindReplaceWidget);
        m_pLabelResult->setObjectName(QStringLiteral("m_pLabelResult"));
        m_pLabelResult->setGeometry(QRect(540, 350, 81, 28));
        sizePolicy.setHeightForWidth(m_pLabelResult->sizePolicy().hasHeightForWidth());
        m_pLabelResult->setSizePolicy(sizePolicy);

        retranslateUi(CFindReplaceWidget);

        QMetaObject::connectSlotsByName(CFindReplaceWidget);
    } // setupUi

    void retranslateUi(QWidget *CFindReplaceWidget)
    {
        CFindReplaceWidget->setWindowTitle(QApplication::translate("CFindReplaceWidget", "Find and Replace Text", Q_NULLPTR));
        m_pLabelReplaceWith->setText(QApplication::translate("CFindReplaceWidget", "Replace with:", Q_NULLPTR));
        m_pBtnFindReplaceText->setText(QApplication::translate("CFindReplaceWidget", "FIND AND REPLACE TEXT", Q_NULLPTR));
        m_pCheckBoxGlobalMatching->setText(QApplication::translate("CFindReplaceWidget", "Global matching.", Q_NULLPTR));
        m_pCheckBoxCaseSensitive->setText(QApplication::translate("CFindReplaceWidget", "Case sensitive.", Q_NULLPTR));
        m_pBtnSelAllOutputText->setText(QApplication::translate("CFindReplaceWidget", "S", Q_NULLPTR));
        m_pBtnClearAllOutputText->setText(QApplication::translate("CFindReplaceWidget", "C", Q_NULLPTR));
        m_pBtnLoadFile->setText(QApplication::translate("CFindReplaceWidget", "LOAD FILE", Q_NULLPTR));
        m_pBtnBrowse->setText(QApplication::translate("CFindReplaceWidget", "Browse...", Q_NULLPTR));
        m_pRadioBtnDos->setText(QApplication::translate("CFindReplaceWidget", "Dos", Q_NULLPTR));
        m_pBtnSaveAs->setText(QApplication::translate("CFindReplaceWidget", "SAVE AS", Q_NULLPTR));
        m_pRadioBtnUnix->setText(QApplication::translate("CFindReplaceWidget", "Unix", Q_NULLPTR));
        m_pLabelWrapIs->setText(QApplication::translate("CFindReplaceWidget", "Wrap is", Q_NULLPTR));
        m_pRadioBtnWrapOn->setText(QApplication::translate("CFindReplaceWidget", "on", Q_NULLPTR));
        m_pRadioBtnWrapOff->setText(QApplication::translate("CFindReplaceWidget", "off", Q_NULLPTR));
        m_pFindThisLabel->setText(QApplication::translate("CFindReplaceWidget", "Find this:", Q_NULLPTR));
        m_pCheckBoxRegularExp->setText(QApplication::translate("CFindReplaceWidget", "Enable regular expression", Q_NULLPTR));
        m_pLabelSelectedFile->setText(QString());
        m_pLabelResult->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CFindReplaceWidget: public Ui_CFindReplaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDREPLACEWIDGET_H
