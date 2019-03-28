#include "AddRemLineBreaksWidget.h"
#include "ui_AddRemLineBreaksWidget.h"
#include "MainWindow.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QButtonGroup>


namespace
{
    static const QString g_strLineEnd("\n");
}

CAddRemLineBreaksWidget::CAddRemLineBreaksWidget(CMainWindow* pMainWindow, QWidget *parent)
                        : QWidget(parent)
                        , ui(new Ui::CAddRemLineBreaksWidget)
                        , m_pMainWindow(pMainWindow)
                        , m_strSelFileName()
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 15, 10, 30);

    pWidgetLayout->addWidget(ui->m_pTextEditInput);


    QHBoxLayout* pElementsLayout1 = new QHBoxLayout();
    pElementsLayout1->addWidget(ui->m_pBtnRemoveAllLineBreaks);
    pElementsLayout1->addWidget(ui->m_pLabelReplaceWithThisText);
    pElementsLayout1->addWidget(ui->m_pLineEditTextToreplace);
    pElementsLayout1->addWidget(ui->m_pLabelBlank);
    pElementsLayout1->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout1);

    QHBoxLayout* pElementsLayout2 = new QHBoxLayout();
    pElementsLayout2->addWidget(ui->m_pBtnMakeNewLineBreaks);
    QButtonGroup* pGroup1 = new QButtonGroup(this);
    pGroup1->addButton(ui->m_pRadioButnBefore);
    pGroup1->addButton(ui->m_pRadioButnAfter);
    pElementsLayout2->addWidget(ui->m_pRadioButnBefore);
    pElementsLayout2->addWidget(ui->m_pRadioButnAfter);
    ui->m_pRadioButnAfter->setChecked(true);
    ui->m_pRadioButnAfter->setCheckable(true);
    pElementsLayout2->addWidget(ui->m_pLineEditTexOccurence);
    pElementsLayout2->addWidget(ui->m_pCheckBoxCS);
    pElementsLayout2->addWidget(ui->m_pCheckBoxRELB);
    pElementsLayout2->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout2);

    QHBoxLayout* pElementsLayout3 = new QHBoxLayout();
    pElementsLayout3->addWidget(ui->m_pBtnMakeNewLineBreaksEvery);
    pElementsLayout3->addWidget(ui->m_pLabelEvery);
    pElementsLayout3->addWidget(ui->m_pLineEditTexEvery);
    pElementsLayout3->addWidget(ui->m_pLabelCharactes);
    pElementsLayout3->addWidget(ui->m_pCheckBoxWordWrap);
    pElementsLayout3->addWidget(ui->m_pCheckBoxEcapeExisting);
    pElementsLayout3->addWidget(ui->m_pBtnSelAllOutputText);
    pElementsLayout3->addWidget(ui->m_pBtnClearAllOutputText);
    pElementsLayout3->addWidget(ui->m_pBtnLoadOutputIntoInput);
    pElementsLayout3->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout3);

    pWidgetLayout->addWidget(ui->m_pTextEditOutput);

    QHBoxLayout* pElementsLayout4 = new QHBoxLayout();
    pElementsLayout4->addWidget(ui->m_pBtnLoadFile);
    pElementsLayout4->addWidget(ui->m_pBtnBrowse);
    pElementsLayout4->addWidget(ui->m_pLabelSelectedFile);
    ui->m_pLabelSelectedFile->setText("No file selected.");
    pElementsLayout4->addWidget(ui->m_pBtnAsveAs);
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

    connect( ui->m_pBtnBrowse, SIGNAL ( released() ), this, SLOT( BrowseFiles() ) );
    connect( ui->m_pBtnRemoveAllLineBreaks, SIGNAL ( released() ), this, SLOT( RemoveAllLineBreaks() ) );
    connect( ui->m_pBtnAsveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
    connect( ui->m_pBtnSelAllOutputText, SIGNAL( released() ), this, SLOT( SelectAllOutputText() ) );
    connect( ui->m_pBtnClearAllOutputText, SIGNAL( released() ), this, SLOT( ClearAllOutputText() ) );
    connect( ui->m_pBtnLoadOutputIntoInput, SIGNAL ( released() ), this, SLOT( LoadOutputIntoInput() ) );
    connect( ui->m_pBtnMakeNewLineBreaks, SIGNAL( released() ), this, SLOT( MakeNewLineBreaks() ) );
    connect( ui->m_pBtnMakeNewLineBreaksEvery, SIGNAL ( released() ), this, SLOT( MakeNewLineBreaksEvery() ) );
}

CAddRemLineBreaksWidget::~CAddRemLineBreaksWidget()
{
    delete ui;
}

void CAddRemLineBreaksWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

void CAddRemLineBreaksWidget::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CAddRemLineBreaksWidget::BrowseFiles()
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

void CAddRemLineBreaksWidget::RemoveAllLineBreaks()
{
    QString strToReplace = ui->m_pLineEditTextToreplace->text();
    QString strText = ui->m_pTextEditInput->toPlainText();

    QString strResult = strText.replace(g_strLineEnd, strToReplace);

    ui->m_pTextEditOutput->clear();
    ui->m_pTextEditOutput->setText(strResult);
}

void CAddRemLineBreaksWidget::SaveAs()
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

void CAddRemLineBreaksWidget::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditOutput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditOutput->setFocus();
        ui->m_pTextEditOutput->selectAll();
    }
}

void CAddRemLineBreaksWidget::ClearAllOutputText()
{
    ui->m_pTextEditOutput->clear();
}

void CAddRemLineBreaksWidget::LoadOutputIntoInput()
{
    QString strTextOutput = ui->m_pTextEditOutput->toPlainText();
    ui->m_pTextEditInput->setText(strTextOutput);
}

void CAddRemLineBreaksWidget::MakeNewLineBreaks()
{
    bool bBefore = ui->m_pRadioButnBefore->isChecked();
    QString strTextOccurence = ui->m_pLineEditTexOccurence->text();
    bool bRemoveNewLines = ui->m_pCheckBoxRELB->isChecked();
    bool bCaseSensitive = ui->m_pCheckBoxCS->isChecked();

    QString strText = ui->m_pTextEditInput->toPlainText();

    if(bRemoveNewLines == true)
    {
        // remove new lines

        strText = strText.remove(g_strLineEnd, bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive);
    }

    if (strTextOccurence.isEmpty() == false)
    {
        if ( bBefore == true )
        {
            QString strReplace( g_strLineEnd + strTextOccurence );
            strText = strText.replace( strTextOccurence, strReplace, bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive );
        }
        else
        {
            QString strReplace( strTextOccurence + g_strLineEnd );
            strText = strText.replace( strTextOccurence, strReplace, bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive );
        }
    }

    ui->m_pTextEditOutput->clear();
    ui->m_pTextEditOutput->setText(strText);
}

void CAddRemLineBreaksWidget::MakeNewLineBreaksEvery()
{
    QString strText = ui->m_pTextEditInput->toPlainText();

    QString strEveryChar = ui->m_pLineEditTexEvery->text();
    if ( strEveryChar.isEmpty() == true )
    {
        return;
    }
    int nStep = strEveryChar.toInt();
    int nCount = strText.size();

    // remove the initial line breaks
    strText.remove( g_strLineEnd );

    for ( int i = nStep, j = 0; i < nCount; i += nStep, j++ )
    {
        strText.insert(i + j, g_strLineEnd);
    }

    ui->m_pTextEditOutput->clear();
    ui->m_pTextEditOutput->setText(strText);
}

bool CAddRemLineBreaksWidget::LoadFileFromDisc()
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

