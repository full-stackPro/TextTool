#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const QIcon oAppIcon = QIcon::fromTheme( "document-save", QIcon( ":/images/align-center.png" ) );
    a.setWindowIcon( oAppIcon );


    CMainWindow w;
    w.show();

    return a.exec();
}
