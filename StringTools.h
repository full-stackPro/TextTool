#ifndef CSTRINGTOOLS_H
#define CSTRINGTOOLS_H


#include <QString>
#include <QStringList>



class CStringTools
{
protected:
    CStringTools();

public:
    static void ExtractLines(const QString& strInputData, QStringList& listLines );

public:
    static const QString g_strLineEnd;
};

#endif // CSTRINGTOOLS_H
