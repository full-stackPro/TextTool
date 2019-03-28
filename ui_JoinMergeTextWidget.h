/********************************************************************************
** Form generated from reading UI file 'JoinMergeTextWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINMERGETEXTWIDGET_H
#define UI_JOINMERGETEXTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CJoinMergeTextWidget
{
public:
    QLabel *m_pLabelSelectedFile1;
    QLineEdit *m_pLineEditSaveAs;
    QRadioButton *m_pRadioBtnUnix;
    QPushButton *m_pBtnBrowse1;
    QRadioButton *m_pRadioBtnDos;
    QPushButton *m_pBtnSaveAs;
    QPushButton *m_pBtnLoadFile1;
    QLabel *m_pLabelInpu1;
    QPushButton *m_pBtnBrowse2;
    QPushButton *m_pBtnLoadFile2;
    QLabel *m_pLabelInpu2;
    QLabel *m_pLabelSelectedFile2;
    QLabel *m_pLabelPrefix;
    QLineEdit *m_pLineEditPrefix;
    QTextEdit *m_pTextEditInput1;
    QLabel *m_pLabelDelimiter;
    QLineEdit *m_pLineEditDelimiter;
    QTextEdit *m_pTextEditInput2;
    QPushButton *m_pBtnMergeLines;
    QLabel *m_pLabelFillVoids;
    QLineEdit *m_pLineEditFillVoids;
    QLabel *m_pLabelJoinSets;
    QLineEdit *m_pLineEditJoinSets;
    QPushButton *m_pBtnClearAllOutputText;
    QPushButton *m_pBtnSelAllOutputText;
    QPushButton *m_pBtnClearInput;
    QTextEdit *m_pTextEditOutput;

    void setupUi(QWidget *CJoinMergeTextWidget)
    {
        if (CJoinMergeTextWidget->objectName().isEmpty())
            CJoinMergeTextWidget->setObjectName(QStringLiteral("CJoinMergeTextWidget"));
        CJoinMergeTextWidget->resize(800, 600);
        m_pLabelSelectedFile1 = new QLabel(CJoinMergeTextWidget);
        m_pLabelSelectedFile1->setObjectName(QStringLiteral("m_pLabelSelectedFile1"));
        m_pLabelSelectedFile1->setGeometry(QRect(280, 90, 101, 28));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pLabelSelectedFile1->sizePolicy().hasHeightForWidth());
        m_pLabelSelectedFile1->setSizePolicy(sizePolicy);
        m_pLineEditSaveAs = new QLineEdit(CJoinMergeTextWidget);
        m_pLineEditSaveAs->setObjectName(QStringLiteral("m_pLineEditSaveAs"));
        m_pLineEditSaveAs->setGeometry(QRect(110, 560, 141, 28));
        sizePolicy.setHeightForWidth(m_pLineEditSaveAs->sizePolicy().hasHeightForWidth());
        m_pLineEditSaveAs->setSizePolicy(sizePolicy);
        m_pRadioBtnUnix = new QRadioButton(CJoinMergeTextWidget);
        m_pRadioBtnUnix->setObjectName(QStringLiteral("m_pRadioBtnUnix"));
        m_pRadioBtnUnix->setGeometry(QRect(260, 560, 61, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnUnix->sizePolicy().hasHeightForWidth());
        m_pRadioBtnUnix->setSizePolicy(sizePolicy);
        m_pBtnBrowse1 = new QPushButton(CJoinMergeTextWidget);
        m_pBtnBrowse1->setObjectName(QStringLiteral("m_pBtnBrowse1"));
        m_pBtnBrowse1->setGeometry(QRect(180, 90, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnBrowse1->sizePolicy().hasHeightForWidth());
        m_pBtnBrowse1->setSizePolicy(sizePolicy);
        m_pRadioBtnDos = new QRadioButton(CJoinMergeTextWidget);
        m_pRadioBtnDos->setObjectName(QStringLiteral("m_pRadioBtnDos"));
        m_pRadioBtnDos->setGeometry(QRect(320, 560, 71, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnDos->sizePolicy().hasHeightForWidth());
        m_pRadioBtnDos->setSizePolicy(sizePolicy);
        m_pBtnSaveAs = new QPushButton(CJoinMergeTextWidget);
        m_pBtnSaveAs->setObjectName(QStringLiteral("m_pBtnSaveAs"));
        m_pBtnSaveAs->setGeometry(QRect(10, 560, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnSaveAs->sizePolicy().hasHeightForWidth());
        m_pBtnSaveAs->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        m_pBtnSaveAs->setFont(font);
        m_pBtnSaveAs->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnLoadFile1 = new QPushButton(CJoinMergeTextWidget);
        m_pBtnLoadFile1->setObjectName(QStringLiteral("m_pBtnLoadFile1"));
        m_pBtnLoadFile1->setGeometry(QRect(80, 90, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnLoadFile1->sizePolicy().hasHeightForWidth());
        m_pBtnLoadFile1->setSizePolicy(sizePolicy);
        m_pBtnLoadFile1->setFont(font);
        m_pBtnLoadFile1->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pLabelInpu1 = new QLabel(CJoinMergeTextWidget);
        m_pLabelInpu1->setObjectName(QStringLiteral("m_pLabelInpu1"));
        m_pLabelInpu1->setGeometry(QRect(40, 90, 41, 28));
        m_pBtnBrowse2 = new QPushButton(CJoinMergeTextWidget);
        m_pBtnBrowse2->setObjectName(QStringLiteral("m_pBtnBrowse2"));
        m_pBtnBrowse2->setGeometry(QRect(530, 90, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnBrowse2->sizePolicy().hasHeightForWidth());
        m_pBtnBrowse2->setSizePolicy(sizePolicy);
        m_pBtnLoadFile2 = new QPushButton(CJoinMergeTextWidget);
        m_pBtnLoadFile2->setObjectName(QStringLiteral("m_pBtnLoadFile2"));
        m_pBtnLoadFile2->setGeometry(QRect(430, 90, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnLoadFile2->sizePolicy().hasHeightForWidth());
        m_pBtnLoadFile2->setSizePolicy(sizePolicy);
        m_pBtnLoadFile2->setFont(font);
        m_pBtnLoadFile2->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pLabelInpu2 = new QLabel(CJoinMergeTextWidget);
        m_pLabelInpu2->setObjectName(QStringLiteral("m_pLabelInpu2"));
        m_pLabelInpu2->setGeometry(QRect(390, 90, 41, 28));
        m_pLabelSelectedFile2 = new QLabel(CJoinMergeTextWidget);
        m_pLabelSelectedFile2->setObjectName(QStringLiteral("m_pLabelSelectedFile2"));
        m_pLabelSelectedFile2->setGeometry(QRect(630, 90, 111, 28));
        sizePolicy.setHeightForWidth(m_pLabelSelectedFile2->sizePolicy().hasHeightForWidth());
        m_pLabelSelectedFile2->setSizePolicy(sizePolicy);
        m_pLabelPrefix = new QLabel(CJoinMergeTextWidget);
        m_pLabelPrefix->setObjectName(QStringLiteral("m_pLabelPrefix"));
        m_pLabelPrefix->setGeometry(QRect(40, 130, 41, 28));
        m_pLineEditPrefix = new QLineEdit(CJoinMergeTextWidget);
        m_pLineEditPrefix->setObjectName(QStringLiteral("m_pLineEditPrefix"));
        m_pLineEditPrefix->setGeometry(QRect(40, 160, 120, 28));
        sizePolicy.setHeightForWidth(m_pLineEditPrefix->sizePolicy().hasHeightForWidth());
        m_pLineEditPrefix->setSizePolicy(sizePolicy);
        m_pTextEditInput1 = new QTextEdit(CJoinMergeTextWidget);
        m_pTextEditInput1->setObjectName(QStringLiteral("m_pTextEditInput1"));
        m_pTextEditInput1->setGeometry(QRect(40, 190, 201, 120));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_pTextEditInput1->sizePolicy().hasHeightForWidth());
        m_pTextEditInput1->setSizePolicy(sizePolicy1);
        m_pLabelDelimiter = new QLabel(CJoinMergeTextWidget);
        m_pLabelDelimiter->setObjectName(QStringLiteral("m_pLabelDelimiter"));
        m_pLabelDelimiter->setGeometry(QRect(430, 130, 61, 28));
        m_pLineEditDelimiter = new QLineEdit(CJoinMergeTextWidget);
        m_pLineEditDelimiter->setObjectName(QStringLiteral("m_pLineEditDelimiter"));
        m_pLineEditDelimiter->setGeometry(QRect(430, 160, 120, 28));
        sizePolicy.setHeightForWidth(m_pLineEditDelimiter->sizePolicy().hasHeightForWidth());
        m_pLineEditDelimiter->setSizePolicy(sizePolicy);
        m_pTextEditInput2 = new QTextEdit(CJoinMergeTextWidget);
        m_pTextEditInput2->setObjectName(QStringLiteral("m_pTextEditInput2"));
        m_pTextEditInput2->setGeometry(QRect(430, 190, 201, 120));
        sizePolicy1.setHeightForWidth(m_pTextEditInput2->sizePolicy().hasHeightForWidth());
        m_pTextEditInput2->setSizePolicy(sizePolicy1);
        m_pBtnMergeLines = new QPushButton(CJoinMergeTextWidget);
        m_pBtnMergeLines->setObjectName(QStringLiteral("m_pBtnMergeLines"));
        m_pBtnMergeLines->setGeometry(QRect(10, 350, 93, 28));
        m_pBtnMergeLines->setFont(font);
        m_pBtnMergeLines->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pLabelFillVoids = new QLabel(CJoinMergeTextWidget);
        m_pLabelFillVoids->setObjectName(QStringLiteral("m_pLabelFillVoids"));
        m_pLabelFillVoids->setGeometry(QRect(110, 350, 91, 28));
        m_pLineEditFillVoids = new QLineEdit(CJoinMergeTextWidget);
        m_pLineEditFillVoids->setObjectName(QStringLiteral("m_pLineEditFillVoids"));
        m_pLineEditFillVoids->setGeometry(QRect(200, 350, 61, 28));
        sizePolicy.setHeightForWidth(m_pLineEditFillVoids->sizePolicy().hasHeightForWidth());
        m_pLineEditFillVoids->setSizePolicy(sizePolicy);
        m_pLabelJoinSets = new QLabel(CJoinMergeTextWidget);
        m_pLabelJoinSets->setObjectName(QStringLiteral("m_pLabelJoinSets"));
        m_pLabelJoinSets->setGeometry(QRect(290, 350, 91, 28));
        m_pLineEditJoinSets = new QLineEdit(CJoinMergeTextWidget);
        m_pLineEditJoinSets->setObjectName(QStringLiteral("m_pLineEditJoinSets"));
        m_pLineEditJoinSets->setGeometry(QRect(380, 350, 61, 28));
        sizePolicy.setHeightForWidth(m_pLineEditJoinSets->sizePolicy().hasHeightForWidth());
        m_pLineEditJoinSets->setSizePolicy(sizePolicy);
        m_pBtnClearAllOutputText = new QPushButton(CJoinMergeTextWidget);
        m_pBtnClearAllOutputText->setObjectName(QStringLiteral("m_pBtnClearAllOutputText"));
        m_pBtnClearAllOutputText->setGeometry(QRect(500, 350, 33, 28));
        sizePolicy.setHeightForWidth(m_pBtnClearAllOutputText->sizePolicy().hasHeightForWidth());
        m_pBtnClearAllOutputText->setSizePolicy(sizePolicy);
        m_pBtnClearAllOutputText->setFont(font);
        m_pBtnClearAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnSelAllOutputText = new QPushButton(CJoinMergeTextWidget);
        m_pBtnSelAllOutputText->setObjectName(QStringLiteral("m_pBtnSelAllOutputText"));
        m_pBtnSelAllOutputText->setGeometry(QRect(460, 350, 33, 28));
        sizePolicy.setHeightForWidth(m_pBtnSelAllOutputText->sizePolicy().hasHeightForWidth());
        m_pBtnSelAllOutputText->setSizePolicy(sizePolicy);
        m_pBtnSelAllOutputText->setFont(font);
        m_pBtnSelAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnClearInput = new QPushButton(CJoinMergeTextWidget);
        m_pBtnClearInput->setObjectName(QStringLiteral("m_pBtnClearInput"));
        m_pBtnClearInput->setGeometry(QRect(540, 350, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnClearInput->sizePolicy().hasHeightForWidth());
        m_pBtnClearInput->setSizePolicy(sizePolicy);
        m_pBtnClearInput->setFont(font);
        m_pBtnClearInput->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pTextEditOutput = new QTextEdit(CJoinMergeTextWidget);
        m_pTextEditOutput->setObjectName(QStringLiteral("m_pTextEditOutput"));
        m_pTextEditOutput->setGeometry(QRect(10, 400, 780, 120));

        retranslateUi(CJoinMergeTextWidget);

        QMetaObject::connectSlotsByName(CJoinMergeTextWidget);
    } // setupUi

    void retranslateUi(QWidget *CJoinMergeTextWidget)
    {
        CJoinMergeTextWidget->setWindowTitle(QApplication::translate("CJoinMergeTextWidget", "Join/Merge Text (Line by Line)", Q_NULLPTR));
        m_pLabelSelectedFile1->setText(QString());
        m_pRadioBtnUnix->setText(QApplication::translate("CJoinMergeTextWidget", "Unix", Q_NULLPTR));
        m_pBtnBrowse1->setText(QApplication::translate("CJoinMergeTextWidget", "Browse...", Q_NULLPTR));
        m_pRadioBtnDos->setText(QApplication::translate("CJoinMergeTextWidget", "Dos", Q_NULLPTR));
        m_pBtnSaveAs->setText(QApplication::translate("CJoinMergeTextWidget", "SAVE AS", Q_NULLPTR));
        m_pBtnLoadFile1->setText(QApplication::translate("CJoinMergeTextWidget", "LOAD FILE", Q_NULLPTR));
        m_pLabelInpu1->setText(QApplication::translate("CJoinMergeTextWidget", "Input 1", Q_NULLPTR));
        m_pBtnBrowse2->setText(QApplication::translate("CJoinMergeTextWidget", "Browse...", Q_NULLPTR));
        m_pBtnLoadFile2->setText(QApplication::translate("CJoinMergeTextWidget", "LOAD FILE", Q_NULLPTR));
        m_pLabelInpu2->setText(QApplication::translate("CJoinMergeTextWidget", "Input 2", Q_NULLPTR));
        m_pLabelSelectedFile2->setText(QString());
        m_pLabelPrefix->setText(QApplication::translate("CJoinMergeTextWidget", "Prefix", Q_NULLPTR));
        m_pLabelDelimiter->setText(QApplication::translate("CJoinMergeTextWidget", "Delimiter", Q_NULLPTR));
        m_pBtnMergeLines->setText(QApplication::translate("CJoinMergeTextWidget", "MERGE LINES", Q_NULLPTR));
        m_pLabelFillVoids->setText(QApplication::translate("CJoinMergeTextWidget", "Fille voids with", Q_NULLPTR));
        m_pLabelJoinSets->setText(QApplication::translate("CJoinMergeTextWidget", "Join sets with", Q_NULLPTR));
        m_pBtnClearAllOutputText->setText(QApplication::translate("CJoinMergeTextWidget", "C", Q_NULLPTR));
        m_pBtnSelAllOutputText->setText(QApplication::translate("CJoinMergeTextWidget", "S", Q_NULLPTR));
        m_pBtnClearInput->setText(QApplication::translate("CJoinMergeTextWidget", "CLEAR INPUT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CJoinMergeTextWidget: public Ui_CJoinMergeTextWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINMERGETEXTWIDGET_H
