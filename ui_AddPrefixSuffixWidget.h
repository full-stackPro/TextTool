/********************************************************************************
** Form generated from reading UI file 'AddPrefixSuffixWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPREFIXSUFFIXWIDGET_H
#define UI_ADDPREFIXSUFFIXWIDGET_H

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

class Ui_CAddPrefixSuffixWidget
{
public:
    QTextEdit *m_oTextEditInput;
    QLabel *m_oLabelPrefix;
    QLineEdit *m_oLineEditPrefix;
    QLabel *m_oLabelSuffix;
    QLineEdit *m_oLineEditSuffix;
    QTextEdit *m_oTextEditOutput;
    QPushButton *m_oBtnLoadFile;
    QPushButton *m_oBtnBrowse;
    QLabel *m_oLabelSelectedFile;
    QPushButton *m_oBtnAsveAs;
    QRadioButton *m_oRadioBtnUnix;
    QRadioButton *m_oRadioBtnDos;
    QPushButton *m_oBtnAddPrefixSuffix;
    QPushButton *m_oBtnSellectAll;
    QPushButton *m_oBtnClearAll;
    QLineEdit *m_oLineEditSaveAs;

    void setupUi(QWidget *CAddPrefixSuffixWidget)
    {
        if (CAddPrefixSuffixWidget->objectName().isEmpty())
            CAddPrefixSuffixWidget->setObjectName(QStringLiteral("CAddPrefixSuffixWidget"));
        CAddPrefixSuffixWidget->resize(800, 600);
        m_oTextEditInput = new QTextEdit(CAddPrefixSuffixWidget);
        m_oTextEditInput->setObjectName(QStringLiteral("m_oTextEditInput"));
        m_oTextEditInput->setGeometry(QRect(10, 10, 780, 120));
        m_oLabelPrefix = new QLabel(CAddPrefixSuffixWidget);
        m_oLabelPrefix->setObjectName(QStringLiteral("m_oLabelPrefix"));
        m_oLabelPrefix->setGeometry(QRect(10, 140, 521, 16));
        m_oLineEditPrefix = new QLineEdit(CAddPrefixSuffixWidget);
        m_oLineEditPrefix->setObjectName(QStringLiteral("m_oLineEditPrefix"));
        m_oLineEditPrefix->setGeometry(QRect(10, 160, 780, 22));
        m_oLabelSuffix = new QLabel(CAddPrefixSuffixWidget);
        m_oLabelSuffix->setObjectName(QStringLiteral("m_oLabelSuffix"));
        m_oLabelSuffix->setGeometry(QRect(10, 190, 521, 16));
        m_oLineEditSuffix = new QLineEdit(CAddPrefixSuffixWidget);
        m_oLineEditSuffix->setObjectName(QStringLiteral("m_oLineEditSuffix"));
        m_oLineEditSuffix->setGeometry(QRect(10, 210, 780, 22));
        m_oTextEditOutput = new QTextEdit(CAddPrefixSuffixWidget);
        m_oTextEditOutput->setObjectName(QStringLiteral("m_oTextEditOutput"));
        m_oTextEditOutput->setGeometry(QRect(10, 300, 780, 120));
        m_oBtnLoadFile = new QPushButton(CAddPrefixSuffixWidget);
        m_oBtnLoadFile->setObjectName(QStringLiteral("m_oBtnLoadFile"));
        m_oBtnLoadFile->setGeometry(QRect(20, 470, 93, 28));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_oBtnLoadFile->sizePolicy().hasHeightForWidth());
        m_oBtnLoadFile->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        m_oBtnLoadFile->setFont(font);
        m_oBtnLoadFile->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_oBtnBrowse = new QPushButton(CAddPrefixSuffixWidget);
        m_oBtnBrowse->setObjectName(QStringLiteral("m_oBtnBrowse"));
        m_oBtnBrowse->setGeometry(QRect(120, 470, 93, 28));
        sizePolicy.setHeightForWidth(m_oBtnBrowse->sizePolicy().hasHeightForWidth());
        m_oBtnBrowse->setSizePolicy(sizePolicy);
        m_oLabelSelectedFile = new QLabel(CAddPrefixSuffixWidget);
        m_oLabelSelectedFile->setObjectName(QStringLiteral("m_oLabelSelectedFile"));
        m_oLabelSelectedFile->setGeometry(QRect(220, 470, 191, 28));
        sizePolicy.setHeightForWidth(m_oLabelSelectedFile->sizePolicy().hasHeightForWidth());
        m_oLabelSelectedFile->setSizePolicy(sizePolicy);
        m_oBtnAsveAs = new QPushButton(CAddPrefixSuffixWidget);
        m_oBtnAsveAs->setObjectName(QStringLiteral("m_oBtnAsveAs"));
        m_oBtnAsveAs->setGeometry(QRect(410, 470, 93, 28));
        sizePolicy.setHeightForWidth(m_oBtnAsveAs->sizePolicy().hasHeightForWidth());
        m_oBtnAsveAs->setSizePolicy(sizePolicy);
        m_oBtnAsveAs->setFont(font);
        m_oBtnAsveAs->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_oRadioBtnUnix = new QRadioButton(CAddPrefixSuffixWidget);
        m_oRadioBtnUnix->setObjectName(QStringLiteral("m_oRadioBtnUnix"));
        m_oRadioBtnUnix->setGeometry(QRect(660, 470, 61, 20));
        sizePolicy.setHeightForWidth(m_oRadioBtnUnix->sizePolicy().hasHeightForWidth());
        m_oRadioBtnUnix->setSizePolicy(sizePolicy);
        m_oRadioBtnDos = new QRadioButton(CAddPrefixSuffixWidget);
        m_oRadioBtnDos->setObjectName(QStringLiteral("m_oRadioBtnDos"));
        m_oRadioBtnDos->setGeometry(QRect(720, 470, 71, 20));
        sizePolicy.setHeightForWidth(m_oRadioBtnDos->sizePolicy().hasHeightForWidth());
        m_oRadioBtnDos->setSizePolicy(sizePolicy);
        m_oBtnAddPrefixSuffix = new QPushButton(CAddPrefixSuffixWidget);
        m_oBtnAddPrefixSuffix->setObjectName(QStringLiteral("m_oBtnAddPrefixSuffix"));
        m_oBtnAddPrefixSuffix->setGeometry(QRect(10, 250, 271, 28));
        sizePolicy.setHeightForWidth(m_oBtnAddPrefixSuffix->sizePolicy().hasHeightForWidth());
        m_oBtnAddPrefixSuffix->setSizePolicy(sizePolicy);
        m_oBtnAddPrefixSuffix->setFont(font);
        m_oBtnAddPrefixSuffix->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_oBtnSellectAll = new QPushButton(CAddPrefixSuffixWidget);
        m_oBtnSellectAll->setObjectName(QStringLiteral("m_oBtnSellectAll"));
        m_oBtnSellectAll->setGeometry(QRect(290, 250, 33, 28));
        sizePolicy.setHeightForWidth(m_oBtnSellectAll->sizePolicy().hasHeightForWidth());
        m_oBtnSellectAll->setSizePolicy(sizePolicy);
        m_oBtnSellectAll->setFont(font);
        m_oBtnSellectAll->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_oBtnClearAll = new QPushButton(CAddPrefixSuffixWidget);
        m_oBtnClearAll->setObjectName(QStringLiteral("m_oBtnClearAll"));
        m_oBtnClearAll->setGeometry(QRect(330, 250, 33, 28));
        sizePolicy.setHeightForWidth(m_oBtnClearAll->sizePolicy().hasHeightForWidth());
        m_oBtnClearAll->setSizePolicy(sizePolicy);
        m_oBtnClearAll->setFont(font);
        m_oBtnClearAll->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_oLineEditSaveAs = new QLineEdit(CAddPrefixSuffixWidget);
        m_oLineEditSaveAs->setObjectName(QStringLiteral("m_oLineEditSaveAs"));
        m_oLineEditSaveAs->setGeometry(QRect(510, 470, 141, 28));
        sizePolicy.setHeightForWidth(m_oLineEditSaveAs->sizePolicy().hasHeightForWidth());
        m_oLineEditSaveAs->setSizePolicy(sizePolicy);

        retranslateUi(CAddPrefixSuffixWidget);

        QMetaObject::connectSlotsByName(CAddPrefixSuffixWidget);
    } // setupUi

    void retranslateUi(QWidget *CAddPrefixSuffixWidget)
    {
        CAddPrefixSuffixWidget->setWindowTitle(QApplication::translate("CAddPrefixSuffixWidget", "Add Prefix and/or Suffix into Each Line", Q_NULLPTR));
        m_oLabelPrefix->setText(QApplication::translate("CAddPrefixSuffixWidget", "Add this prefix into the beginning of each line:", Q_NULLPTR));
        m_oLabelSuffix->setText(QApplication::translate("CAddPrefixSuffixWidget", "Add this prefix into the beginning of each line:", Q_NULLPTR));
        m_oBtnLoadFile->setText(QApplication::translate("CAddPrefixSuffixWidget", "LOAD FILE", Q_NULLPTR));
        m_oBtnBrowse->setText(QApplication::translate("CAddPrefixSuffixWidget", "Browse...", Q_NULLPTR));
        m_oLabelSelectedFile->setText(QString());
        m_oBtnAsveAs->setText(QApplication::translate("CAddPrefixSuffixWidget", "SAVE AS", Q_NULLPTR));
        m_oRadioBtnUnix->setText(QApplication::translate("CAddPrefixSuffixWidget", "Unix", Q_NULLPTR));
        m_oRadioBtnDos->setText(QApplication::translate("CAddPrefixSuffixWidget", "Dos", Q_NULLPTR));
        m_oBtnAddPrefixSuffix->setText(QApplication::translate("CAddPrefixSuffixWidget", "ADD PREFIX AND/OR SUFFIX", Q_NULLPTR));
        m_oBtnSellectAll->setText(QApplication::translate("CAddPrefixSuffixWidget", "S", Q_NULLPTR));
        m_oBtnClearAll->setText(QApplication::translate("CAddPrefixSuffixWidget", "C", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CAddPrefixSuffixWidget: public Ui_CAddPrefixSuffixWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPREFIXSUFFIXWIDGET_H
