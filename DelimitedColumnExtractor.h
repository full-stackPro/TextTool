#ifndef DELIMITEDCOLUMNEXTRACTOR_H
#define DELIMITEDCOLUMNEXTRACTOR_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;



namespace Ui {
class CDelimitedColumnExtractor;
}

class CDelimitedColumnExtractor : public QWidget
{
    Q_OBJECT

public:
    explicit CDelimitedColumnExtractor(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CDelimitedColumnExtractor();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool LoadFileFromDisc();


private slots:
    void LoadFile();
    void BrowseFiles();
    void SaveAs();
    void ExtractColumn();
    void SelectAllOutputText();
    void ClearAllOutputText();

private:
    Ui::CDelimitedColumnExtractor*  ui;
    CMainWindow*                    m_pMainWindow;
    QString                         m_strSelFileName;
    QByteArray                      m_arData;
};

#endif // DELIMITEDCOLUMNEXTRACTOR_H
