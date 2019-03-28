#ifndef FINDREPLACEWIDGET_H
#define FINDREPLACEWIDGET_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;



namespace Ui {
class CFindReplaceWidget;
}

class CFindReplaceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CFindReplaceWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CFindReplaceWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool LoadFileFromDisc();

private slots:
    void LoadFile();
    void BrowseFiles();
    void FindAndReplace();
    void SaveAs();
    void SelectAllOutputText();
    void ClearAllOutputText();

private:
    Ui::CFindReplaceWidget*         ui;
    CMainWindow*                    m_pMainWindow;
    QString                         m_strSelFileName;
    QByteArray                      m_arData;
};

#endif // FINDREPLACEWIDGET_H
