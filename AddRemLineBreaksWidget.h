#ifndef ADDREMLINEBREAKSWIDGET_H
#define ADDREMLINEBREAKSWIDGET_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;


namespace Ui {
class CAddRemLineBreaksWidget;
}

class CAddRemLineBreaksWidget : public QWidget
{
    Q_OBJECT

public:
    CAddRemLineBreaksWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CAddRemLineBreaksWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void LoadFile();
    void BrowseFiles();
    void RemoveAllLineBreaks();
    void SaveAs();
    void SelectAllOutputText();
    void ClearAllOutputText();
    void LoadOutputIntoInput();
    void MakeNewLineBreaks();
    void MakeNewLineBreaksEvery();

private:
    bool LoadFileFromDisc();

private:
    Ui::CAddRemLineBreaksWidget*    ui;
    CMainWindow*                    m_pMainWindow;
    QString                         m_strSelFileName;
    QByteArray                      m_arData;
};

#endif // ADDREMLINEBREAKSWIDGET_H
