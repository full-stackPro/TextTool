#include "SortTextLinesWidget.h"
#include "ui_SortTextLinesWidget.h"
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


CSortTextLinesWidget::CSortTextLinesWidget(CMainWindow* pMainWindow, QWidget *parent)
                     : QWidget(parent)
                     , ui(new Ui::CSortTextLinesWidget)
                     , m_pMainWindow(pMainWindow)
                     , m_strSelFileName()
{
    ui->setupUi(this);

    QRect rectMainGeometry = m_pMainWindow->geometry();
    this->setGeometry(rectMainGeometry);

    QVBoxLayout* pWidgetLayout = new QVBoxLayout(this);
    pWidgetLayout->setContentsMargins(10, 15, 10, 30);
    pWidgetLayout->setAlignment(Qt::AlignTop);
}

CSortTextLinesWidget::~CSortTextLinesWidget()
{
    delete ui;
}

void CSortTextLinesWidget::closeEvent(QCloseEvent *event)
{
    event->accept();
    if(m_pMainWindow != nullptr)
    {
        m_pMainWindow->show();
    }
}

bool CSortTextLinesWidget::LoadFileFromDisc()
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

        oFile.close();

        return true;
    }

    return false;
}
