#include "RemoveLinesContainingWidget.h"
#include "ui_RemoveLinesContainingWidget.h"
#include "MainWindow.h"
#include "StringTools.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QProgressDialog>
#include <assert.h>



CRemoveLinesContainingWidget::CRemoveLinesContainingWidget(CMainWindow* pMainWindow, QWidget *parent)
                             : QWidget(parent)
                             , ui(new Ui::CRemoveLinesContainingWidget)
                             , m_pMainWindow(pMainWindow)
                             , m_strSelFileName()
                             , m_pEditLinesManager(nullptr)
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    static const unsigned int uiExtraSearchCriteria = 10;
    for(unsigned int i = 0; i < uiExtraSearchCriteria; i++)
    {
        QLabel* pAndLabelAnd = new QLabel();
        pAndLabelAnd->setText( "AND" );
        pAndLabelAnd->setVisible(false);
        m_arAndLabels.push_back( pAndLabelAnd );

        QLineEdit* pAndLineEdit = new QLineEdit();
        m_arAndEditLines.push_back( pAndLineEdit );
        pAndLineEdit->setVisible(false);

        QLabel* pAndLabelOr = new QLabel();
        pAndLabelOr->setText( "OR" );
        pAndLabelOr->setVisible(false);
        m_arOrLabels.push_back( pAndLabelOr );

        QLineEdit* pOrLineEdit = new QLineEdit();
        m_arOrEditLines.push_back( pOrLineEdit );
        pOrLineEdit->setVisible(false);
    }

    CreateGUI();

    m_pEditLinesManager = new CEditLineManager( this, ui->m_pTextEditInput, ui->m_pTextEditRemoved );

    connect( ui->m_pBtnBrowse, SIGNAL ( released() ), this, SLOT( BrowseFiles() ) );
    connect( ui->m_pBtnLoadFile, SIGNAL ( released() ), this, SLOT( LoadFile() ) );
    connect( ui->m_pCheckBoxDisplayRemoved, SIGNAL ( released() ), this, SLOT( DisplayRemoved() ) );
    connect( ui->m_pCheckBoxDisplayOutput, SIGNAL ( released() ), this, SLOT( DisplayOutput() ) );
    connect( ui->m_pBtnSaveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
    connect( ui->m_pBtnSelAllOutputText, SIGNAL ( released() ), this, SLOT( SelectAllOutputText() ) );
    connect( ui->m_pBtnClearAllOutputText, SIGNAL ( released() ), this, SLOT( ClearAllOutputText() ) );
    connect( ui->m_pBtnRemoveLinesContaining, SIGNAL ( released() ), this, SLOT( RemoveLinesContaining() ) );
    connect( ui->m_pBtnNotContaining, SIGNAL ( released() ), this, SLOT( NotContaining() ) );
    connect( ui->m_pBtnAnd, SIGNAL ( released() ), this, SLOT( And() ) );
    connect( ui->m_pBtnOr, SIGNAL ( released() ), this, SLOT( Or() ) );
    connect( ui->m_pBtnReset, SIGNAL ( released() ), this, SLOT( Reset() ) );
}

CRemoveLinesContainingWidget::~CRemoveLinesContainingWidget()
{
    ReleaseEditLines();

    delete ui;

    delete m_pEditLinesManager;
}

void CRemoveLinesContainingWidget::CreateGUI()
{

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 30, 10, 30);
    pWidgetLayout->setAlignment(Qt::AlignTop);

    pWidgetLayout->addWidget(ui->m_pLabelSearchLinesFor);
    pWidgetLayout->addWidget(ui->m_pLineEditSearchLinesFor);
    ui->m_pBtnExtractColumns->setVisible(false);

    // add extra 'ADD' search lines
    assert( m_arAndEditLines.size() == m_arAndLabels.size() );
    QVector<QLineEdit*>::const_iterator itLineEdit = m_arAndEditLines.begin();
    QVector<QLabel*>::const_iterator itLabel = m_arAndLabels.begin();
    for( ; itLineEdit != m_arAndEditLines.end() && itLabel != m_arAndLabels.end(); itLineEdit++, itLabel++ )
    {
        pWidgetLayout->addWidget( *itLabel );
        pWidgetLayout->addWidget( *itLineEdit );
    }

    // add extra 'OR' search lines
    assert( m_arOrEditLines.size() == m_arOrLabels.size() );
    itLineEdit = m_arOrEditLines.begin();
    itLabel = m_arOrLabels.begin();
    for( ; itLineEdit != m_arOrEditLines.end() && itLabel != m_arOrLabels.end(); itLineEdit++, itLabel++ )
    {
        pWidgetLayout->addWidget( *itLabel );
        pWidgetLayout->addWidget( *itLineEdit );
    }


