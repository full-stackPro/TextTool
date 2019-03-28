#ifndef ADDPREFIXSUFFIXWIDGET_H
#define ADDPREFIXSUFFIXWIDGET_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;


namespace Ui {
class CAddPrefixSuffixWidget;
}

class CAddPrefixSuffixWidget : public QWidget
{
    Q_OBJECT

public:
    CAddPrefixSuffixWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CAddPrefixSuffixWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void LoadFile();
    void BrowseFiles();
    void ClearAll();
    void SelectAll();
    void AddPrefixSuffix();
    void SaveAs();

private:
    bool LoadFileFromDisc();

private:
    Ui::CAddPrefixSuffixWidget*     ui;
    CMainWindow*                    m_pMainWindow;
    QString                         m_strSelFileName;
    QByteArray                      m_arData;
};

#endif // ADDPREFIXSUFFIXWIDGET_H
