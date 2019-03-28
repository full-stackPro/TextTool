#include "DelimitedColumnExtractor.h"
#include "ui_DelimitedColumnExtractor.h"
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

CDelimitedColumnExtractor::CDelimitedColumnExtractor(CMainWindow* pMainWindow, QWidget *parent)
                          : QWidget(parent)
                          , ui(new Ui::CDelimitedColumnExtractor)
                          , m_pMainWindow(pMainWindow)
                          , m_strSelFileName()
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 15, 10, 30);

    QHBoxLayout* pElementsLayout0 = new QHBoxLayout();
    pElementsLayout0->addWidget(ui->m_pLabelColumns);
    pElementsLayout0->addWidget(ui->m_pLineEditColumnsText);
    pElementsLayout0->addWidget(ui->m_pLabelExtractColumn);
    pElementsLayout0->addWidget(ui->m_pLineEditExtractColumns);
    //ui->m_pLineEditExtractColumns->setText( "1" );
    pElementsLayout0->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout0);

    pWidgetLayout->addWidget(ui->m_pTextEditInput);

    QHBoxLayout* pElementsLayout1 = new QHBoxLayout();
    pElementsLayout1->addWidget(ui->m_pBtnExtractColumn);
    pElementsLayout1->addWidget(ui->m_pBtnSelAllOutputText);
    pElementsLayout1->addWidget(ui->m_pBtnClearAllOutputText);
    pElementsLayout1->addWidget(ui->m_pCheckBoxMonoFont);
    pElementsLayout1->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout1);

    pWidgetLayout->addWidget(ui->m_pTextEditOutput);

    QHBoxLayout* pElementsLayout2 = new QHBoxLayout();
    pElementsLayout2->addWidget(ui->m_pBtnLoadFile);
    pElementsLayout2->addWidget(ui->m_pBtnBrowse);
    pElementsLayout2->addWidget(ui->m_pLabelSelectedFile);
    ui->m_pLabelSelectedFile->setText("No file selected.");
    pElementsLayout2->addWidget(ui->m_pBtnAsveAs);
    pElementsLayout2->addWidget(ui->m_pLineEditSaveAs);
    ui->m_pLineEditSaveAs->setText("output.txt");
    QButtonGroup* pGroup2 = new QButtonGroup(this);
    pGroup2->addButton(ui->m_pRadioBtnUnix);
    pGroup2->addButton(ui->m_pRadioBtnDos);
    pElementsLayout2->addWidget(ui->m_pRadioBtnUnix);
    ui->m_pRadioBtnUnix->setChecked(true);
    pElementsLayout2->addWidget(ui->m_pRadioBtnDos);
    pElementsLayout2->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout2);

    connect( ui->m_pBtnBrowse, SIGNAL ( released() ), this, SLOT( BrowseFiles() ) );
    connect( ui->m_pBtnAsveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
    connect( ui->m_pBtnExtractColumn, SIGNAL ( released() ), this, SLOT( ExtractColumn() ) );
    connect( ui->m_pBtnClearAllOutputText, SIGNAL ( released() ), this, SLOT( ClearAllOutputText() ) );
    connect( ui->m_pBtnSelAllOutputText, SIGNAL ( released() ), this, SLOT( SelectAllOutputText() ) );
}

CDelimitedColumnExtractor::~CDelimitedColumnExtractor()
{
    delete ui;
}

void CDelimitedColumnExtractor::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

bool CDelimitedColumnExtractor::LoadFileFromDisc()
{
    QFile oFile(m_strSelFileName);

    if( oFile.exists() )
    {
        if( oFile.open(QIODevice::ReadOnly | QIODevice::Text) == false )
            return false;

        m_arData = oFile.readAll();

        if(m_arData.size() == 0)
        {
            oFile.close();
            return false;
        }

        QString strTest;
        strTest = m_arData;
        ui->m_pTextEditInput->setText(strTest);

        oFile.close();

        return true;
    }

    return false;
}

void CDelimitedColumnExtractor::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CDelimitedColumnExtractor::BrowseFiles()
{
    QString strFileName = QFileDialog::getOpenFileName( this, tr( "File Upload" ), QString(),
                                                                      tr( "All files (*.*)" ) );
    if(strFileName.isEmpty() == false)
    {
        m_strSelFileName = strFileName;
        if( LoadFileFromDisc() == true )
        {
            ui->m_pLabelSelectedFile->setText(strFileName);
        }
        else
        {
            m_strSelFileName.clear();
            ui->m_pLabelSelectedFile->setText("No file selected.");
            m_arData.clear();
        }
    }
    else if(m_strSelFileName.isEmpty())
    {
        ui->m_pLabelSelectedFile->setText("No file selected.");
        m_arData.clear();
    }
}

void CDelimitedColumnExtractor::SaveAs()
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

void CDelimitedColumnExtractor::ExtractColumn()
{
    QString strToExtract = ui->m_pLineEditColumnsText->text();
    QString strColumn = ui->m_pLineEditExtractColumns->text();
    if ( strToExtract.isEmpty() == true || strColumn.isEmpty() == true )
    {
        ui->m_pTextEditOutput->setText("");
        return;
    }

    int nColums = strColumn.toInt();

    QString strText = ui->m_pTextEditInput->toPlainText();
    int nSIzeInput = strText.size();
    QString strResult;

    int nIndexOfNewLine = 0;
    int nIndexOf = strText.indexOf(strToExtract, 0, Qt::CaseSensitive);
    while(nIndexOf >= 0)
    {
        QString strLeftPart = strText.left(nIndexOf);
        int nTemp = strLeftPart.lastIndexOf(g_strLineEnd, -1);
        if (nTemp > 0)
            nIndexOfNewLine = nTemp + g_strLineEnd.size();
        QString strData = strText.mid(nIndexOfNewLine, nIndexOf - nIndexOfNewLine);

        /*QByteArray arrayLatin1 = strData.toLatin1();
        char* lpszDataLatin = arrayLatin1.data();*/

        strResult += strData;
        strResult += g_strLineEnd;

        nIndexOfNewLine = strText.indexOf(g_strLineEnd, nIndexOf, Qt::CaseSensitive) + g_strLineEnd.size();
        int nNextIndex = qMax(nIndexOf + strToExtract.size(), nIndexOfNewLine);

        nIndexOf = strText.indexOf(strToExtract, nNextIndex, Qt::CaseSensitive);

    }
    int nSize = strResult.size();
    ui->m_pTextEditOutput->clear();
    ui->m_pTextEditOutput->setText( strResult );
}

void CDelimitedColumnExtractor::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditOutput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditOutput->setFocus();
        ui->m_pTextEditOutput->selectAll();
    }
}

void CDelimitedColumnExtractor::ClearAllOutputText()
{
    ui->m_pTextEditOutput->clear();
}
