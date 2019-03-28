#include "JoinMergeTextWidget.h"
#include "ui_JoinMergeTextWidget.h"
#include "MainWindow.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QButtonGroup>
#include <QtGlobal>


namespace
{
    static const QString g_strLineEnd("\n");
}

CJoinMergeTextWidget::CJoinMergeTextWidget(CMainWindow* pMainWindow, QWidget *parent)
                     : QWidget(parent)
                     , ui(new Ui::CJoinMergeTextWidget)
                     , m_pMainWindow(pMainWindow)
                     , m_strSelFileName1()
                     , m_strSelFileName2()
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 15, 10, 30);

    QHBoxLayout* pElementsLayout0 = new QHBoxLayout();
    pElementsLayout0->addWidget(ui->m_pLabelInpu1);
    pElementsLayout0->addWidget(ui->m_pBtnLoadFile1);
    pElementsLayout0->addWidget(ui->m_pBtnBrowse1);
    pElementsLayout0->addWidget(ui->m_pLabelSelectedFile1);

    pElementsLayout0->addSpacing(300);

    pElementsLayout0->addWidget(ui->m_pLabelInpu2);
    pElementsLayout0->addWidget(ui->m_pBtnLoadFile2);
    pElementsLayout0->addWidget(ui->m_pBtnBrowse2);
    pElementsLayout0->addWidget(ui->m_pLabelSelectedFile2);

    pElementsLayout0->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout0);

    pWidgetLayout->addSpacing(50);

    QHBoxLayout* pElementsLayout1 = new QHBoxLayout();

    QVBoxLayout* pVerticalLayout1 = new QVBoxLayout();
    pVerticalLayout1->addWidget(ui->m_pLabelPrefix);
    pVerticalLayout1->addWidget(ui->m_pLineEditPrefix);
    pVerticalLayout1->addWidget(ui->m_pTextEditInput1);
    pElementsLayout1->addLayout(pVerticalLayout1);

    pElementsLayout1->addSpacing(100);
    QVBoxLayout* pVerticalLayout2 = new QVBoxLayout();
    pVerticalLayout2->addWidget(ui->m_pLabelDelimiter);
    pVerticalLayout2->addWidget(ui->m_pLineEditDelimiter);
    pVerticalLayout2->addWidget(ui->m_pTextEditInput2);
    pElementsLayout1->addLayout(pVerticalLayout2);

    pElementsLayout1->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout1);

    pWidgetLayout->addSpacing(50);

    QHBoxLayout* pElementsLayout2 = new QHBoxLayout();
    pElementsLayout2->addWidget(ui->m_pBtnMergeLines);
    pElementsLayout2->addWidget(ui->m_pLabelFillVoids);
    pElementsLayout2->addWidget(ui->m_pLineEditFillVoids);
    pElementsLayout2->addSpacing(50);
    pElementsLayout2->addWidget(ui->m_pLabelJoinSets);
    pElementsLayout2->addWidget(ui->m_pLineEditJoinSets);
    pElementsLayout2->addWidget(ui->m_pBtnSelAllOutputText);
    pElementsLayout2->addWidget(ui->m_pBtnClearAllOutputText);
    pElementsLayout2->addWidget(ui->m_pBtnClearInput);
    pElementsLayout2->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout2);

    pWidgetLayout->addWidget(ui->m_pTextEditOutput);

    QHBoxLayout* pElementsLayout3 = new QHBoxLayout();
    pElementsLayout3->addWidget(ui->m_pBtnSaveAs);
    pElementsLayout3->addWidget(ui->m_pLineEditSaveAs);
    ui->m_pLineEditSaveAs->setText("output.txt");
    QButtonGroup* pGroup2 = new QButtonGroup(this);
    pGroup2->addButton(ui->m_pRadioBtnUnix);
    pGroup2->addButton(ui->m_pRadioBtnDos);
    pElementsLayout3->addWidget(ui->m_pRadioBtnUnix);
    ui->m_pRadioBtnUnix->setChecked(true);
    pElementsLayout3->addWidget(ui->m_pRadioBtnDos);
    pElementsLayout3->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout3);

    connect( ui->m_pBtnBrowse1, SIGNAL ( released() ), this, SLOT( BrowseFile1() ) );
    connect( ui->m_pBtnBrowse2, SIGNAL ( released() ), this, SLOT( BrowseFile2() ) );
    connect( ui->m_pBtnMergeLines, SIGNAL( released() ), this, SLOT( MergeFiles() ) );
    connect( ui->m_pBtnClearInput, SIGNAL( released() ), this, SLOT( ClearInputs() ) );
    connect( ui->m_pBtnSaveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
    connect( ui->m_pBtnSelAllOutputText, SIGNAL ( released() ), this, SLOT( SelectAllOutputText() ) );
    connect( ui->m_pBtnClearAllOutputText, SIGNAL ( released() ), this, SLOT( ClearAllOutputText() ) );
}

CJoinMergeTextWidget::~CJoinMergeTextWidget()
{
    delete ui;
}

void CJoinMergeTextWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

bool CJoinMergeTextWidget::LoadFileFromDisc( const QString& strFileName, QTextEdit* pTextEdit )
{
    QFile oFile(strFileName);

    if( oFile.exists() )
    {
        if( oFile.open(QIODevice::ReadOnly | QIODevice::Text) == false )
            return false;

        QByteArray arData = oFile.readAll();

        if(arData.size() == 0)
        {
            oFile.close();
            return false;
        }

        QString strTest;
        strTest = arData;
        pTextEdit->setText(strTest);

        oFile.close();

        return true;
    }

    return false;
}

