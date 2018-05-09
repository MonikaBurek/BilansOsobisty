#include <iostream>
#include "expenses.h"
#include "expensesFile.h"
#include "Markup.h"
#include <windows.h>

using namespace std;

Expense Expenses::enterExpenseDate()
{
    int expenseId,userId,date;
    string item;
    double amount;
    Expense newExpense;
    bool doesExpenseExistIdOneInFile;

    doesExpenseExistIdOneInFile = applicationExpensesFile.isFirstItemInFile("expenses.xml", "expense");

    if ( doesExpenseExistIdOneInFile == false)
    {
       expenseId = 1;           // then the new friend has id = 1
    }
    else
    {
        expenseId = lastExpenseId + 1; //applicationExpensesFile.getLastExpenseId() otherwise, get the last person's id from the address book and increase the value by one.
    }

    userId = loggedInUserId;

    newExpense.enterDate();
    newExpense.enterItem();
    newExpense.enterAmount();

    newExpense.setExpenseId(expenseId);
    newExpense.setUserId(userId);

    return newExpense;
}

void Expenses::addExpense()
{
    bool isFileExists;

    isFileExists = applicationExpensesFile.isFileExists("expenses.xml"); // funkcja sprawdzaj¹ca czy plik istnieje (zwraca true jeœli istnieje)

    if (isFileExists == false)
    {
        CMarkup xml;
        xml.AddElem("expenses");
        xml.IntoElem();
        xml.Save("expenses.xml");
    }

    Expense newExpense = enterExpenseDate();

    expenses.push_back(newExpense);
    applicationExpensesFile.addExpensesToFile(newExpense);

    cout << endl << "Zapisano wydatek. " << endl;
    Sleep(1000);
}
