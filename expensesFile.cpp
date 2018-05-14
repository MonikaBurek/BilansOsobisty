#include <iostream>
#include "expensesFile.h"
#include <windows.h>
#include <cstdlib>
#include "conversion.h"
#include "Markup.h"

using namespace std;

ExpensesFile::ExpensesFile()
{

}
ExpensesFile::~ExpensesFile()
{
    ;
}


void ExpensesFile::addExpensesToFile(Expense newExpense)
{
    string amount;
    Conversion conversion;
    CMarkup xml;
    xml.Load("expenses.xml");
    xml.FindElem();
    xml.IntoElem(); //inside ORDER

    xml.AddElem("expense");
    xml.IntoElem(); // inside user
    xml.AddElem("expenseId", newExpense.getExpenseId());
    xml.AddElem("userId", newExpense.getUserId());
    xml.AddElem("date", newExpense.getDate());
    xml.AddElem("item", newExpense.getItem());
    amount = conversion.conversionDoubleToString(newExpense.getAmount());
    xml.AddElem("amount", amount);

    xml.Save("expenses.xml");
}

int ExpensesFile::loadAllUserExpenses(vector <Expense> &expenses,int loggedInUserId)
{
    CMarkup xml;
    Expense expense;
    expenses.clear();
    int userId = 0;
    int lastExpenseIdInFile = 0;

    xml.Load("expenses.xml");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem(); //inside in Order

    while (xml.FindElem("expense"))
    {
        xml.IntoElem();
        xml.FindElem("userId");
        userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (loggedInUserId == userId)
        {
            xml.ResetMainPos();
            xml.IntoElem(); //inside user
            xml.FindElem("expenseId");
            expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
            lastExpenseIdInFile = atoi(MCD_2PCSZ(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("userId");
            expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            xml.FindElem("date");
            expense.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            xml.FindElem("item");
            expense.setItem(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("amount");
            expense.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
return lastExpenseIdInFile;
}

