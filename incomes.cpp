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
   catch (int incorrectUserId)
   {
       cout << endl << "Nie poprawny numer użytkowanika.Nie jesteś zalogowany" << endl << endl;
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
    int userId,date;
    string item;
    double amount;
    Income newIncome;
    bool doesIncomeExistIdOneInFile;

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
    Sleep(1000);
}

vector <Income> Incomes::getIncomesFromSelectedPeriod(int dateBeginPeriod, int dateEndPeriod)
{
    vector <Income> incomes;
    Income income;
    IncomesFile applicationIncomesFile;

    applicationIncomesFile.loadAllUserIncomes(incomes,loggedInUserId);

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr -> getDate() < dateBeginPeriod || itr -> getDate() > dateEndPeriod)
        {
            itr = incomes.erase(itr);
            cout << "Przychod zostal usuniety." << endl << endl;
            break;
        }
    }

    showSelectedIncomes(incomes);
    getIncomesSum(incomes);

    return incomes;
}

struct CompareDate
{
    bool operator()(Income &first, Income & second)
    {
        return first.getDate() > second.getDate();
    }
} myObject2;

void Incomes::sortIncomesByDateInAscendingOrder(vector <Income> &incomes)
{
    cout << "Zmienne posorowane. " <<endl;
    sort(incomes.begin(), incomes.end(), myObject2);

}

void Incomes::showSelectedIncomes(vector <Income> &incomes)
{
    int counter = 0;
    sortIncomesByDateInAscendingOrder(incomes);

    cout << "Lista przychodow:" << endl;
    cout.width(5);
    cout << left << "Lp." ;
    cout.width(15);
    cout << left << "Data" ;
    cout.width(19);
    cout << left << "Kategoria" ;
    cout.width(20);
    cout << left <<" Kwota" << endl;

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        counter += 1;
        cout << counter << "    ";
        cout << dateOperations.convertDateFromIntToStringWithDash(itr -> getDate()) << "     " ;
        cout << itr -> getItem() << "          ";
        cout << itr -> getAmount() << "    " << endl;
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
    cout << "Suma przychodow: " << incomesSum << endl;

 return incomesSum;
}

