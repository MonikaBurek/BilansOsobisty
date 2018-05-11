#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "expense.h"
#include "file.h"
#include "date.h"
#include "dateoperations.h"

using namespace std;

/*
The class responsible for operations on the file expenses.xml
*/

class ExpensesFile :public File
{
    fstream file;

public:
    ExpensesFile();
    virtual ~ExpensesFile();

    void addExpensesToFile(Expense newExpense);
    int loadAllUserExpenses(vector <Expense> &expenses,int loggedInUserId);

};

#endif // EXPENSESFILE_H
