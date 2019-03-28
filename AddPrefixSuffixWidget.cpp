#include "AddPrefixSuffixWidget.h"
#include "ui_AddPrefixSuffixWidget.h"
#include "MainWindow.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>



CAddPrefixSuffixWidget::CAddPrefixSuffixWidget(CMainWindow* pMainWindow, QWidget *parent)
                       : QWidget(parent)
                       , ui(new Ui::CAddPrefixSuffixWidget)
                       , m_pMainWindow(pMainWindow)
                       , m_strSelFileName()
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 15, 10, 30);
    pWidgetLayout->addWidget(ui->m_oTextEditInput);
    pWidgetLayout->addWidget(ui->m_oLabelPrefix);
    pWidgetLayout->addWidget(ui->m_oLineEditPrefix);
    pWidgetLayout->addWidget(ui->m_oLabelSuffix);
    pWidgetLayout->addWidget(ui->m_oLineEditSuffix);

    QHBoxLayout* pElementsLayout = new QHBoxLayout();
    pElementsLayout->addWidget(ui->m_oBtnAddPrefixSuffix);
    pElementsLayout->addWidget(ui->m_oBtnSellectAll);
    pElementsLayout->addWidget(ui->m_oBtnClearAll);
    pElementsLayout->setAlignment(Qt::AlignLeft);

    pWidgetLayout->addLayout(pElementsLayout);

    pWidgetLayout->addWidget(ui->m_oTextEditOutput);

    QHBoxLayout* pDownLeftLayout = new QHBoxLayout();
    pDownLeftLayout->addWidget(ui->m_oBtnLoadFile);
    pDownLeftLayout->addWidget(ui->m_oBtnBrowse);
    pDownLeftLayout->addWidget(ui->m_oLabelSelectedFile);
    ui->m_oLabelSelectedFile->setText("No file selected.");

    pDownLeftLayout->addSpacing(50);
    pDownLeftLayout->addWidget(ui->m_oBtnAsveAs );
    pDownLeftLayout->addWidget(ui->m_oLineEditSaveAs );
    ui->m_oLineEditSaveAs->setText("output.txt");
    ui->m_oRadioBtnUnix->setChecked(true);
    pDownLeftLayout->addWidget(ui->m_oRadioBtnUnix);
    pDownLeftLayout->addWidget(ui->m_oRadioBtnDos);
    pDownLeftLayout->setAlignment(Qt::AlignLeft);

    pWidgetLayout->addLayout(pDownLeftLayout);

    connect( ui->m_oBtnBrowse, SIGNAL ( released() ), this, SLOT( BrowseFiles() ) );
    connect( ui->m_oBtnClearAll, SIGNAL ( released() ), this, SLOT( ClearAll() ) );
    connect( ui->m_oBtnSellectAll, SIGNAL ( released() ), this, SLOT( SelectAll() ) );
    connect( ui->m_oBtnAddPrefixSuffix, SIGNAL ( released() ), this, SLOT( AddPrefixSuffix() ) );
    connect( ui->m_oBtnAsveAs, SIGNAL ( released() ), this, SLOT( SaveAs() ) );
}

CAddPrefixSuffixWidget::~CAddPrefixSuffixWidget()
{
    delete ui;
}

void CAddPrefixSuffixWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

void CAddPrefixSuffixWidget::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CAddPrefixSuffixWidget::BrowseFiles()
{
    QString strFileName = QFileDialog::getOpenFileName( this, tr( "File Upload" ), QString(),
                                                                      tr( "All files (*.*)" ) );
    if(strFileName.isEmpty() == false)
    {
        m_strSelFileName = strFileName;
        if( LoadFileFromDisc() == true )
        {
            ui->m_oLabelSelectedFile->setText(strFileName);
        }
        else
        {
            m_strSelFileName.clear();
            ui->m_oLabelSelectedFile->setText("No file selected.");
            m_arData.clear();
        }
    }
    else if(m_strSelFileName.isEmpty())
    {
        ui->m_oLabelSelectedFile->setText("No file selected.");
        m_arData.clear();
    }
}

bool CAddPrefixSuffixWidget::LoadFileFromDisc()
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
        ui->m_oTextEditInput->setText(strTest);

        oFile.close();

        return true;
    }

    return false;
}

void CAddPrefixSuffixWidget::ClearAll()
{
    m_strSelFileName.clear();
    ui->m_oLabelSelectedFile->setText("No file selected.");
    m_arData.clear();
    ui->m_oTextEditInput->clear();
    ui->m_oTextEditOutput->clear();
    ui->m_oLineEditPrefix->clear();
    ui->m_oLineEditSuffix->clear();
}

void CAddPrefixSuffixWidget::SelectAll()
{
    QString strText = ui->m_oTextEditOutput->toPlainText();
    if(strText.isEmpty() == false)
    {
        ui->m_oTextEditOutput->setFocus();
        ui->m_oTextEditOutput->selectAll();
    }
}

void CAddPrefixSuffixWidget::AddPrefixSuffix()
{
    static const QString strLineEnd("\n");


    // get the prefix
    QString strPrefix = ui->m_oLineEditPrefix->text();

    // get the suffix
    QString strSuffix = ui->m_oLineEditSuffix->text();

    if(strPrefix.isEmpty() && strSuffix.isEmpty())
    {
        // both prefix and suffix empty

        if(ui->m_oTextEditOutput->toPlainText().isEmpty())
        {
            ui->m_oTextEditOutput->setText( ui->m_oTextEditInput->toPlainText() );
        }
        return;
    }

    QString strText = ui->m_oTextEditInput->toPlainText();

    QString strToReplace(strSuffix + strLineEnd+strPrefix);
    QString strResult = strText.replace(strLineEnd, strToReplace);
    strResult.insert(0, strPrefix);
    strResult.append(strSuffix);

    ui->m_oTextEditOutput->clear();
    ui->m_oTextEditOutput->setText(strResult);

}

void CAddPrefixSuffixWidget::SaveAs()
{
    QString strSaveName = ui->m_oLineEditSaveAs->text();

    QString strOutFileName = QFileDialog::getSaveFileName( this, tr( "Save as" ), strSaveName,
                                                                      tr( "All files (*.*)" ) );
    if(strOutFileName.isEmpty())
    {
        return;
    }

    QFile oOutFile(strOutFileName);
    if(oOutFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QString strText = ui->m_oTextEditOutput->toPlainText();


        oOutFile.write(strText.toStdString().c_str(), strText.size() );

        oOutFile.close();
    }
}

