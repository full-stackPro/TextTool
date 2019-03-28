#ifndef JOINMERGETEXTWIDGET_H
#define JOINMERGETEXTWIDGET_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;
class QTextEdit;



namespace Ui {
class CJoinMergeTextWidget;
}

class CJoinMergeTextWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CJoinMergeTextWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CJoinMergeTextWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool LoadFileFromDisc( const QString& strFileName, QTextEdit* pTextEdit );

private slots:
    void LoadFile1();
    void BrowseFile1();
    void LoadFile2();
    void BrowseFile2();
    void MergeFiles();
    void ClearInputs();
    void SaveAs();

    void SelectAllOutputText();
    void ClearAllOutputText();

private:
    Ui::CJoinMergeTextWidget*       ui;
    CMainWindow*                    m_pMainWindow;
    QString                         m_strSelFileName1;
    QString                         m_strSelFileName2;
};

#endif // JOINMERGETEXTWIDGET_H
