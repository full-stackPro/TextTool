#ifndef CEDITLINEMANAGER_H
#define CEDITLINEMANAGER_H


#include <QString>
#include <QStringList>
#include <QVector>


// forward declarations
class QWidget;
class QTextEdit;


class CEditLineManager
{
public:
    CEditLineManager( QWidget* pParent, QTextEdit* pSourceTextEdit, QTextEdit* pRemovedTextEdit );
    ~CEditLineManager();

    // setters
    void SetSourceLines( const QStringList& listSourceLines ) { m_listSourceLines = listSourceLines; }
    void SetRemovedLines( const QStringList& listRemovedLines ) { m_listRemovedLines = listRemovedLines; }
    void SetMaxVisibleLines( unsigned int uiMaxVisibleLines ) { m_uiMaxVisibleLines = uiMaxVisibleLines; }
    void ClearSourceLines(){ m_listSourceLines.clear(); }
    void ClearRemovedLines(){ m_listRemovedLines.clear(); }
    inline void AddRemovedLine( const QString& strLine ){ m_listRemovedLines.append(strLine); }

    // getters
    inline const QStringList& GetSourceLinesList()const {return m_listSourceLines;}
    inline const QStringList& GetRemovedLinesList()const {return m_listRemovedLines;}

    void SetSourceLines(const QString& strSourceData );
    void SetRemovedLines(const QString& strRemovedData );
    void ShowSourceTextEditContent();
    void ShowRemovedTextEditContent();

    // data section
private:
    QWidget*        m_pParentWidget;
    QTextEdit*      m_pSourceTextEdit;
    QTextEdit*      m_pRemovedTextEdit;

    QStringList     m_listSourceLines;
    QStringList     m_listRemovedLines;

    unsigned int    m_uiMaxVisibleLines;
};

#endif // CEDITLINEMANAGER_H
