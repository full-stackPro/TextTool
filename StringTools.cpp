#include "StringTools.h"



const QString CStringTools::g_strLineEnd("\n");


CStringTools::CStringTools()
{

}

/*static*/ void CStringTools::ExtractLines( const QString& strInputData, QStringList& listLines )
{
    int nStartIndex = 0;
    int nNextIndex = strInputData.indexOf( g_strLineEnd, nStartIndex );
    while( nStartIndex < strInputData.size() )
    {
        int nLineLength = nNextIndex != - 1 ? nNextIndex - nStartIndex : -1;
        QString strLine = strInputData.mid( nStartIndex, nLineLength );

        listLines.append( strLine );

        if( nNextIndex == -1 )
        {
            break;
        }
        nStartIndex = nNextIndex + g_strLineEnd.size();
        nNextIndex = strInputData.indexOf( g_strLineEnd, nStartIndex );
    }
}

