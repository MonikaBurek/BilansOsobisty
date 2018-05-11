#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

/*
The class based on which the Income is created (getters and setters)
*/

class Income
{
    int incomeId;
    int userId;
    int date;
    string item;
    double amount;

public:
    Income();
    virtual ~Income();

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);

    void enterDate();
    void enterItem();
    void enterAmount();

    string changeLargeLettersIntoSmallOnes(string word);
};

#endif // Income_H
