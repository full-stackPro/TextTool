#include "EditLineManager.h"
#include "StringTools.h"
#include <QWidget>
#include <QTextEdit>
#include <QProgressDialog>



CEditLineManager::CEditLineManager( QWidget* pParent, QTextEdit* pSourceTextEdit, QTextEdit* pRemovedTextEdit  )
                 :m_pParentWidget(pParent)
                 ,m_pSourceTextEdit(pSourceTextEdit)
                 ,m_pRemovedTextEdit(pRemovedTextEdit)
                 ,m_uiMaxVisibleLines( 10000 )
{

}

CEditLineManager::~CEditLineManager()
{
    m_pParentWidget = nullptr;
    m_pSourceTextEdit = nullptr;
    m_pRemovedTextEdit = nullptr;
}

void CEditLineManager::SetSourceLines(const QString& strSourceData )
{
    m_listSourceLines.clear();
    CStringTools::ExtractLines( strSourceData, m_listSourceLines );
}

void CEditLineManager::SetRemovedLines(const QString& strRemovedData )
{
    m_listRemovedLines.clear();
    CStringTools::ExtractLines( strRemovedData, m_listRemovedLines );
}

void CEditLineManager::ShowSourceTextEditContent()
{
    QProgressDialog oProgressDlg( "Update source view", "Abort", 0, m_uiMaxVisibleLines, m_pParentWidget, Qt::CustomizeWindowHint );
    oProgressDlg.setWindowModality( Qt::WindowModal );

    int nCounter = 0;
    foreach( QString strLine, m_listSourceLines )
    {
        oProgressDlg.setValue( nCounter++ );
        if( oProgressDlg.wasCanceled() )
            break;

        m_pSourceTextEdit->append( strLine );

        if( nCounter > m_uiMaxVisibleLines )
            break;
    }

    oProgressDlg.setValue( m_uiMaxVisibleLines );
}

void CEditLineManager::ShowRemovedTextEditContent()
{
    QProgressDialog oProgressDlg( "Update removed view", "Abort", 0, m_uiMaxVisibleLines, m_pParentWidget, Qt::CustomizeWindowHint );
    oProgressDlg.setWindowModality( Qt::WindowModal );

    int nCounter = 0;
    foreach( QString strLine, m_listRemovedLines )
    {
        oProgressDlg.setValue( nCounter++ );
        if( oProgressDlg.wasCanceled() )
            break;

        m_pRemovedTextEdit->append( strLine );

        if( nCounter > m_uiMaxVisibleLines )
            break;
    }

    oProgressDlg.setValue( m_uiMaxVisibleLines );
}

