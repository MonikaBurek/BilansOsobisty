#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "income.h"
#include "file.h"
#include "date.h"
#include "dateoperations.h"

using namespace std;

/*
The class responsible for operations on the file incomes.xml
*/

class IncomesFile :public File
{
    fstream file;


public:
    IncomesFile();
    virtual ~IncomesFile();

    void addIncomesToFile(Income newIncome);
    int loadAllUserIncomes(vector <Income> &incomes,int loggedInUserId);

};

#endif // INCOMESFILE_H
