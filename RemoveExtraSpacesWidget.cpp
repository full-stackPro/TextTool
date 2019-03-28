#include "RemoveExtraSpacesWidget.h"
#include "ui_RemoveExtraSpacesWidget.h"
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




CRemoveExtraSpacesWidget::CRemoveExtraSpacesWidget(CMainWindow* pMainWindow, QWidget *parent)
                         : QWidget(parent)
                         , ui(new Ui::CRemoveExtraSpacesWidget)
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
    pElementsLayout1->addWidget(ui->m_pBtnRemove);
    pElementsLayout1->addWidget(ui->m_pCheckBoxTrim);
    ui->m_pCheckBoxTrim->setChecked(true);
    QButtonGroup* pGroup1 = new QButtonGroup(this);
    pGroup1->addButton(ui->m_pRadioBtnRemoveExtra);
    pGroup1->addButton(ui->m_pRadioBtnRemoveAll);
    pElementsLayout1->addWidget(ui->m_pRadioBtnRemoveExtra);
    ui->m_pRadioBtnRemoveExtra->setChecked(true);
    pElementsLayout1->addWidget(ui->m_pRadioBtnRemoveAll);
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
    connect( ui->m_pBtnRemove, SIGNAL ( released() ), this, SLOT( Remove() ) );
}

CRemoveExtraSpacesWidget::~CRemoveExtraSpacesWidget()
{
    delete ui;
}

void CRemoveExtraSpacesWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

bool CRemoveExtraSpacesWidget::LoadFileFromDisc()
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

void CRemoveExtraSpacesWidget::LoadFile()
{
    if(m_strSelFileName.isEmpty() == false)
    {
        LoadFileFromDisc();
    }
}

void CRemoveExtraSpacesWidget::BrowseFiles()
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

void CRemoveExtraSpacesWidget::SaveAs()
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

void CRemoveExtraSpacesWidget::SelectAllOutputText()
{
    QString strText = ui->m_pTextEditInput->toPlainText();
    if ( strText.isEmpty() == false )
    {
        ui->m_pTextEditInput->setFocus();
        ui->m_pTextEditInput->selectAll();
    }
}

void CRemoveExtraSpacesWidget::ClearAllOutputText()
{
    ui->m_pTextEditInput->clear();
    ui->m_pLabelResult->clear();
}

void CRemoveExtraSpacesWidget::Remove()
{
    bool bTrim = ui->m_pCheckBoxTrim->isChecked();
    bool bRemoveExtraSpaces = ui->m_pRadioBtnRemoveExtra->isChecked();
    bool bRemoveAllSpaces = ui->m_pRadioBtnRemoveAll->isChecked();

    QString strInput = ui->m_pTextEditInput->toPlainText();

    if( bRemoveAllSpaces == true )
    {
        int nCount = strInput.count(" ");
        strInput.remove(" ");
        ui->m_pTextEditInput->setText( strInput );

        QString strLabel = QString("%1 spaces removed").arg( nCount );
        ui->m_pLabelResult->setText( strLabel );

        return;
    }

    int nCount = strInput.count("  ");
    //strInput.remove("  ");

    QString strTrimmed;
    if(bTrim == true)
    {
        strTrimmed = strInput.trimmed();
    }
    if(bRemoveExtraSpaces)
    {
        strTrimmed = strInput.simplified();
    }
    ui->m_pTextEditInput->setText( strTrimmed );
    QString strLabel = QString("%1 spaces removed").arg( nCount );
    ui->m_pLabelResult->setText( strLabel );
}

