#include <iostream>
#include "incomes.h"
#include "incomesFile.h"
#include "Markup.h"
#include <windows.h>
#include <algorithm>

using namespace std;
Incomes::Incomes(int loggedInUserId)
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
            this -> lastIncomeId = applicationIncomesFile.loadAllUserIncomes(incomes,loggedInUserId);
        }
    }
    catch (int incorrectUserId1)
    {
        cout << endl << "Nie poprawny numer uzytkowanika.Nie jestes zalogowany" << endl << endl;
        system("pause");
        exit(0);
    }
}
Incomes::~Incomes()
{
    ;
}

Income Incomes::enterIncomeDate()
{
    int userId;
    string item;
    Income newIncome;

    userId = loggedInUserId;

    newIncome.enterDate();
    newIncome.enterItem();
    newIncome.enterAmount();

    newIncome.setIncomeId(++lastIncomeId);
    newIncome.setUserId(userId);

    return newIncome;
}

void Incomes::addIncome()
{
    bool isFileExists;

    isFileExists = applicationIncomesFile.isFileExists("incomes.xml"); // funkcja sprawdzaj¹ca czy plik istnieje (zwraca true jeœli istnieje)

    if (isFileExists == false)
    {
        CMarkup xml;
        xml.AddElem("incomes");
        xml.IntoElem();
        xml.Save("incomes.xml");
    }
    Income newIncome = enterIncomeDate();

    incomes.push_back(newIncome);
    applicationIncomesFile.addIncomesToFile(newIncome);

    cout << endl << "Zapisano przychod. " << endl;
    system("pause");
}

vector <Income> Incomes::getIncomesFromSelectedPeriod(int dateBeginPeriod, int dateEndPeriod)
{
    vector <Income> incomes;
    Income income;
    IncomesFile applicationIncomesFile;

    applicationIncomesFile.loadAllUserIncomes(incomes,loggedInUserId);

    if (!incomes.empty())
    {
        for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (itr -> getDate() < dateBeginPeriod || itr -> getDate() > dateEndPeriod)
            {
                itr = incomes.erase(itr);
                itr--;
            }
        }
    }


    return incomes;
}

struct CompareDate
{
    bool operator()(Income &first, Income & second)
    {
        return first.getDate() < second.getDate();
    }
} myObject2;

void Incomes::sortIncomesByDateInAscendingOrder(vector <Income> &incomes)
{
    sort(incomes.begin(), incomes.end(), myObject2);
}

void Incomes::showSelectedIncomes(vector <Income> &incomes)
{
    int counter = 0;
    sortIncomesByDateInAscendingOrder(incomes);

    cout << endl << "Lista przychodow:" << endl;
    cout << "Lp.";
    cout << "\tData";
    cout << "\t\tKategoria";
    cout << "\t\tKwota" << endl;

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        counter += 1;
        cout << counter << "\t";
        cout << dateOperations.convertDateFromIntToStringWithDash(itr -> getDate()) << "\t";
        cout << itr -> getItem() << "\t\t\t";
        cout << itr -> getAmount() << endl;
    }
}

float Incomes::getIncomesSum(vector<Income> &incomes)
{
    float incomesSum = 0;
    double amount = 0;

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        amount = itr -> getAmount();
        incomesSum +=  amount;
    }
    return incomesSum;
}

