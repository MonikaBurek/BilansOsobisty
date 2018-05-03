#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

using namespace std;

/*
The class contains functions if the file is empty.
*/

class File
{
    fstream file;

public:
    bool isFileEmpty(string fileName);
    bool isFileExists(string fileName);
};

#endif
