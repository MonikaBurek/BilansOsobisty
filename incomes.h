#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <vector>
#include "income.h"
#include "incomesFile.h"

using namespace std;

class Incomes
{
    vector <Income> incomes;
    int loggedInUserId;
    int lastIncomeId;
    IncomesFile applicationIncomesFile;
    DateOperations dateOperations;

public:
    Incomes(int loggedInUserId);
    virtual ~Incomes();
    void addIncome();
    vector <Income> getIncomesFromSelectedPeriod(int dateBeginPeriod, int dateEndPeriod);
    void showSelectedIncomes(vector <Income> &incomes);
    float getIncomesSum(vector <Income> &incomes);

private:
    Income enterIncomeDate();
    void sortIncomesByDateInAscendingOrder(vector <Income> &incomes);


};

#endif // Incomes_H
