#include "RemoveDuplicatedLinesWidget.h"
#include "ui_RemoveDuplicatedLinesWidget.h"
#include "MainWindow.h"
#include "StringTools.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QProgressDialog>
#include <set>



CRemoveDuplicatedLinesWidget::CRemoveDuplicatedLinesWidget(CMainWindow* pMainWindow, QWidget *parent)
                             : QWidget(parent)
                             , ui(new Ui::CRemoveDuplicatedLinesWidget)
                             , m_pMainWindow(pMainWindow)
                             , m_strSelFileName()
                             , m_pEditLinesManager(nullptr)
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 30, 10, 30);
    pWidgetLayout->setAlignment(Qt::AlignTop);

    QHBoxLayout* pElementsLayout1 = new QHBoxLayout();
    pElementsLayout1->addWidget(ui->m_pBtnRemDuplicateLines);
    pElementsLayout1->addWidget(ui->m_pCheckBoxCaseSensitive);
    pElementsLayout1->addWidget(ui->m_pCheckBoxRemoveEmptyLines);
    pElementsLayout1->addWidget(ui->m_pCheckBoxDisplaRemoved);
    pElementsLayout1->addWidget(ui->m_pCheckBoxDisplayOutput);
    pElementsLayout1->addWidget(ui->m_pBtnSelAllOutputText);
    ui->m_pBtnSelAllOutputText->setVisible(false);
    pElementsLayout1->addWidget(ui->m_pBtnClearAllOutputText);
    ui->m_pBtnClearAllOutputText->setVisible(false);
    pElementsLayout1->addWidget(ui->m_pLabelResult);
    pElementsLayout1->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout1);

    pWidgetLayout->addWidget(ui->m_pTextEditInput);
    ui->m_pTextEditInput->setVisible(false);

    pWidgetLayout->addSpacing(50);

    pWidgetLayout->addWidget(ui->m_pTextEditOutput);
    ui->m_pTextEditOutput->setVisible(false);

    QHBoxLayout* pElementsLayout4 = new QHBoxLayout();
    pElementsLayout4->addWidget(ui->m_pBtnLoadFile);
    pElementsLayout4->addWidget(ui->m_pBtnBrowse);
    pElementsLayout4->addWidget(ui->m_pLabelSelectedFile);
    ui->m_pLabelSelectedFile->setText("No file selected.");
    pElementsLayout4->addWidget(ui->m_pBtnSaveAs);
    pElementsLayout4->addWidget(ui->m_pLineEditSaveAs);
    ui->m_pLineEditSaveAs->setText("output.txt");
    QButtonGroup* pGroup2 = new QButtonGroup(this);
    pGroup2->addButton(ui->m_pRadioBtnUnix);
    pGroup2->addButton(ui->m_pRadioBtnDos);
    pElementsLayout4->addWidget(ui->m_pRadioBtnUnix);
    ui->m_pRadioBtnUnix->setChecked(true);
    pElementsLayout4->addWidget(ui->m_pRadioBtnDos);
    pElementsLayout4->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout4);

    m_pEditLinesManager = new CEditLineManager( this, ui->m_pTextEditInput, ui->m_pTextEditOutput );

    connect( ui->m_pBtnBrowse, SIGNAL ( released() ), this, SLOT( BrowseFiles() ) );
    connect( ui->m_pBtnLoadFile, SIGNAL ( released() ), this, SLOT( LoadFile() ) );
    connect( ui->m_pCheckBoxDisplaRemoved, SIGNAL ( released() ), this, SLOT( DisplayRemoved() ) );
    connect( ui->m_pCheckBoxDisplayOutput, SIGNAL ( released() ), this, SLOT( DisplayOutput() ) );
    connect( ui->m_pBtnSaveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
    connect( ui->m_pBtnSelAllOutputText, SIGNAL ( released() ), this, SLOT( SelectAllOutputText() ) );
    connect( ui->m_pBtnClearAllOutputText, SIGNAL ( released() ), this, SLOT( ClearAllOutputText() ) );
    connect( ui->m_pBtnRemDuplicateLines, SIGNAL ( released() ), this, SLOT( RemoveDuplicateLines() ) );
}

CRemoveDuplicatedLinesWidget::~CRemoveDuplicatedLinesWidget()
{
    delete ui;

    delete m_pEditLinesManager;
    m_pEditLinesManager = nullptr;
}

void CRemoveDuplicatedLinesWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

bool CRemoveDuplicatedLinesWidget::LoadFileFromDisc()
{
    QFile oFile(m_strSelFileName);

    m_strInputData.clear();
    ui->m_pTextEditInput->clear();
    ui->m_pTextEditOutput->clear();
     ui->m_pLabelResult->clear();

    m_pEditLinesManager->ClearSourceLines();
    m_pEditLinesManager->ClearRemovedLines();

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

        m_strInputData = arData;

        m_pEditLinesManager->SetSourceLines( m_strInputData );

        if( ui->m_pTextEditInput->isVisible() )
        {
            m_pEditLinesManager->ShowSourceTextEditContent();
        }

        oFile.close();

        return true;
    }

    return false;
}

void CRemoveDuplicatedLinesWidget::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CRemoveDuplicatedLinesWidget::BrowseFiles()
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

void CRemoveDuplicatedLinesWidget::SaveAs()
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
        QString strText = m_strInputData;


        oOutFile.write( strText.toStdString().c_str(), strText.size() );

        oOutFile.close();
    }
}

