#include <iostream>
#include "budgetManager.h"
#include "expenses.h"
#include "incomes.h"
#include "dateoperations.h"
#include "windows.h"

using namespace std;

BudgetManager::BudgetManager(int loggedUserId):incomesUser(loggedUserId), expensesUser(loggedUserId)
{
    userId = loggedUserId;
}

BudgetManager::~BudgetManager()
{
    ;
}

void BudgetManager::addIncome()
{
    incomesUser.addIncome();
}

void BudgetManager::addExpense()
{
    expensesUser.addExpense();
}

void BudgetManager::showBalanceFromCurrentMonth()
{
    int startDate, endDate;
    cout << "Bilans z biezacego miesiaca." << endl;

    startDate = dateOperations.getFistDateInCurrentMonth();
    endDate = dateOperations.getCurrentDayInt();

    showBalane(startDate,endDate);
}

void BudgetManager::showBalanceFromPreviousMonth()
{
    int startDate, endDate;
    cout << "Bilans z poprzedniego miesiaca." << endl;

    startDate = dateOperations.getFistDateInPreviousMonth();
    endDate = dateOperations.getLastDateInPreviousMonth();

    showBalane(startDate,endDate);
}

void BudgetManager::showBalanceFromSelectedPeriod()
{
    int startDate, endDate;

    cout << "Bilans z wybranego okresu." << endl << endl;
    cout << "Data poczatku okresu." << endl;;
    startDate = dateOperations.loadDateFromUser();

    do
    {
        cout << "Data konca okresu." << endl;
        endDate = dateOperations.loadDateFromUser();
        if ( startDate > endDate)
        {
            cout << "Podano niepoprawna date zakonczenia okresu." << endl;
        }
    }
    while (startDate > endDate);


    showBalane(startDate,endDate);
}

void BudgetManager::showBalane(int startDate,int endDate)
{
    vector <Income> incomes;
    vector <Expense> expenses;

    system("cls");
    cout << "Bilans z okresu od " << dateOperations.convertDateFromIntToStringWithDash(startDate)<< " do " << dateOperations.convertDateFromIntToStringWithDash(endDate) << "." << endl;

    incomes = incomesUser.getIncomesFromSelectedPeriod(startDate,endDate);
    if (!incomes.empty())
    {
        incomesUser.showSelectedIncomes(incomes);
    }
    else
    {
        cout << "Brak przychodow w wybranym czasie." << endl;
    }

    expenses = expensesUser.getExpenseFromSelectedPeriod(startDate,endDate);
    if (!expenses.empty())
    {
        expensesUser.showSelectedExpenses(expenses);
    }
    else
    {
        cout << "Brak wydatkow w wybranym czasie." << endl;
    }

    cout << endl << "Suma przychodow: " << incomesUser.getIncomesSum(incomes) << endl;
    cout << "Suma wydatkow: " << expensesUser.getExpensesSum(expenses) << endl;
    cout << "Roznica przychodow i wydatkow: " << incomesUser.getIncomesSum(incomes) - expensesUser.getExpensesSum(expenses) << endl << endl;
    system("pause");
}
