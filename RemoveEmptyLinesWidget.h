#ifndef REMOVEEMPTYLINESWIDGET_H
#define REMOVEEMPTYLINESWIDGET_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;
class QTextEdit;



namespace Ui {
class CRemoveEmptyLinesWidget;
}

class CRemoveEmptyLinesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CRemoveEmptyLinesWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CRemoveEmptyLinesWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool LoadFileFromDisc();

private slots:
    void LoadFile();
    void BrowseFiles();
    void SaveAs();
    void SelectAllOutputText();
    void ClearAllOutputText();
    void RemoveEmptyLines();


private:
    Ui::CRemoveEmptyLinesWidget*        ui;
    CMainWindow*                        m_pMainWindow;
    QString                             m_strSelFileName;
};

#endif // REMOVEEMPTYLINESWIDGET_H
