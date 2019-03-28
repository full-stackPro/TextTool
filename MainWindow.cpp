#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QSettings>
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QGridLayout>
#include <QPushButton>



CMainWindow::CMainWindow(QWidget *parent)
            : QMainWindow(parent),
              ui(new Ui::CMainWindow)
            , m_pAddPrefixWidget(nullptr)
            , m_pAddLineBreaksWidget(nullptr)
            , m_pFindReplaceWidget(nullptr)
            , m_pColumnExtractorWidget(nullptr)
            , m_pJoinMergeWidget(nullptr)
            , m_pRemoveDuplicateLinesWidget(nullptr)
            , m_pRemoveEmptyLinesWidget(nullptr)
            , m_pRemoveExtraSpacesWidget(nullptr)
            , m_pRemoveLinesContainingWidget(nullptr)
            , m_pSortTextLinesWidget(nullptr)
{
    ui->setupUi(this);

    QCoreApplication::setApplicationName( tr( "TextTool" ) );
    QCoreApplication::setOrganizationName( tr( "CreativeSoft" ) );

    ReadSettings();

    ui->mainToolBar->setVisible(false);

    QGridLayout* pGridLayout = new QGridLayout(ui->centralWidget);
    pGridLayout->setHorizontalSpacing(170);
    pGridLayout->addWidget(ui->m_oBtnAddPrefixSuffix, 0, 0);
    pGridLayout->addWidget(ui->m_oBtnAddRemoveLineBreaks, 0, 1);
    pGridLayout->addWidget(ui->m_oBtnDelimitedExtractor, 0, 2);

    pGridLayout->addWidget(ui->m_oBtnFindAndReplace, 1, 0);
    pGridLayout->addWidget(ui->m_oBtnJoinMerge, 1, 1);
    pGridLayout->addWidget(ui->m_oBtnRemoveDuplicateLines, 1, 2);

    pGridLayout->addWidget(ui->m_oBtnRemoveEmptyLines, 2, 0);
    pGridLayout->addWidget(ui->m_oBtnRemoveExtraSpaces, 2, 1);
    pGridLayout->addWidget(ui->m_oBtnRemoveLinesContaining, 2, 2);

    pGridLayout->addWidget(ui->m_oBtnSortTextLines, 3, 0);

    connect( ui->m_oBtnAddPrefixSuffix, SIGNAL ( released() ), this, SLOT( AddPrefixSuffixIntoLine() ) );
    connect( ui->m_oBtnAddRemoveLineBreaks, SIGNAL ( released() ), this, SLOT( AddRemoveLineBreaks() ) );
    connect( ui->m_oBtnFindAndReplace, SIGNAL ( released() ), this, SLOT( FindAndReplaceText() ) );
    connect( ui->m_oBtnDelimitedExtractor, SIGNAL ( released() ), this, SLOT( DelimitedColumnExtractor() ) );
    connect( ui->m_oBtnJoinMerge, SIGNAL ( released() ), this, SLOT( JoinMergeText() ) );
    connect( ui->m_oBtnRemoveDuplicateLines, SIGNAL ( released() ), this, SLOT( RemoveDuplicateLines() ) );
    connect( ui->m_oBtnRemoveEmptyLines, SIGNAL ( released() ), this, SLOT( RemoveEmptyLines() ) );
    connect( ui->m_oBtnRemoveExtraSpaces, SIGNAL ( released() ), this, SLOT( RemoveExtraSpaces() ) );
    connect( ui->m_oBtnRemoveLinesContaining, SIGNAL ( released() ), this, SLOT( RemoveLinesContaining() ) );
    connect( ui->m_oBtnSortTextLines, SIGNAL ( released() ), this, SLOT( SortTextLines() ) );
}

CMainWindow::~CMainWindow()
{
    delete ui;

    delete m_pAddPrefixWidget;
    m_pAddPrefixWidget = nullptr;

    delete m_pAddPrefixWidget;
    m_pAddPrefixWidget = nullptr;

    delete m_pFindReplaceWidget;
    m_pFindReplaceWidget = nullptr;

    delete m_pJoinMergeWidget;
    m_pJoinMergeWidget = nullptr;

    delete m_pRemoveDuplicateLinesWidget;
    m_pRemoveDuplicateLinesWidget = nullptr;

    delete m_pRemoveEmptyLinesWidget;
    m_pRemoveEmptyLinesWidget = nullptr;

    delete m_pRemoveExtraSpacesWidget;
    m_pRemoveExtraSpacesWidget = nullptr;

    delete m_pRemoveLinesContainingWidget;
    m_pRemoveLinesContainingWidget = nullptr;

    delete m_pSortTextLinesWidget;
    m_pSortTextLinesWidget = nullptr;
}

