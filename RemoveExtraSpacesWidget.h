#ifndef REMOVEEXTRASPACESWIDGET_H
#define REMOVEEXTRASPACESWIDGET_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;
class QTextEdit;



namespace Ui {
class CRemoveExtraSpacesWidget;
}

class CRemoveExtraSpacesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CRemoveExtraSpacesWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CRemoveExtraSpacesWidget();

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
    void Remove();

private:
    Ui::CRemoveExtraSpacesWidget*       ui;
    CMainWindow*                        m_pMainWindow;
    QString                             m_strSelFileName;
};

#endif // REMOVEEXTRASPACESWIDGET_H