void CRemoveDuplicatedLinesWidget::DisplayRemoved()
{
    bool bChecked = ui->m_pCheckBoxDisplaRemoved->isChecked();
    bool bVisible = ui->m_pTextEditInput->isVisible();

    ui->m_pTextEditOutput->setVisible(bChecked);
    ui->m_pBtnSelAllOutputText->setVisible( bChecked || bVisible );
    ui->m_pBtnClearAllOutputText->setVisible( bChecked || bVisible );

    if( bChecked == true )
    {
        m_pEditLinesManager->ShowRemovedTextEditContent();
    }
}

void CRemoveDuplicatedLinesWidget::DisplayOutput()
{
    bool bChecked = ui->m_pCheckBoxDisplayOutput->isChecked();
    bool bVisible = ui->m_pTextEditInput->isVisible();

    ui->m_pTextEditInput->setVisible(bChecked);
    ui->m_pBtnSelAllOutputText->setVisible( bChecked || bVisible );
    ui->m_pBtnClearAllOutputText->setVisible( bChecked || bVisible );

    if( bChecked == true )
    {
        m_pEditLinesManager->ShowSourceTextEditContent();
    }
}

void CRemoveDuplicatedLinesWidget::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditInput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditInput->setFocus();
        ui->m_pTextEditInput->selectAll();
    }
}

void CRemoveDuplicatedLinesWidget::ClearAllOutputText()
{
    ui->m_pTextEditInput->clear();
    ui->m_pTextEditOutput->clear();
    ui->m_pLabelResult->clear();

    m_strInputData.clear();

    m_pEditLinesManager->ClearSourceLines();
    m_pEditLinesManager->ClearRemovedLines();
}

void CRemoveDuplicatedLinesWidget::RemoveDuplicateLines()
{
    const QStringList& listSourceLines = m_pEditLinesManager->GetSourceLinesList();

    int nListSize = listSourceLines.size();
    QProgressDialog oProgressDlg( "Remove duplicated lines", "Abort", 0, nListSize, this, Qt::CustomizeWindowHint );
    oProgressDlg.setWindowModality( Qt::WindowModal );

    m_pEditLinesManager->ClearRemovedLines();
    ui->m_pLabelResult->clear();

    bool bCaseSensitive = ui->m_pCheckBoxCaseSensitive->isChecked();
    Qt::CaseSensitivity cs = bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive;

    bool bRemoveEmptyLines = ui->m_pCheckBoxRemoveEmptyLines->isChecked();
    int nEmptyLinesCounter = 0;

    QString strInput = m_strInputData;//ui->m_pTextEditInput->toPlainText();
    QString strNewInput;

    int nStartIndex = 0;
    int nNextIndex = strInput.indexOf( CStringTools::g_strLineEnd, nStartIndex, cs );

    std::set<QString> setLines;
    std::set<QString> setDuplicates;

    int nProgressIndex = 0;
    while( nStartIndex < strInput.size() )
    {
        oProgressDlg.setValue( nProgressIndex++ );
        if( oProgressDlg.wasCanceled() )
            break;

        int nLineLength = nNextIndex != - 1 ? nNextIndex - nStartIndex : -1;
        QString strLine = strInput.mid( nStartIndex, nLineLength );

        QString strDataToAdd(strLine);
        if ( bCaseSensitive == false )
        {
            strDataToAdd = strLine.toUpper();
        }

        if ( setLines.find( strDataToAdd ) == setLines.end() )
        {
            setLines.insert( strDataToAdd );
            bool bAdd = true;

            if ( bRemoveEmptyLines == true )
            {
                QString strNoEmpty( strLine );

                strNoEmpty.remove(" ");
                if( strNoEmpty.isEmpty() == true )
                {
                    bAdd = false;
                    nEmptyLinesCounter++;
                }
            }
            if( bAdd == true )
            {
                if ( strNewInput.isEmpty() == false )
                {
                    strNewInput += CStringTools::g_strLineEnd;
                }
                strNewInput += strLine;
            }
        }
        else
        {
            if ( setDuplicates.find( strDataToAdd ) == setDuplicates.end() )
            {
                setDuplicates.insert( strDataToAdd );
                m_pEditLinesManager->AddRemovedLine( strLine );

                /*if ( strRemoved.isEmpty() == false )
                {
                    strRemoved += g_strLineEnd;
                }
                strRemoved += strLine;*/
            }
        }

        if( nNextIndex == -1 )
        {
            break;
        }

        nStartIndex = nNextIndex + CStringTools::g_strLineEnd.size();
        
        nNextIndex = strInput.indexOf( CStringTools::g_strLineEnd, nStartIndex, cs );

    }
    oProgressDlg.setValue( nListSize );

    m_strInputData = strNewInput;

    ui->m_pTextEditInput->clear();
    ui->m_pTextEditOutput->clear();

    m_pEditLinesManager->SetSourceLines( m_strInputData );

    if( ui->m_pTextEditInput->isVisible() )
    {
        m_pEditLinesManager->ShowSourceTextEditContent();
    }

    if( ui->m_pTextEditOutput->isVisible() )
    {
        m_pEditLinesManager->ShowRemovedTextEditContent();
    }

    QString strLabel = QString("%1 lines remove").arg( setDuplicates.size() + nEmptyLinesCounter );
    ui->m_pLabelResult->setText( strLabel );
}