void CMainWindow::ReadSettings()
{
    QString strApplName = QCoreApplication::applicationName();
    QByteArray arrayFileNameLatin1 = strApplName.toLatin1();
    char* lpszAppName = arrayFileNameLatin1.data();

    QString strCompanyName = QCoreApplication::organizationName();
    arrayFileNameLatin1 = strCompanyName.toLatin1();
    const char* lpszCompanyName = arrayFileNameLatin1.data();

    QSettings oAppSettings( strApplName, strCompanyName );
    const QByteArray arrayGeometry = oAppSettings.value( "geometry", QByteArray() ).toByteArray();

    if( true )
    {
         const QRect rectDesktopGeometry = QApplication::desktop()->availableGeometry( this );
         resize( rectDesktopGeometry.width() - 10, rectDesktopGeometry.height() - 50 );
    }
    else
    {
        restoreGeometry( arrayGeometry );
    }

}

void CMainWindow::SaveSettings()
{
    QString strApplName = QCoreApplication::applicationName();
    QString strCompanyName = QCoreApplication::organizationName();

    QSettings oAppSettings( strApplName, strCompanyName );
    oAppSettings.setValue( "geometry", saveGeometry() );
}

void CMainWindow::closeEvent(QCloseEvent *event)
{
    SaveSettings();
    event->accept();
}

void CMainWindow::AddPrefixSuffixIntoLine()
{
    delete m_pAddPrefixWidget;

    m_pAddPrefixWidget = new CAddPrefixSuffixWidget(this, nullptr);
    this->close();
    m_pAddPrefixWidget->show();
}

void CMainWindow::AddRemoveLineBreaks()
{
    delete m_pAddLineBreaksWidget;

    m_pAddLineBreaksWidget = new CAddRemLineBreaksWidget(this, nullptr);
    this->close();
    m_pAddLineBreaksWidget->show();
}

void CMainWindow::FindAndReplaceText()
{
    delete m_pFindReplaceWidget;

    m_pFindReplaceWidget = new CFindReplaceWidget(this, nullptr);
    this->close();
    m_pFindReplaceWidget->show();
}

void CMainWindow::DelimitedColumnExtractor()
{
    delete m_pColumnExtractorWidget;

    m_pColumnExtractorWidget = new CDelimitedColumnExtractor(this, nullptr);
    this->close();
    m_pColumnExtractorWidget->show();
}

void CMainWindow::JoinMergeText()
{
    delete m_pJoinMergeWidget;

    m_pJoinMergeWidget = new CJoinMergeTextWidget(this, nullptr);
    this->close();
    m_pJoinMergeWidget->show();
}

void CMainWindow::RemoveDuplicateLines()
{
    delete m_pRemoveDuplicateLinesWidget;

    m_pRemoveDuplicateLinesWidget = new CRemoveDuplicatedLinesWidget(this, nullptr);
    this->close();
    m_pRemoveDuplicateLinesWidget->show();
}

void CMainWindow::RemoveEmptyLines()
{
    delete m_pRemoveEmptyLinesWidget;

    m_pRemoveEmptyLinesWidget = new CRemoveEmptyLinesWidget(this, nullptr);
    this->close();
    m_pRemoveEmptyLinesWidget->show();
}

void CMainWindow::RemoveExtraSpaces()
{
    delete m_pRemoveExtraSpacesWidget;

    m_pRemoveExtraSpacesWidget = new CRemoveExtraSpacesWidget(this, nullptr);
    this->close();
    m_pRemoveExtraSpacesWidget->show();
}

void CMainWindow::RemoveLinesContaining()
{
    delete m_pRemoveLinesContainingWidget;

    m_pRemoveLinesContainingWidget = new CRemoveLinesContainingWidget(this, nullptr);
    this->close();
    m_pRemoveLinesContainingWidget->show();
}

void CMainWindow::SortTextLines()
{
    delete m_pSortTextLinesWidget;

    m_pSortTextLinesWidget = new CSortTextLinesWidget(this, nullptr);
    this->close();
    m_pSortTextLinesWidget->show();
}

