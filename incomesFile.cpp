#include <iostream>
#include "incomesfile.h"
#include <windows.h>
#include <cstdlib>
#include "conversion.h"
#include "Markup.h"

using namespace std;

IncomesFile::IncomesFile()
{

}
IncomesFile::~IncomesFile()
{
    ;
}


void IncomesFile::addIncomesToFile(Income newIncome)
{
    string amount;
    Conversion conversion;
    CMarkup xml;
    xml.Load("incomes.xml");
    xml.FindElem();
    xml.IntoElem(); //inside ORDER

    xml.AddElem("income");
    xml.IntoElem(); // inside user
    xml.AddElem("incomeId", newIncome.getIncomeId());
    xml.AddElem("userId", newIncome.getUserId());
    xml.AddElem("date", newIncome.getDate());
    xml.AddElem("item", newIncome.getItem());
    amount = conversion.conversionDoubleToString(newIncome.getAmount());
    xml.AddElem("amount", amount);

    xml.Save("incomes.xml");
}

int IncomesFile::loadAllUserIncomes(vector <Income> &incomes,int loggedInUserId)
{
    CMarkup xml;
    Income income;
    incomes.clear();
    int userId = 0;
    int lastIncomeIdInFile = 0;

    xml.Load("incomes.xml");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem(); //inside in Order

    while (xml.FindElem("income"))
    {
        xml.IntoElem();
        xml.FindElem("userId");
        userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (loggedInUserId == userId)
        {
            xml.ResetMainPos();
            xml.IntoElem(); //inside user
            xml.FindElem("incomeId");
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            lastIncomeIdInFile = atoi(MCD_2PCSZ(xml.GetData()));
            xml.ResetMainPos();

            xml.FindElem("userId");
            income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            xml.FindElem("date");
            income.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            xml.FindElem("item");
            income.setItem(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("amount");
            income.setAmount(atof(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
return lastIncomeIdInFile;
}