#if 0
    QHBoxLayout* pElementsLayout0 = new QHBoxLayout();
    pElementsLayout0->addWidget(ui->m_pLineEditSearchLinesFor);
    pElementsLayout0->addWidget(ui->m_pBtnExtractColumns);
    pElementsLayout0->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout0);
#endif

    pWidgetLayout->addSpacing(30);

    QHBoxLayout* pElementsLayout1 = new QHBoxLayout();
    pElementsLayout1->addWidget(ui->m_pLabelAdd);
    pElementsLayout1->addWidget(ui->m_pBtnAnd);
    pElementsLayout1->addWidget(ui->m_pBtnOr);
    pElementsLayout1->addWidget(ui->m_pLabelSearchField);
    pElementsLayout1->addWidget(ui->m_pBtnReset);
    pElementsLayout1->addWidget(ui->m_pCheckBoxEnableRegExp);
    pElementsLayout1->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout1);

    pWidgetLayout->addSpacing(30);

    QHBoxLayout* pElementsLayout2 = new QHBoxLayout();
    pElementsLayout2->addWidget(ui->m_pBtnRemoveLinesContaining);
    pElementsLayout2->addWidget(ui->m_pBtnNotContaining);
    pElementsLayout2->addWidget(ui->m_pCheckBoxCaseSensitive);
    pElementsLayout2->addWidget(ui->m_pCheckBoxDisplayRemoved);
    pElementsLayout2->addWidget(ui->m_pCheckBoxDisplayOutput);
    pElementsLayout2->addWidget(ui->m_pBtnSelAllOutputText);
    pElementsLayout2->addWidget(ui->m_pBtnClearAllOutputText);
    ui->m_pBtnSelAllOutputText->setVisible(false);
    ui->m_pBtnClearAllOutputText->setVisible(false);
    pElementsLayout2->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout2);

    pWidgetLayout->addSpacing(30);

    pWidgetLayout->addWidget(ui->m_pTextEditInput);
    ui->m_pTextEditInput->setVisible(false);

    pWidgetLayout->addSpacing(30);

    pWidgetLayout->addWidget(ui->m_pTextEditRemoved);
    ui->m_pTextEditRemoved->setVisible(false);

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
}

void CRemoveLinesContainingWidget::ReleaseEditLines()
{
    // AND edit lines & labels
    foreach( QLineEdit* pEditLine, m_arAndEditLines )
    {
        delete pEditLine;
    }
    m_arAndEditLines.clear();

    foreach( QLabel* pLabel, m_arAndLabels )
    {
        delete pLabel;
    }
    m_arAndLabels.clear();

    // OR edit lines & labels
    foreach( QLineEdit* pEditLine, m_arOrEditLines )
    {
        delete pEditLine;
    }
    m_arOrEditLines.clear();

    foreach( QLabel* pLabel, m_arOrLabels )
    {
        delete pLabel;
    }
    m_arOrLabels.clear();
}

void CRemoveLinesContainingWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

bool CRemoveLinesContainingWidget::LoadFileFromDisc()
{
    QFile oFile(m_strSelFileName);

    m_strInputData.clear();
    ui->m_pTextEditInput->clear();
    ui->m_pTextEditRemoved->clear();

    m_pEditLinesManager->ClearSourceLines();
    m_pEditLinesManager->ClearRemovedLines();

    if( oFile.exists() )
    {
        if( oFile.open(QIODevice::ReadOnly | QIODevice::Text) == false )
            return false;

        QByteArray arData = oFile.readAll();
        int nDataSize = arData.size();
        if( nDataSize == 0 )
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

void CRemoveLinesContainingWidget::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CRemoveLinesContainingWidget::BrowseFiles()
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

void CRemoveLinesContainingWidget::SaveAs()
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

void CRemoveLinesContainingWidget::DisplayRemoved()
{
    bool bChecked = ui->m_pCheckBoxDisplayRemoved->isChecked();
    bool bVisible = ui->m_pTextEditInput->isVisible();

    ui->m_pTextEditRemoved->setVisible(bChecked);
    ui->m_pBtnSelAllOutputText->setVisible( bChecked || bVisible );
    ui->m_pBtnClearAllOutputText->setVisible( bChecked || bVisible );

    if( bChecked == true )
    {
        m_pEditLinesManager->ShowRemovedTextEditContent();
    }
}

void CRemoveLinesContainingWidget::DisplayOutput()
{
    bool bChecked = ui->m_pCheckBoxDisplayOutput->isChecked();
    bool bVisible = ui->m_pTextEditRemoved->isVisible();

    ui->m_pTextEditInput->setVisible(bChecked);
    ui->m_pBtnSelAllOutputText->setVisible( bChecked || bVisible );
    ui->m_pBtnClearAllOutputText->setVisible( bChecked || bVisible );

    if( bChecked == true )
    {
        m_pEditLinesManager->ShowSourceTextEditContent();
    }
}

void CRemoveLinesContainingWidget::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditInput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditInput->setFocus();
        ui->m_pTextEditInput->selectAll();
    }
}

