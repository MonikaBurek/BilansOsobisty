#include <iostream>
#include "file.h"
#include "Markup.h"

using namespace std;

bool File::isFileExists(string fileName)
{
    file.open(fileName.c_str(), ios::in );  /* wa¿ne, by nie tworzyæ pliku, jeœli nie istnieje, st¹d flaga nocreate */
    if ( file.is_open())
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}

bool File::isFirstItemInFile(string fileName, string objectName)
{
    CMarkup xml;
    xml.Load(fileName.c_str());

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    if (xml.FindElem(objectName))
    {
            return true;
    }
    return false;
}
