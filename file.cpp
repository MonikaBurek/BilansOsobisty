#include <iostream>
#include "file.h"
#include "Markup.h"

using namespace std;

bool File::isFileEmpty(string fileName)
{
    int length;

    file.open(fileName.c_str());
    file.seekg(0, ios::end); // Go to the end of the file.

    length = file.tellg();  // We check the position that corresponds to the length of the file.

    file.close();

    if (length == 0)
        return 0;// The file is empty.
    else
        return 1; // The file contains data.
}


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

