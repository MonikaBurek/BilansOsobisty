#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "expenses.h"
#include "incomes.h"
#include "dateoperations.h"

using namespace std;

/*
The class responsible
*/

class BudgetManager
{
    int userId;
    DateOperations dateOperations;
    Incomes incomesUser;
    Expenses expensesUser;

public:
    BudgetManager(int userId);
    virtual ~BudgetManager();

    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();

private:
    void showBalane(int,int);
};

#endif //BUDGETMANAGER_H
