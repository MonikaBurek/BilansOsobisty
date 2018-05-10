#include <iostream>
#include "expenses.h"
#include "expensesFile.h"
#include "Markup.h"
#include <windows.h>
#include <algorithm>

using namespace std;
Expenses::Expenses()
{
    int loggedInUserId = 0;
    int lastExpenseId = 0;
}
Expenses::~Expenses()
{
    ;
}

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
        expenseId = lastExpenseId + 1; //otherwise, get the last person's id from the address book and increase the value by one.
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
    lastExpenseId = applicationExpensesFile.loadAllUserExpenses(expenses,1);
    Expense newExpense = enterExpenseDate();

    expenses.push_back(newExpense);
    applicationExpensesFile.addExpensesToFile(newExpense);

    cout << endl << "Zapisano wydatek. " << endl;
    Sleep(1000);
}

vector <Expense> Expenses::getExpenseFromSelectedPeriod(int dateBeginPeriod, int dateEndPeriod)
{
    vector <Expense> expenses;
    Expense expense;
    int loggedInUserId = 1;
    ExpensesFile applicationExpensesFile;

    applicationExpensesFile.loadAllUserExpenses(expenses,loggedInUserId);

    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if (itr -> getDate() < dateBeginPeriod || itr -> getDate() > dateEndPeriod)
        {
            itr = expenses.erase(itr);
            cout << "Wydatek zostal usuniety." << endl << endl;
            break;
        }
    }

    showSelectedExpenses(expenses);
    getExpensesSum(expenses);

    return expenses;
}

struct CompareDate
{
    bool operator()(Expense &first, Expense & second)
    {
        return first.getDate() > second.getDate();
    }
} myObject;

void Expenses::sortExpensesByDateInAscendingOrder(vector<Expense> &expenses)
{
    cout << "Zmienne posorowane. " <<endl;
    sort(expenses.begin(), expenses.end(), myObject);

}
void Expenses::showSelectedExpenses(vector <Expense> &expenses)
{
    int counter = 0;
    sortExpensesByDateInAscendingOrder(expenses);

    cout << "Lista wydatkow:" << endl;
    cout.width(5);
    cout << left << "Lp." ;
    cout.width(15);
    cout << left << "Data" ;
    cout.width(19);
    cout << left << "Kategoria" ;
    cout.width(20);
    cout << left <<" Kwota" << endl;

    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        counter += 1;
        cout << counter << "    ";
        cout << dateOperations.convertDateFromIntToStringWithDash(itr -> getDate()) << "     " ;
        cout << itr -> getItem() << "          ";
        cout << itr -> getAmount() << "    " << endl;
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
    cout << "Suma wydatkow: " << expensesSum << endl;

 return expensesSum;
}