void CRemoveLinesContainingWidget::ClearAllOutputText()
{
    ui->m_pTextEditInput->clear();
    ui->m_pTextEditRemoved->clear();
    m_strInputData.clear();

    m_pEditLinesManager->ClearSourceLines();
    m_pEditLinesManager->ClearRemovedLines();
}

void CRemoveLinesContainingWidget::RemoveLinesContaining()
{
    m_pEditLinesManager->ClearRemovedLines();

    QString strSearchFor = ui->m_pLineEditSearchLinesFor->text();
    if( strSearchFor.isEmpty() == true )
    {
        return;
    }

    bool bCaseSensitive = ui->m_pCheckBoxCaseSensitive->isChecked();
    Qt::CaseSensitivity cs = bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive;

    QString strInput = m_strInputData;

    QString strNewInput, strRemovedOutput;

    QStringList listToRemove;
    listToRemove.append( strSearchFor );

    bool bAnd = true;

    // also get criteria from optional 'AND' fileds, fi any
    foreach( QLineEdit* pEditLine, m_arAndEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == true )
        {
            QString strCriteria = pEditLine->text();
            if( strCriteria.isEmpty() == false )
            {
                listToRemove.append( strCriteria );
            }
        }
    }

    // also get criteria from optional 'OR' fileds, fi any
    foreach( QLineEdit* pEditLine, m_arOrEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == true )
        {
            QString strCriteria = pEditLine->text();
            if( strCriteria.isEmpty() == false )
            {
                listToRemove.append( strCriteria );
                bAnd = false;
            }
        }
    }

    RemoveStrings( strInput, listToRemove, cs, true, bAnd, strNewInput, strRemovedOutput );

    m_strInputData = strNewInput;

    ui->m_pTextEditInput->clear();
    ui->m_pTextEditRemoved->clear();

    m_pEditLinesManager->SetSourceLines( m_strInputData );

    if( ui->m_pTextEditInput->isVisible() )
    {
        m_pEditLinesManager->ShowSourceTextEditContent();
    }

    if( ui->m_pTextEditRemoved->isVisible() )
    {
        m_pEditLinesManager->ShowRemovedTextEditContent();
    }
}

void CRemoveLinesContainingWidget::NotContaining()
{
    m_pEditLinesManager->ClearRemovedLines();

    QString strSearchFor = ui->m_pLineEditSearchLinesFor->text();
    if( strSearchFor.isEmpty() == true )
    {
        return;
    }

    bool bCaseSensitive = ui->m_pCheckBoxCaseSensitive->isChecked();
    Qt::CaseSensitivity cs = bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive;

    QString strInput = m_strInputData;

    QString strNewInput, strRemovedOutput;

    QStringList listToRemove;
    listToRemove.append( strSearchFor );

    bool bAnd = true;

    // also get criteria from optional 'AND' fileds, fi any
    foreach( QLineEdit* pEditLine, m_arAndEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == true )
        {
            QString strCriteria = pEditLine->text();
            if( strCriteria.isEmpty() == false )
            {
                listToRemove.append( strCriteria );
            }
        }
    }

    // also get criteria from optional 'OR' fileds, fi any
    foreach( QLineEdit* pEditLine, m_arOrEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == true )
        {
            QString strCriteria = pEditLine->text();
            if( strCriteria.isEmpty() == false )
            {
                listToRemove.append( strCriteria );
                bAnd = false;
            }
        }
    }

    RemoveStrings( strInput, listToRemove, cs, false, bAnd, strNewInput, strRemovedOutput );

    m_strInputData = strNewInput;

    ui->m_pTextEditInput->clear();
    ui->m_pTextEditRemoved->clear();

    m_pEditLinesManager->SetSourceLines( m_strInputData );

    if( ui->m_pTextEditInput->isVisible() )
    {
        m_pEditLinesManager->ShowSourceTextEditContent();
    }

    if( ui->m_pTextEditRemoved->isVisible() )
    {
        m_pEditLinesManager->ShowRemovedTextEditContent();
    }
}