void CJoinMergeTextWidget::LoadFile1()
{
    if(m_strSelFileName1.isEmpty() == false)
    {
        if( LoadFileFromDisc(m_strSelFileName1, ui->m_pTextEditInput1) )
        {
            ui->m_pLabelSelectedFile1->setText(m_strSelFileName1);
        }
    }
}

void CJoinMergeTextWidget::BrowseFile1()
{
    QString strFileName = QFileDialog::getOpenFileName( this, tr( "File Upload" ), QString(),
                                                                      tr( "All files (*.*)" ) );
    if(strFileName.isEmpty() == false)
    {
        m_strSelFileName1 = strFileName;
        if( LoadFileFromDisc(m_strSelFileName1, ui->m_pTextEditInput1) == true )
        {
            ui->m_pLabelSelectedFile1->setText(strFileName);
        }
        else
        {
            m_strSelFileName1.clear();
            ui->m_pLabelSelectedFile1->setText("No file selected.");
        }
    }
    else if(m_strSelFileName1.isEmpty())
    {
        ui->m_pLabelSelectedFile1->setText("No file selected.");
    }
}

void CJoinMergeTextWidget::LoadFile2()
{
    if(m_strSelFileName2.isEmpty() == false)
    {
        if( LoadFileFromDisc(m_strSelFileName2, ui->m_pTextEditInput2) )
        {
            ui->m_pLabelSelectedFile2->setText(m_strSelFileName2);
        }
    }
}

void CJoinMergeTextWidget::BrowseFile2()
{
    QString strFileName = QFileDialog::getOpenFileName( this, tr( "File Upload" ), QString(),
                                                                      tr( "All files (*.*)" ) );
    if(strFileName.isEmpty() == false)
    {
        m_strSelFileName2 = strFileName;
        if( LoadFileFromDisc(m_strSelFileName2, ui->m_pTextEditInput2) == true )
        {
            ui->m_pLabelSelectedFile2->setText(strFileName);
        }
        else
        {
            m_strSelFileName2.clear();
            ui->m_pLabelSelectedFile2->setText("No file selected.");
        }
    }
    else if(m_strSelFileName2.isEmpty())
    {
        ui->m_pLabelSelectedFile2->setText("No file selected.");
    }
}

void CJoinMergeTextWidget::MergeFiles()
{
    QString strInput1 = ui->m_pTextEditInput1->toPlainText();
    QString strInput2 = ui->m_pTextEditInput2->toPlainText();

    int nIndex1 = 0;// strInput1.indexOf(g_strLineEnd, 0);
    int nIndex2 = 0;// strInput2.indexOf(g_strLineEnd, 0);
    
    QString strResult;

    do
    {
        if (nIndex1 == -1 && nIndex2 == -1)
        {
            break;
        }

        if (nIndex1 != -1)
        {
            int nNextIndex1 = strInput1.indexOf( g_strLineEnd, nIndex1 + g_strLineEnd.size() );
            
            int nLength1 = nNextIndex1 > nIndex1 ? ( nNextIndex1 - nIndex1/* - g_strLineEnd.size()*/ ) : (strInput1.size() - nIndex1);

            QString strData1 = strInput1.mid(nIndex1, nLength1);

            QByteArray arrayLatin1 = strData1.toLatin1();
            char* lpszDataLatin = arrayLatin1.data();

            nIndex1 = nNextIndex1;
            if (nIndex1 >= 0)
                nIndex1 += g_strLineEnd.size();

            strResult += strData1;
        }

        if (nIndex2 != -1)
        {
            int nNextIndex2 = strInput2.indexOf(g_strLineEnd, nIndex2 + g_strLineEnd.size());

            int nLength2 = nNextIndex2 > nIndex2 ? (nNextIndex2 - nIndex2/* - g_strLineEnd.size()*/) : (strInput2.size() - nIndex2);

            QString strData2 = strInput2.mid(nIndex2, nLength2);

            QByteArray arrayLatin1 = strData2.toLatin1();
            char* lpszDataLatin = arrayLatin1.data();

            nIndex2 = nNextIndex2;
            if (nIndex2 >= 0)
                nIndex2 += g_strLineEnd.size();

            strResult += strData2;
            strResult += g_strLineEnd;
        }

    } while (true);

    ui->m_pTextEditOutput->setText(strResult);
}

void CJoinMergeTextWidget::ClearInputs()
{
    ui->m_pTextEditInput1->clear();
    ui->m_pTextEditInput2->clear();
}

void CJoinMergeTextWidget::SaveAs()
{
    QString strSaveName = ui->m_pLineEditSaveAs->text();

    QString strOutFileName = QFileDialog::getSaveFileName( this, tr( "Save as" ), strSaveName,
                                                                      tr( "All files (*.*)" ) );
    if(strOutFileName.isEmpty())
    {
        return;
    }

    QFile oOutFile(strOutFileName);
    if(oOutFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QString strText = ui->m_pTextEditOutput->toPlainText();


        oOutFile.write(strText.toStdString().c_str(), strText.size() );

        oOutFile.close();
    }
}

void CJoinMergeTextWidget::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditOutput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditOutput->setFocus();
        ui->m_pTextEditOutput->selectAll();
    }
}

void CJoinMergeTextWidget::ClearAllOutputText()
{
    ui->m_pTextEditOutput->clear();
}

