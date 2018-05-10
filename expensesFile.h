#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include "expense.h"
#include "file.h"
#include "date.h"
#include "dateoperations.h"

using namespace std;

/*
The class responsible for operations on the file Expenses.txt
*/

class ExpensesFile :public File
{
    fstream file;
  //  Date date;

public:
    ExpensesFile();
    virtual ~ExpensesFile();

    void addExpensesToFile(Expense newExpense);
    int loadAllUserExpenses(vector <Expense> &expenses,int loggedInUserId);

};

#endif // USERSFILE_H
