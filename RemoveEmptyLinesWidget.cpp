#include "RemoveEmptyLinesWidget.h"
#include "ui_RemoveEmptyLinesWidget.h"
#include "MainWindow.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <set>


namespace
{
    static const QString g_strLineEnd("\n");
}



CRemoveEmptyLinesWidget::CRemoveEmptyLinesWidget(CMainWindow* pMainWindow, QWidget *parent)
                        : QWidget(parent)
                        , ui(new Ui::CRemoveEmptyLinesWidget)
                        , m_pMainWindow(pMainWindow)
                        , m_strSelFileName()
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 15, 10, 30);
    pWidgetLayout->setAlignment(Qt::AlignTop);

    QHBoxLayout* pElementsLayout1 = new QHBoxLayout();
    pElementsLayout1->addWidget(ui->m_pBtnRemEmptyLines);
    pElementsLayout1->addWidget(ui->m_pCheckBoxRemoveOnlyWhiteSpace);
    ui->m_pCheckBoxRemoveOnlyWhiteSpace->setChecked(true);
    pElementsLayout1->addWidget(ui->m_pBtnSelAllOutputText  );
    pElementsLayout1->addWidget(ui->m_pBtnClearAllOutputText);
    pElementsLayout1->addWidget(ui->m_pLabelResult);
    pElementsLayout1->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout1);

    pWidgetLayout->addWidget(ui->m_pTextEditInput);

    QHBoxLayout* pElementsLayout2 = new QHBoxLayout();
    pElementsLayout2->addWidget(ui->m_pBtnLoadFile);
    pElementsLayout2->addWidget(ui->m_pBtnBrowse);
    pElementsLayout2->addWidget(ui->m_pLabelSelectedFile);
    ui->m_pLabelSelectedFile->setText("No file selected.");
    pElementsLayout2->addWidget(ui->m_pBtnSaveAs);
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
    connect( ui->m_pBtnSaveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
    connect( ui->m_pBtnSelAllOutputText, SIGNAL ( released() ), this, SLOT( SelectAllOutputText() ) );
    connect( ui->m_pBtnClearAllOutputText, SIGNAL ( released() ), this, SLOT( ClearAllOutputText() ) );
    connect( ui->m_pBtnRemEmptyLines, SIGNAL ( released() ), this, SLOT( RemoveEmptyLines() ) );
}

CRemoveEmptyLinesWidget::~CRemoveEmptyLinesWidget()
{
    delete ui;
}

void CRemoveEmptyLinesWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

bool CRemoveEmptyLinesWidget::LoadFileFromDisc()
{
    QFile oFile(m_strSelFileName);

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

        ui->m_pTextEditInput->setText( arData );
        ui->m_pLabelResult->clear();

        oFile.close();

        return true;
    }

    return false;
}

void CRemoveEmptyLinesWidget::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CRemoveEmptyLinesWidget::BrowseFiles()
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
        }
    }
    else if(m_strSelFileName.isEmpty())
    {
        ui->m_pLabelSelectedFile->setText("No file selected.");
    }
}

void CRemoveEmptyLinesWidget::SaveAs()
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
        QString strText = ui->m_pTextEditInput->toPlainText();


        oOutFile.write(strText.toStdString().c_str(), strText.size() );

        oOutFile.close();
    }
}

void CRemoveEmptyLinesWidget::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditInput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditInput->setFocus();
        ui->m_pTextEditInput->selectAll();
    }
}

void CRemoveEmptyLinesWidget::ClearAllOutputText()
{
    ui->m_pTextEditInput->clear();
    ui->m_pLabelResult->clear();
}

void CRemoveEmptyLinesWidget::RemoveEmptyLines()
{
    bool bRemoveOnlyLinesWithWhiteSpaces = ui->m_pCheckBoxRemoveOnlyWhiteSpace->isChecked();

    QString strInput = ui->m_pTextEditInput->toPlainText();
    QString strNewInput;

    int nRemovedCount = 0;
    int nStartIndex = 0;
    int nNextIndex = strInput.indexOf( g_strLineEnd, nStartIndex );

    const QString strEmpty(" ");
    while(nNextIndex != -1)
    {
        int nLineLength = nNextIndex - nStartIndex;
        QString strLine = strInput.mid( nStartIndex, nLineLength );

        if( bRemoveOnlyLinesWithWhiteSpaces == false )
        {
            QString strTemp( strLine );
            strTemp.remove( strEmpty );
            if( strTemp.size() != 0 )
            {
                if ( strNewInput.isEmpty() == false )
                {
                    strNewInput += g_strLineEnd;
                }
                strNewInput += strLine;
            }
            else
            {
                nRemovedCount++;
            }

        }
        else
        {
            int nLineSize = strLine.size();
            int nCount = strLine.count(strEmpty);
            if(nLineSize != 0 && nLineSize == nCount)
            {
                nRemovedCount++;
            }
            else
            {
                if ( strNewInput.isEmpty() == false )
                {
                    strNewInput += g_strLineEnd;
                }
                strNewInput += strLine;
            }
        }

        nStartIndex = nNextIndex + g_strLineEnd.size();

        nNextIndex = strInput.indexOf( g_strLineEnd, nStartIndex );
    }

    if ( nStartIndex < strInput.size() )
    {
        // extract the last line which doesn't end with line break

        int nLength = strInput.size() - nStartIndex;
        QString strLastLine = strInput.right( nLength );

        if( bRemoveOnlyLinesWithWhiteSpaces == false )
        {
            QString strTemp( strLastLine );
            strTemp.remove( strEmpty );
            if( strTemp.size() != 0 )
            {
                if ( strNewInput.isEmpty() == false )
                {
                    strNewInput += g_strLineEnd;
                }
                strNewInput += strLastLine;
            }
            else
            {
                nRemovedCount++;
            }
        }
        else
        {
            int nLineSize = strLastLine.size();
            int nCount = strLastLine.count(strEmpty);
            if(nLineSize != 0 && nLineSize == nCount)
            {
                nRemovedCount++;
            }
            else
            {
                if ( strNewInput.isEmpty() == false )
                {
                    strNewInput += g_strLineEnd;
                }
                strNewInput += strLastLine;
            }
        }
    }

    ui->m_pTextEditInput->setText( strNewInput );
    QString strLabel = QString("%1 empty lines removed").arg( nRemovedCount );
    ui->m_pLabelResult->setText( strLabel );
}

