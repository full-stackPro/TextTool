#ifndef REMOVEDUPLICATEDLINESWIDGET_H
#define REMOVEDUPLICATEDLINESWIDGET_H

#include <QWidget>
#include <QString>
#include "EditLineManager.h"


// forward declarations
class CMainWindow;
class QTextEdit;



namespace Ui {
class CRemoveDuplicatedLinesWidget;
}

class CRemoveDuplicatedLinesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CRemoveDuplicatedLinesWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CRemoveDuplicatedLinesWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool LoadFileFromDisc();

private slots:
    void LoadFile();
    void BrowseFiles();
    void SaveAs();
    void DisplayRemoved();
    void DisplayOutput();
    void SelectAllOutputText();
    void ClearAllOutputText();
    void RemoveDuplicateLines();

private:
    Ui::CRemoveDuplicatedLinesWidget*   ui;
    CMainWindow*                        m_pMainWindow;
    QString                             m_strSelFileName;

    QString                             m_strInputData;
    CEditLineManager*                   m_pEditLinesManager;
};

#endif // REMOVEDUPLICATEDLINESWIDGET_H
