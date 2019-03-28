#include "FindReplaceWidget.h"
#include "ui_FindReplaceWidget.h"
#include "MainWindow.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QButtonGroup>



CFindReplaceWidget::CFindReplaceWidget(CMainWindow* pMainWindow, QWidget *parent)
                   : QWidget(parent)
                   , m_pMainWindow(pMainWindow)
                   , ui(new Ui::CFindReplaceWidget)
                   , m_strSelFileName()
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 15, 10, 30);

    QHBoxLayout* pElementsLayout0 = new QHBoxLayout();
    pElementsLayout0->addWidget(ui->m_pFindThisLabel);
    pElementsLayout0->addWidget(ui->m_pCheckBoxRegularExp);
    pElementsLayout0->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout0);

    pWidgetLayout->addWidget(ui->m_pTextEditLookFor);
    pWidgetLayout->addWidget(ui->m_pLabelReplaceWith);
    pWidgetLayout->addWidget(ui->m_pTextEditReplaceWith);

    QHBoxLayout* pElementsLayout1 = new QHBoxLayout();
    pElementsLayout1->addWidget(ui->m_pBtnFindReplaceText);
    pElementsLayout1->addWidget(ui->m_pCheckBoxGlobalMatching);
    ui->m_pCheckBoxGlobalMatching->setChecked(true);
    pElementsLayout1->addWidget(ui->m_pCheckBoxCaseSensitive);
    pElementsLayout1->addWidget(ui->m_pBtnSelAllOutputText);
    pElementsLayout1->addWidget(ui->m_pBtnClearAllOutputText);
    pElementsLayout1->addWidget(ui->m_pLabelResult);
    pElementsLayout1->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout1);

    pWidgetLayout->addWidget(ui->m_pTextEditInputOutput);

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
    pElementsLayout4->addWidget(ui->m_pLabelWrapIs);
    pElementsLayout4->addWidget(ui->m_pRadioBtnWrapOn);
    pElementsLayout4->addWidget(ui->m_pRadioBtnWrapOff);
    ui->m_pRadioBtnWrapOff->setChecked(true);
    pElementsLayout4->setAlignment(Qt::AlignLeft);
    pWidgetLayout->addLayout(pElementsLayout4);

    connect( ui->m_pBtnBrowse, SIGNAL ( released() ), this, SLOT( BrowseFiles() ) );
    connect( ui->m_pBtnFindReplaceText, SIGNAL ( released() ), this, SLOT( FindAndReplace() ) );
    connect( ui->m_pBtnSaveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
    connect( ui->m_pBtnSelAllOutputText, SIGNAL ( released() ), this, SLOT( SelectAllOutputText() ) );
    connect( ui->m_pBtnClearAllOutputText, SIGNAL ( released() ), this, SLOT( ClearAllOutputText() ) );
}

CFindReplaceWidget::~CFindReplaceWidget()
{
    delete ui;
}

void CFindReplaceWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

void CFindReplaceWidget::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CFindReplaceWidget::BrowseFiles()
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

void CFindReplaceWidget::FindAndReplace()
{
    QString strToFind = ui->m_pTextEditLookFor->toPlainText();
    QString strReplaceWith = ui->m_pTextEditReplaceWith->toPlainText();

    QString strResultText;
    QString strText = ui->m_pTextEditInputOutput->toPlainText();
    if(strText.isEmpty() == true)
    {
        return;
    }

    bool bGlobalMatching = ui->m_pCheckBoxGlobalMatching->isChecked();
    bool bCaseSensitive = ui->m_pCheckBoxCaseSensitive->isChecked();

    int nCount = strText.count( strToFind, bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive );

    if( strReplaceWith.isEmpty() == false && strToFind.isEmpty() == false )
    {
        strResultText = strText.replace( strToFind, strReplaceWith, bCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive );
        ui->m_pTextEditInputOutput->setText(strResultText);
    }

    if(nCount > 0)
    {
        QString strResult( QString::number(nCount) );
        strResult += " found and replaces";

        ui->m_pLabelResult->setText(strResult);
    }
    else
    {
        ui->m_pLabelResult->clear();
    }
}

void CFindReplaceWidget::SaveAs()
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
        QString strText = ui->m_pTextEditInputOutput->toPlainText();


        oOutFile.write(strText.toStdString().c_str(), strText.size() );

        oOutFile.close();
    }
}

void CFindReplaceWidget::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditInputOutput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditInputOutput->setFocus();
        ui->m_pTextEditInputOutput->selectAll();
    }
}

void CFindReplaceWidget::ClearAllOutputText()
{
    ui->m_pTextEditInputOutput->clear();
}

bool CFindReplaceWidget::LoadFileFromDisc()
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
        ui->m_pTextEditInputOutput->setText(strTest);

        oFile.close();

        return true;
    }

    return false;
}

