#ifndef REMOVELINESCONTAININGWIDGET_H
#define REMOVELINESCONTAININGWIDGET_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QVector>
#include "EditLineManager.h"


// forward declarations
class CMainWindow;
class QTextEdit;
class QLineEdit;
class QLabel;



namespace Ui {
class CRemoveLinesContainingWidget;
}

class CRemoveLinesContainingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CRemoveLinesContainingWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CRemoveLinesContainingWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void LoadFile();
    void BrowseFiles();
    void SaveAs();
    void DisplayRemoved();
    void DisplayOutput();
    void SelectAllOutputText();
    void ClearAllOutputText();
    void RemoveLinesContaining();
    void NotContaining();
    void And();
    void Or();
    void Reset();

private:
    void CreateGUI();
    void ReleaseEditLines();
    bool LoadFileFromDisc();
    void RemoveStrings( const QString& strInputData, const QStringList& listStringsToRemove,
                        Qt::CaseSensitivity cs, bool bContaining, bool bAndOperation,
                        QString& strOutputData, QString& strRemovedData );

    bool Contains( const QString& strLine, const QStringList& listStringsToRemove, Qt::CaseSensitivity cs, bool bAnd )const;


private:
    Ui::CRemoveLinesContainingWidget*   ui;
    CMainWindow*                        m_pMainWindow;
    QString                             m_strSelFileName;
    QVector<QLineEdit*>                 m_arAndEditLines;
    QVector<QLabel*>                    m_arAndLabels;
    QVector<QLineEdit*>                 m_arOrEditLines;
    QVector<QLabel*>                    m_arOrLabels;
    QString                             m_strInputData;

    CEditLineManager*                   m_pEditLinesManager;
};

#endif // REMOVELINESCONTAININGWIDGET_H
