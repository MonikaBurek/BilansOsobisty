#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>



using namespace std;

/*
The class based on which the Expense is created (getters and setters)
*/

class Expense
{
    int expenseId;
    int userId;
    int date;
    string item;
    double amount;

public:
    Expense();
    virtual ~Expense();

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);

    void enterDate();
    void enterItem();
    void enterAmount();
};

#endif // EXPENSE_H
