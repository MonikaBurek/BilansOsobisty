#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>
#include "expense.h"
#include "expensesFile.h"

using namespace std;

class Expenses
{
    vector <Expense> expenses;
    int loggedInUserId;
    int lastExpenseId;
    ExpensesFile applicationExpensesFile;
    DateOperations dateOperations;

public:
    Expenses(int loggedInUserId);
    virtual ~Expenses();
    void addExpense();
    vector <Expense> getExpenseFromSelectedPeriod(int dateBeginPeriod, int dateEndPeriod);
    void showSelectedExpenses(vector <Expense> &expenses);
    float getExpensesSum(vector <Expense> &expenses);

private:
    Expense enterExpenseDate();
    void sortExpensesByDateInAscendingOrder(vector <Expense> &expenses);


};

#endif // EXPENSES_H
