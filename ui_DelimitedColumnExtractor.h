/********************************************************************************
** Form generated from reading UI file 'DelimitedColumnExtractor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELIMITEDCOLUMNEXTRACTOR_H
#define UI_DELIMITEDCOLUMNEXTRACTOR_H

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

class Ui_CDelimitedColumnExtractor
{
public:
    QLabel *m_pLabelColumns;
    QLineEdit *m_pLineEditColumnsText;
    QLabel *m_pLabelExtractColumn;
    QLineEdit *m_pLineEditExtractColumns;
    QTextEdit *m_pTextEditInput;
    QPushButton *m_pBtnClearAllOutputText;
    QPushButton *m_pBtnSelAllOutputText;
    QPushButton *m_pBtnExtractColumn;
    QCheckBox *m_pCheckBoxMonoFont;
    QLineEdit *m_pLineEditSaveAs;
    QPushButton *m_pBtnLoadFile;
    QLabel *m_pLabelSelectedFile;
    QPushButton *m_pBtnAsveAs;
    QTextEdit *m_pTextEditOutput;
    QPushButton *m_pBtnBrowse;
    QRadioButton *m_pRadioBtnUnix;
    QRadioButton *m_pRadioBtnDos;

    void setupUi(QWidget *CDelimitedColumnExtractor)
    {
        if (CDelimitedColumnExtractor->objectName().isEmpty())
            CDelimitedColumnExtractor->setObjectName(QStringLiteral("CDelimitedColumnExtractor"));
        CDelimitedColumnExtractor->resize(800, 600);
        m_pLabelColumns = new QLabel(CDelimitedColumnExtractor);
        m_pLabelColumns->setObjectName(QStringLiteral("m_pLabelColumns"));
        m_pLabelColumns->setGeometry(QRect(10, 10, 181, 28));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_pLabelColumns->sizePolicy().hasHeightForWidth());
        m_pLabelColumns->setSizePolicy(sizePolicy);
        m_pLineEditColumnsText = new QLineEdit(CDelimitedColumnExtractor);
        m_pLineEditColumnsText->setObjectName(QStringLiteral("m_pLineEditColumnsText"));
        m_pLineEditColumnsText->setGeometry(QRect(190, 10, 113, 22));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_pLineEditColumnsText->sizePolicy().hasHeightForWidth());
        m_pLineEditColumnsText->setSizePolicy(sizePolicy1);
        m_pLabelExtractColumn = new QLabel(CDelimitedColumnExtractor);
        m_pLabelExtractColumn->setObjectName(QStringLiteral("m_pLabelExtractColumn"));
        m_pLabelExtractColumn->setGeometry(QRect(310, 10, 101, 28));
        sizePolicy.setHeightForWidth(m_pLabelExtractColumn->sizePolicy().hasHeightForWidth());
        m_pLabelExtractColumn->setSizePolicy(sizePolicy);
        m_pLineEditExtractColumns = new QLineEdit(CDelimitedColumnExtractor);
        m_pLineEditExtractColumns->setObjectName(QStringLiteral("m_pLineEditExtractColumns"));
        m_pLineEditExtractColumns->setGeometry(QRect(410, 10, 71, 22));
        sizePolicy1.setHeightForWidth(m_pLineEditExtractColumns->sizePolicy().hasHeightForWidth());
        m_pLineEditExtractColumns->setSizePolicy(sizePolicy1);
        m_pTextEditInput = new QTextEdit(CDelimitedColumnExtractor);
        m_pTextEditInput->setObjectName(QStringLiteral("m_pTextEditInput"));
        m_pTextEditInput->setGeometry(QRect(10, 50, 780, 120));
        m_pBtnClearAllOutputText = new QPushButton(CDelimitedColumnExtractor);
        m_pBtnClearAllOutputText->setObjectName(QStringLiteral("m_pBtnClearAllOutputText"));
        m_pBtnClearAllOutputText->setGeometry(QRect(210, 190, 31, 28));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        m_pBtnClearAllOutputText->setFont(font);
        m_pBtnClearAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnSelAllOutputText = new QPushButton(CDelimitedColumnExtractor);
        m_pBtnSelAllOutputText->setObjectName(QStringLiteral("m_pBtnSelAllOutputText"));
        m_pBtnSelAllOutputText->setGeometry(QRect(170, 190, 31, 28));
        m_pBtnSelAllOutputText->setFont(font);
        m_pBtnSelAllOutputText->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pBtnExtractColumn = new QPushButton(CDelimitedColumnExtractor);
        m_pBtnExtractColumn->setObjectName(QStringLiteral("m_pBtnExtractColumn"));
        m_pBtnExtractColumn->setGeometry(QRect(10, 190, 151, 28));
        m_pBtnExtractColumn->setFont(font);
        m_pBtnExtractColumn->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pCheckBoxMonoFont = new QCheckBox(CDelimitedColumnExtractor);
        m_pCheckBoxMonoFont->setObjectName(QStringLiteral("m_pCheckBoxMonoFont"));
        m_pCheckBoxMonoFont->setGeometry(QRect(250, 190, 131, 28));
        m_pLineEditSaveAs = new QLineEdit(CDelimitedColumnExtractor);
        m_pLineEditSaveAs->setObjectName(QStringLiteral("m_pLineEditSaveAs"));
        m_pLineEditSaveAs->setGeometry(QRect(510, 400, 141, 28));
        sizePolicy1.setHeightForWidth(m_pLineEditSaveAs->sizePolicy().hasHeightForWidth());
        m_pLineEditSaveAs->setSizePolicy(sizePolicy1);
        m_pBtnLoadFile = new QPushButton(CDelimitedColumnExtractor);
        m_pBtnLoadFile->setObjectName(QStringLiteral("m_pBtnLoadFile"));
        m_pBtnLoadFile->setGeometry(QRect(20, 400, 93, 28));
        sizePolicy1.setHeightForWidth(m_pBtnLoadFile->sizePolicy().hasHeightForWidth());
        m_pBtnLoadFile->setSizePolicy(sizePolicy1);
        m_pBtnLoadFile->setFont(font);
        m_pBtnLoadFile->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pLabelSelectedFile = new QLabel(CDelimitedColumnExtractor);
        m_pLabelSelectedFile->setObjectName(QStringLiteral("m_pLabelSelectedFile"));
        m_pLabelSelectedFile->setGeometry(QRect(220, 400, 181, 28));
        sizePolicy1.setHeightForWidth(m_pLabelSelectedFile->sizePolicy().hasHeightForWidth());
        m_pLabelSelectedFile->setSizePolicy(sizePolicy1);
        m_pBtnAsveAs = new QPushButton(CDelimitedColumnExtractor);
        m_pBtnAsveAs->setObjectName(QStringLiteral("m_pBtnAsveAs"));
        m_pBtnAsveAs->setGeometry(QRect(410, 400, 93, 28));
        sizePolicy1.setHeightForWidth(m_pBtnAsveAs->sizePolicy().hasHeightForWidth());
        m_pBtnAsveAs->setSizePolicy(sizePolicy1);
        m_pBtnAsveAs->setFont(font);
        m_pBtnAsveAs->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);"));
        m_pTextEditOutput = new QTextEdit(CDelimitedColumnExtractor);
        m_pTextEditOutput->setObjectName(QStringLiteral("m_pTextEditOutput"));
        m_pTextEditOutput->setGeometry(QRect(10, 240, 780, 120));
        m_pBtnBrowse = new QPushButton(CDelimitedColumnExtractor);
        m_pBtnBrowse->setObjectName(QStringLiteral("m_pBtnBrowse"));
        m_pBtnBrowse->setGeometry(QRect(120, 400, 93, 28));
        sizePolicy1.setHeightForWidth(m_pBtnBrowse->sizePolicy().hasHeightForWidth());
        m_pBtnBrowse->setSizePolicy(sizePolicy1);
        m_pRadioBtnUnix = new QRadioButton(CDelimitedColumnExtractor);
        m_pRadioBtnUnix->setObjectName(QStringLiteral("m_pRadioBtnUnix"));
        m_pRadioBtnUnix->setGeometry(QRect(660, 400, 61, 20));
        sizePolicy1.setHeightForWidth(m_pRadioBtnUnix->sizePolicy().hasHeightForWidth());
        m_pRadioBtnUnix->setSizePolicy(sizePolicy1);
        m_pRadioBtnDos = new QRadioButton(CDelimitedColumnExtractor);
        m_pRadioBtnDos->setObjectName(QStringLiteral("m_pRadioBtnDos"));
        m_pRadioBtnDos->setGeometry(QRect(720, 400, 71, 20));
        sizePolicy1.setHeightForWidth(m_pRadioBtnDos->sizePolicy().hasHeightForWidth());
        m_pRadioBtnDos->setSizePolicy(sizePolicy1);

        retranslateUi(CDelimitedColumnExtractor);

        QMetaObject::connectSlotsByName(CDelimitedColumnExtractor);
    } // setupUi

    void retranslateUi(QWidget *CDelimitedColumnExtractor)
    {
        CDelimitedColumnExtractor->setWindowTitle(QApplication::translate("CDelimitedColumnExtractor", "Delimited Column Extractor", Q_NULLPTR));
        m_pLabelColumns->setText(QApplication::translate("CDelimitedColumnExtractor", "Columns delimited by this text:", Q_NULLPTR));
        m_pLabelExtractColumn->setText(QApplication::translate("CDelimitedColumnExtractor", "Extract column # ", Q_NULLPTR));
        m_pBtnClearAllOutputText->setText(QApplication::translate("CDelimitedColumnExtractor", "C", Q_NULLPTR));
        m_pBtnSelAllOutputText->setText(QApplication::translate("CDelimitedColumnExtractor", "S", Q_NULLPTR));
        m_pBtnExtractColumn->setText(QApplication::translate("CDelimitedColumnExtractor", "EXTRACT COLUMN", Q_NULLPTR));
        m_pCheckBoxMonoFont->setText(QApplication::translate("CDelimitedColumnExtractor", "Monospaced font. ", Q_NULLPTR));
        m_pBtnLoadFile->setText(QApplication::translate("CDelimitedColumnExtractor", "LOAD FILE", Q_NULLPTR));
        m_pLabelSelectedFile->setText(QString());
        m_pBtnAsveAs->setText(QApplication::translate("CDelimitedColumnExtractor", "SAVE AS", Q_NULLPTR));
        m_pBtnBrowse->setText(QApplication::translate("CDelimitedColumnExtractor", "Browse...", Q_NULLPTR));
        m_pRadioBtnUnix->setText(QApplication::translate("CDelimitedColumnExtractor", "Unix", Q_NULLPTR));
        m_pRadioBtnDos->setText(QApplication::translate("CDelimitedColumnExtractor", "Dos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CDelimitedColumnExtractor: public Ui_CDelimitedColumnExtractor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIMITEDCOLUMNEXTRACTOR_H
