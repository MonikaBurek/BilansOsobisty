#include <iostream>
#include "expenses.h"
#include "expensesFile.h"
#include "Markup.h"
#include <windows.h>
#include <algorithm>


using namespace std;
Expenses::Expenses(int loggedInUserId)
{
    try
    {
        if (loggedInUserId <= 0)
        {
            throw 0;
        }
        else
        {
            this -> loggedInUserId = loggedInUserId;
            this -> lastExpenseId = applicationExpensesFile.loadAllUserExpenses(expenses,loggedInUserId);
        }
    }
    catch (int incorrectUserId)
    {
        cout << endl << "Nie poprawny numer uzytkowanika. Nie jestes zalogowany" << endl << endl;
        system("pause");
        exit(0);
    }
}
Expenses::~Expenses()
{
    ;
}

Expense Expenses::enterExpenseDate()
{
    int userId;
    string item;
    Expense newExpense;

    userId = loggedInUserId;

    newExpense.enterDate();
    newExpense.enterItem();
    newExpense.enterAmount();

    newExpense.setExpenseId(++lastExpenseId);
    newExpense.setUserId(userId);

    return newExpense;
}

void Expenses::addExpense()
{
    bool isFileExists;

    isFileExists = applicationExpensesFile.isFileExists("expenses.xml");

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

    cout << endl << "Zapisano wydatek." << endl;
    system("pause");
}

vector <Expense> Expenses::getExpenseFromSelectedPeriod(int dateBeginPeriod, int dateEndPeriod)
{
    vector <Expense> expenses;
    Expense expense;
    ExpensesFile applicationExpensesFile;

    applicationExpensesFile.loadAllUserExpenses(expenses,loggedInUserId);

    if (!expenses.empty())
    {
        for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if (itr -> getDate() < dateBeginPeriod || itr -> getDate() > dateEndPeriod)
            {
                itr = expenses.erase(itr);
                itr--;
            }
        }
    }
    return expenses;
}

struct CompareDate
{
    bool operator()(Expense &first, Expense & second)
    {
        return first.getDate() < second.getDate();
    }
} myObject;

void Expenses::sortExpensesByDateInAscendingOrder(vector<Expense> &expenses)
{
    sort(expenses.begin(), expenses.end(), myObject);
}

void Expenses::showSelectedExpenses(vector <Expense> &expenses)
{
    int counter = 0;
    sortExpensesByDateInAscendingOrder(expenses);

    cout << endl << "Lista wydatkow:" << endl;
    cout << "Lp.";
    cout << "\tData";
    cout << "\t\tKategoria";
    cout << "\t\tKwota" << endl;

     for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        counter += 1;
        cout << counter << "\t";
        cout << dateOperations.convertDateFromIntToStringWithDash(itr -> getDate()) << "\t";
        cout << itr -> getItem() << "\t\t";
        cout << itr -> getAmount() << endl;
    }
}

float Expenses::getExpensesSum(vector<Expense> &expenses)
{
    float expensesSum = 0;
    double amount = 0;

    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        amount = itr -> getAmount();
        expensesSum +=  amount;
    }

    return expensesSum;
}

