#ifndef SORTTEXTLINESWIDGET_H
#define SORTTEXTLINESWIDGET_H

#include <QWidget>
#include <QString>


// forward declarations
class CMainWindow;
class QTextEdit;



namespace Ui {
class CSortTextLinesWidget;
}

class CSortTextLinesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CSortTextLinesWidget(CMainWindow* pMainWindow, QWidget *parent = 0);
    ~CSortTextLinesWidget();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    bool LoadFileFromDisc();


private:
    Ui::CSortTextLinesWidget*   ui;
    CMainWindow*                m_pMainWindow;
    QString                     m_strSelFileName;
};

#endif // SORTTEXTLINESWIDGET_H
