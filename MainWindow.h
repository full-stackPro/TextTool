#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AddPrefixSuffixWidget.h"
#include "AddRemLineBreaksWidget.h"
#include "FindReplaceWidget.h"
#include "DelimitedColumnExtractor.h"
#include "JoinMergeTextWidget.h"
#include "RemoveDuplicatedLinesWidget.h"
#include "RemoveEmptyLinesWidget.h"
#include "RemoveExtraSpacesWidget.h"
#include "RemoveLinesContainingWidget.h"
#include "SortTextLinesWidget.h"


namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void AddPrefixSuffixIntoLine();
    void AddRemoveLineBreaks();
    void FindAndReplaceText();
    void DelimitedColumnExtractor();
    void JoinMergeText();
    void RemoveDuplicateLines();
    void RemoveEmptyLines();
    void RemoveExtraSpaces();
    void RemoveLinesContaining();
    void SortTextLines();

private:
    void ReadSettings();
    void SaveSettings();

    // data section
private:
    Ui::CMainWindow *ui;
    CAddPrefixSuffixWidget*         m_pAddPrefixWidget;
    CAddRemLineBreaksWidget*        m_pAddLineBreaksWidget;
    CFindReplaceWidget*             m_pFindReplaceWidget;
    CDelimitedColumnExtractor*      m_pColumnExtractorWidget;
    CJoinMergeTextWidget*           m_pJoinMergeWidget;
    CRemoveDuplicatedLinesWidget*   m_pRemoveDuplicateLinesWidget;
    CRemoveEmptyLinesWidget*        m_pRemoveEmptyLinesWidget;
    CRemoveExtraSpacesWidget*       m_pRemoveExtraSpacesWidget;
    CRemoveLinesContainingWidget*   m_pRemoveLinesContainingWidget;
    CSortTextLinesWidget*           m_pSortTextLinesWidget;
};

#endif // MAINWINDOW_H
