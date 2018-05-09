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
    xml.AddElem("amount", newExpense.getAmount());
    //xml.OutOfElem(); // back out to user level

    xml.Save("expenses.xml");
    cout << "Dane zostaly zapisne." << endl;
    system("pause");

}

int ExpensesFile::loadAllUserExpenses(vector <Expense> &expenses,int)
{
    CMarkup xml;
    Expense expense;
    expenses.clear();

    xml.Load("expenses.xml");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem(); //inside in Order
    xml.FindElem("expense");
    do
    {
        xml.IntoElem(); //inside user
        xml.FindElem("expenseId");
        expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.ResetMainPos();

        xml.FindElem("userId");
        expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        cout << "F.Load UserId: " << expense.getUserId() << endl;
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
        xml.OutOfElem();
    }while (xml.FindElem("expense"));
}