void CRemoveLinesContainingWidget::And()
{
    // AND edit lines & labels
    foreach( QLineEdit* pEditLine, m_arAndEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == false )
        {
            pEditLine->setVisible(true);
            break;
        }
    }

    foreach( QLabel* pLabel, m_arAndLabels )
    {
        if( pLabel != nullptr && pLabel->isVisible() == false )
        {
            pLabel->setVisible(true);
            break;
        }
    }

    ui->m_pBtnOr->setVisible(false);

    QLayout* pLayout = layout();
    if( pLayout != nullptr )
    {
        pLayout->update();
    }
}

void CRemoveLinesContainingWidget::Or()
{
    // OR edit lines & labels
    foreach( QLineEdit* pEditLine, m_arOrEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == false )
        {
            pEditLine->setVisible(true);
            break;
        }
    }

    foreach( QLabel* pLabel, m_arOrLabels )
    {
        if( pLabel != nullptr && pLabel->isVisible() == false )
        {
            pLabel->setVisible(true);
            break;
        }
    }

    ui->m_pBtnAnd->setVisible(false);

    QLayout* pLayout = layout();
    if( pLayout != nullptr )
    {
        pLayout->update();
    }
}

void CRemoveLinesContainingWidget::Reset()
{
    ui->m_pLineEditSearchLinesFor->clear();

    // AND
    foreach( QLineEdit* pEditLine, m_arAndEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == true )
        {
            pEditLine->setVisible(false);
        }
    }

    foreach( QLabel* pLabel, m_arAndLabels )
    {
        if( pLabel != nullptr && pLabel->isVisible() == true )
        {
            pLabel->setVisible(false);
        }
    }

    // OR
    foreach( QLineEdit* pEditLine, m_arOrEditLines )
    {
        if( pEditLine != nullptr && pEditLine->isVisible() == true )
        {
            pEditLine->setVisible(false);
        }
    }

    foreach( QLabel* pLabel, m_arOrLabels )
    {
        if( pLabel != nullptr && pLabel->isVisible() == true )
        {
            pLabel->setVisible(false);
        }
    }

    ui->m_pBtnAnd->setVisible(true);
    ui->m_pBtnOr->setVisible(true);

    QLayout* pLayout = layout();
    if( pLayout != nullptr )
    {
        pLayout->update();
    }
}

void CRemoveLinesContainingWidget::RemoveStrings( const QString& strInputData, const QStringList& listStringsToRemove,
                                                  Qt::CaseSensitivity cs, bool bRemoveContaining, bool bAndOperation,
                                                  QString& strOutputData, QString& strRemovedData )
{
    const QStringList& listSourceLines = m_pEditLinesManager->GetSourceLinesList();

    int nListSize = listSourceLines.size();
    QProgressDialog oProgressDlg( "Remove lines containing", "Abort", 0, nListSize, this, Qt::CustomizeWindowHint );
    oProgressDlg.setWindowModality( Qt::WindowModal );

    int nProgressIndex = 0;
    foreach( QString strLine, listSourceLines )
    {
        oProgressDlg.setValue( nProgressIndex++ );
        if( oProgressDlg.wasCanceled() )
            break;

        // figure out if this line contains the text to be removed
        bool bHasStrings = Contains( strLine, listStringsToRemove, cs, bAndOperation );

        if( bHasStrings )
        {
            if( bRemoveContaining == false )
            {
                if ( strOutputData.isEmpty() == false )
                {
                    strOutputData += CStringTools::g_strLineEnd;
                }
                strOutputData += strLine;
            }
            else
            {
                m_pEditLinesManager->AddRemovedLine( strLine );
            }
        }
        else
        {
            if( bRemoveContaining == false )
            {
                m_pEditLinesManager->AddRemovedLine( strLine );
            }
            else
            {
                if ( strOutputData.isEmpty() == false )
                {
                    strOutputData += CStringTools::g_strLineEnd;
                }
                strOutputData += strLine;
            }
        }
    }

    oProgressDlg.setValue( nListSize );
}

bool CRemoveLinesContainingWidget::Contains( const QString& strLine, const QStringList& listStringsToRemove,
                                             Qt::CaseSensitivity cs, bool bAnd )const
{
    bool bContains = bAnd ? true : false;
    foreach(QString strFilter, listStringsToRemove)
    {
        if( bAnd == true )
        {
            if( strLine.contains(strFilter, cs) == false )
            {
                return false;
            }
        }
        else
        {
            if( strLine.contains(strFilter, cs) == true )
            {
                bContains = true;
                break;
            }
        }
    }
    return bContains;
}
