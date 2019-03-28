/********************************************************************************
** Form generated from reading UI file 'AddRemLineBreaksWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREMLINEBREAKSWIDGET_H
#define UI_ADDREMLINEBREAKSWIDGET_H

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

class Ui_CAddRemLineBreaksWidget
{
public:
    QTextEdit *m_pTextEditInput;
    QPushButton *m_pBtnRemoveAllLineBreaks;
    QLabel *m_pLabelReplaceWithThisText;
    QLineEdit *m_pLineEditTextToreplace;
    QLabel *m_pLabelBlank;
    QPushButton *m_pBtnMakeNewLineBreaks;
    QRadioButton *m_pRadioButnBefore;
    QRadioButton *m_pRadioButnAfter;
    QLineEdit *m_pLineEditTexOccurence;
    QCheckBox *m_pCheckBoxCS;
    QCheckBox *m_pCheckBoxRELB;
    QPushButton *m_pBtnMakeNewLineBreaksEvery;
    QLabel *m_pLabelEvery;
    QLineEdit *m_pLineEditTexEvery;
    QLabel *m_pLabelCharactes;
    QCheckBox *m_pCheckBoxWordWrap;
    QCheckBox *m_pCheckBoxEcapeExisting;
    QPushButton *m_pBtnSelAllOutputText;
    QPushButton *m_pBtnClearAllOutputText;
    QPushButton *m_pBtnLoadOutputIntoInput;
    QTextEdit *m_pTextEditOutput;
    QLineEdit *m_pLineEditSaveAs;
    QRadioButton *m_pRadioBtnDos;
    QPushButton *m_pBtnBrowse;
    QRadioButton *m_pRadioBtnUnix;
    QPushButton *m_pBtnAsveAs;
    QPushButton *m_pBtnLoadFile;
    QLabel *m_pLabelSelectedFile;

    void setupUi(QWidget *CAddRemLineBreaksWidget)
    {
        if (CAddRemLineBreaksWidget->objectName().isEmpty())
            CAddRemLineBreaksWidget->setObjectName(QStringLiteral("CAddRemLineBreaksWidget"));
        CAddRemLineBreaksWidget->resize(800, 600);
        m_pTextEditInput = new QTextEdit(CAddRemLineBreaksWidget);
        m_pTextEditInput->setObjectName(QStringLiteral("m_pTextEditInput"));
        m_pTextEditInput->setGeometry(QRect(10, 10, 780, 120));
        m_pBtnRemoveAllLineBreaks = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnRemoveAllLineBreaks->setObjectName(QStringLiteral("m_pBtnRemoveAllLineBreaks"));
        m_pBtnRemoveAllLineBreaks->setGeometry(QRect(10, 170, 151, 28));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        m_pBtnRemoveAllLineBreaks->setFont(font);
        m_pBtnRemoveAllLineBreaks->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pLabelReplaceWithThisText = new QLabel(CAddRemLineBreaksWidget);
        m_pLabelReplaceWithThisText->setObjectName(QStringLiteral("m_pLabelReplaceWithThisText"));
        m_pLabelReplaceWithThisText->setGeometry(QRect(170, 170, 241, 28));
        m_pLineEditTextToreplace = new QLineEdit(CAddRemLineBreaksWidget);
        m_pLineEditTextToreplace->setObjectName(QStringLiteral("m_pLineEditTextToreplace"));
        m_pLineEditTextToreplace->setGeometry(QRect(410, 170, 271, 22));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pLineEditTextToreplace->sizePolicy().hasHeightForWidth());
        m_pLineEditTextToreplace->setSizePolicy(sizePolicy);
        m_pLabelBlank = new QLabel(CAddRemLineBreaksWidget);
        m_pLabelBlank->setObjectName(QStringLiteral("m_pLabelBlank"));
        m_pLabelBlank->setGeometry(QRect(690, 170, 101, 28));
        m_pBtnMakeNewLineBreaks = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnMakeNewLineBreaks->setObjectName(QStringLiteral("m_pBtnMakeNewLineBreaks"));
        m_pBtnMakeNewLineBreaks->setGeometry(QRect(10, 220, 151, 28));
        m_pBtnMakeNewLineBreaks->setFont(font);
        m_pBtnMakeNewLineBreaks->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pRadioButnBefore = new QRadioButton(CAddRemLineBreaksWidget);
        m_pRadioButnBefore->setObjectName(QStringLiteral("m_pRadioButnBefore"));
        m_pRadioButnBefore->setGeometry(QRect(170, 220, 61, 28));
        m_pRadioButnAfter = new QRadioButton(CAddRemLineBreaksWidget);
        m_pRadioButnAfter->setObjectName(QStringLiteral("m_pRadioButnAfter"));
        m_pRadioButnAfter->setGeometry(QRect(240, 220, 221, 28));
        m_pLineEditTexOccurence = new QLineEdit(CAddRemLineBreaksWidget);
        m_pLineEditTexOccurence->setObjectName(QStringLiteral("m_pLineEditTexOccurence"));
        m_pLineEditTexOccurence->setGeometry(QRect(460, 220, 211, 22));
        sizePolicy.setHeightForWidth(m_pLineEditTexOccurence->sizePolicy().hasHeightForWidth());
        m_pLineEditTexOccurence->setSizePolicy(sizePolicy);
        m_pCheckBoxCS = new QCheckBox(CAddRemLineBreaksWidget);
        m_pCheckBoxCS->setObjectName(QStringLiteral("m_pCheckBoxCS"));
        m_pCheckBoxCS->setGeometry(QRect(680, 220, 41, 28));
        m_pCheckBoxRELB = new QCheckBox(CAddRemLineBreaksWidget);
        m_pCheckBoxRELB->setObjectName(QStringLiteral("m_pCheckBoxRELB"));
        m_pCheckBoxRELB->setGeometry(QRect(730, 220, 61, 28));
        m_pBtnMakeNewLineBreaksEvery = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnMakeNewLineBreaksEvery->setObjectName(QStringLiteral("m_pBtnMakeNewLineBreaksEvery"));
        m_pBtnMakeNewLineBreaksEvery->setGeometry(QRect(10, 270, 151, 28));
        m_pBtnMakeNewLineBreaksEvery->setFont(font);
        m_pBtnMakeNewLineBreaksEvery->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pLabelEvery = new QLabel(CAddRemLineBreaksWidget);
        m_pLabelEvery->setObjectName(QStringLiteral("m_pLabelEvery"));
        m_pLabelEvery->setGeometry(QRect(160, 270, 31, 28));
        m_pLineEditTexEvery = new QLineEdit(CAddRemLineBreaksWidget);
        m_pLineEditTexEvery->setObjectName(QStringLiteral("m_pLineEditTexEvery"));
        m_pLineEditTexEvery->setGeometry(QRect(200, 270, 51, 22));
        sizePolicy.setHeightForWidth(m_pLineEditTexEvery->sizePolicy().hasHeightForWidth());
        m_pLineEditTexEvery->setSizePolicy(sizePolicy);
        m_pLabelCharactes = new QLabel(CAddRemLineBreaksWidget);
        m_pLabelCharactes->setObjectName(QStringLiteral("m_pLabelCharactes"));
        m_pLabelCharactes->setGeometry(QRect(260, 270, 71, 28));
        m_pCheckBoxWordWrap = new QCheckBox(CAddRemLineBreaksWidget);
        m_pCheckBoxWordWrap->setObjectName(QStringLiteral("m_pCheckBoxWordWrap"));
        m_pCheckBoxWordWrap->setGeometry(QRect(330, 270, 91, 28));
        m_pCheckBoxEcapeExisting = new QCheckBox(CAddRemLineBreaksWidget);
        m_pCheckBoxEcapeExisting->setObjectName(QStringLiteral("m_pCheckBoxEcapeExisting"));
        m_pCheckBoxEcapeExisting->setGeometry(QRect(430, 270, 181, 28));
        m_pBtnSelAllOutputText = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnSelAllOutputText->setObjectName(QStringLiteral("m_pBtnSelAllOutputText"));
        m_pBtnSelAllOutputText->setGeometry(QRect(620, 270, 31, 28));
        m_pBtnSelAllOutputText->setFont(font);
        m_pBtnSelAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnClearAllOutputText = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnClearAllOutputText->setObjectName(QStringLiteral("m_pBtnClearAllOutputText"));
        m_pBtnClearAllOutputText->setGeometry(QRect(660, 270, 31, 28));
        m_pBtnClearAllOutputText->setFont(font);
        m_pBtnClearAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnLoadOutputIntoInput = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnLoadOutputIntoInput->setObjectName(QStringLiteral("m_pBtnLoadOutputIntoInput"));
        m_pBtnLoadOutputIntoInput->setGeometry(QRect(700, 270, 31, 28));
        m_pBtnLoadOutputIntoInput->setFont(font);
        m_pBtnLoadOutputIntoInput->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pTextEditOutput = new QTextEdit(CAddRemLineBreaksWidget);
        m_pTextEditOutput->setObjectName(QStringLiteral("m_pTextEditOutput"));
        m_pTextEditOutput->setGeometry(QRect(0, 320, 780, 120));
        m_pLineEditSaveAs = new QLineEdit(CAddRemLineBreaksWidget);
        m_pLineEditSaveAs->setObjectName(QStringLiteral("m_pLineEditSaveAs"));
        m_pLineEditSaveAs->setGeometry(QRect(500, 480, 141, 28));
        sizePolicy.setHeightForWidth(m_pLineEditSaveAs->sizePolicy().hasHeightForWidth());
        m_pLineEditSaveAs->setSizePolicy(sizePolicy);
        m_pRadioBtnDos = new QRadioButton(CAddRemLineBreaksWidget);
        m_pRadioBtnDos->setObjectName(QStringLiteral("m_pRadioBtnDos"));
        m_pRadioBtnDos->setGeometry(QRect(710, 480, 71, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnDos->sizePolicy().hasHeightForWidth());
        m_pRadioBtnDos->setSizePolicy(sizePolicy);
        m_pBtnBrowse = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnBrowse->setObjectName(QStringLiteral("m_pBtnBrowse"));
        m_pBtnBrowse->setGeometry(QRect(110, 480, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnBrowse->sizePolicy().hasHeightForWidth());
        m_pBtnBrowse->setSizePolicy(sizePolicy);
        m_pRadioBtnUnix = new QRadioButton(CAddRemLineBreaksWidget);
        m_pRadioBtnUnix->setObjectName(QStringLiteral("m_pRadioBtnUnix"));
        m_pRadioBtnUnix->setGeometry(QRect(650, 480, 61, 20));
        sizePolicy.setHeightForWidth(m_pRadioBtnUnix->sizePolicy().hasHeightForWidth());
        m_pRadioBtnUnix->setSizePolicy(sizePolicy);
        m_pBtnAsveAs = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnAsveAs->setObjectName(QStringLiteral("m_pBtnAsveAs"));
        m_pBtnAsveAs->setGeometry(QRect(400, 480, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnAsveAs->sizePolicy().hasHeightForWidth());
        m_pBtnAsveAs->setSizePolicy(sizePolicy);
        m_pBtnAsveAs->setFont(font);
        m_pBtnAsveAs->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnLoadFile = new QPushButton(CAddRemLineBreaksWidget);
        m_pBtnLoadFile->setObjectName(QStringLiteral("m_pBtnLoadFile"));
        m_pBtnLoadFile->setGeometry(QRect(10, 480, 93, 28));
        sizePolicy.setHeightForWidth(m_pBtnLoadFile->sizePolicy().hasHeightForWidth());
        m_pBtnLoadFile->setSizePolicy(sizePolicy);
        m_pBtnLoadFile->setFont(font);
        m_pBtnLoadFile->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pLabelSelectedFile = new QLabel(CAddRemLineBreaksWidget);
        m_pLabelSelectedFile->setObjectName(QStringLiteral("m_pLabelSelectedFile"));
        m_pLabelSelectedFile->setGeometry(QRect(210, 480, 181, 28));
        sizePolicy.setHeightForWidth(m_pLabelSelectedFile->sizePolicy().hasHeightForWidth());
        m_pLabelSelectedFile->setSizePolicy(sizePolicy);

        retranslateUi(CAddRemLineBreaksWidget);

        QMetaObject::connectSlotsByName(CAddRemLineBreaksWidget);
    } // setupUi

    void retranslateUi(QWidget *CAddRemLineBreaksWidget)
    {
        CAddRemLineBreaksWidget->setWindowTitle(QApplication::translate("CAddRemLineBreaksWidget", "Add / Remove Line Breaks", Q_NULLPTR));
        m_pBtnRemoveAllLineBreaks->setText(QApplication::translate("CAddRemLineBreaksWidget", "REMOVE ALL LINE BREAKS", Q_NULLPTR));
        m_pLabelReplaceWithThisText->setText(QApplication::translate("CAddRemLineBreaksWidget", "and replace the line break with this text:", Q_NULLPTR));
        m_pLabelBlank->setText(QApplication::translate("CAddRemLineBreaksWidget", "Blank for nothing.", Q_NULLPTR));
        m_pBtnMakeNewLineBreaks->setText(QApplication::translate("CAddRemLineBreaksWidget", "MAKE NEW LINE BREAKS", Q_NULLPTR));
        m_pRadioButnBefore->setText(QApplication::translate("CAddRemLineBreaksWidget", "before", Q_NULLPTR));
        m_pRadioButnAfter->setText(QApplication::translate("CAddRemLineBreaksWidget", "after each occurrence of this text:", Q_NULLPTR));
        m_pCheckBoxCS->setText(QApplication::translate("CAddRemLineBreaksWidget", "CS", Q_NULLPTR));
        m_pCheckBoxRELB->setText(QApplication::translate("CAddRemLineBreaksWidget", "RELB", Q_NULLPTR));
        m_pBtnMakeNewLineBreaksEvery->setText(QApplication::translate("CAddRemLineBreaksWidget", "MAKE NEW LINE BREAKS", Q_NULLPTR));
        m_pLabelEvery->setText(QApplication::translate("CAddRemLineBreaksWidget", "every", Q_NULLPTR));
        m_pLabelCharactes->setText(QApplication::translate("CAddRemLineBreaksWidget", "characters.", Q_NULLPTR));
        m_pCheckBoxWordWrap->setText(QApplication::translate("CAddRemLineBreaksWidget", "Word wrap.", Q_NULLPTR));
        m_pCheckBoxEcapeExisting->setText(QApplication::translate("CAddRemLineBreaksWidget", "Escape existing line breaks.", Q_NULLPTR));
        m_pBtnSelAllOutputText->setText(QApplication::translate("CAddRemLineBreaksWidget", "S", Q_NULLPTR));
        m_pBtnClearAllOutputText->setText(QApplication::translate("CAddRemLineBreaksWidget", "C", Q_NULLPTR));
        m_pBtnLoadOutputIntoInput->setText(QApplication::translate("CAddRemLineBreaksWidget", "U", Q_NULLPTR));
        m_pRadioBtnDos->setText(QApplication::translate("CAddRemLineBreaksWidget", "Dos", Q_NULLPTR));
        m_pBtnBrowse->setText(QApplication::translate("CAddRemLineBreaksWidget", "Browse...", Q_NULLPTR));
        m_pRadioBtnUnix->setText(QApplication::translate("CAddRemLineBreaksWidget", "Unix", Q_NULLPTR));
        m_pBtnAsveAs->setText(QApplication::translate("CAddRemLineBreaksWidget", "SAVE AS", Q_NULLPTR));
        m_pBtnLoadFile->setText(QApplication::translate("CAddRemLineBreaksWidget", "LOAD FILE", Q_NULLPTR));
        m_pLabelSelectedFile->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CAddRemLineBreaksWidget: public Ui_CAddRemLineBreaksWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREMLINEBREAKSWIDGET_H
