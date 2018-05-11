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
       cout << endl << "Nie poprawny numer użytkowanika.Nie jesteś zalogowany" << endl << endl;
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
    int userId,date;
    string item;
    double amount;
    Expense newExpense;
    bool doesExpenseExistIdOneInFile;

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

vector <Expense> Expenses::getExpenseFromSelectedPeriod(int dateBeginPeriod, int dateEndPeriod)
{
    vector <Expense> expenses;
    Expense expense;
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

