#include <iostream>
#include "income.h"
#include "dateoperations.h"
#include "Amount.h"

using namespace std;

Income::Income()
{
    incomeId = 0;
    userId = 0;
    date = 0;
    item = "";
    amount = 0;
}

Income::~Income()
{
    ;
}

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getUserId()
{
    return userId;
}

int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

double Income::getAmount()
{
    return amount;
}

void Income::setIncomeId(int incomeId)
{
    this -> incomeId = incomeId;
}

void Income::setUserId(int userId)
{
    this -> userId = userId;
}

void Income::setDate(int date)
{
    this -> date = date;
}

void Income::setItem(string item)
{
    this -> item = item;
}

void Income::setAmount(double amount)
{
    this -> amount = amount;
}

void Income::enterDate()
{
    char selectedMenuItem;
    DateOperations dateOperations;
    int date;
    cout << "Czy przychod dotyczy dnia dziesiejszego czy innego dnia?" << endl;
    cout << "1.Dzis" << endl;
    cout << "2.Inna data" << endl;
    cin >> selectedMenuItem;

    switch(selectedMenuItem)
    {
    case '1':
        date = dateOperations.getCurrentDayInt();
        break;
    case '2':
        date = dateOperations.loadDateFromUser();
        break;
    }
    setDate(date);
}

string Income::changeLargeLettersIntoSmallOnes(string word)
{
    string changeWord = "";

    for (int i = 0; i < word.length(); i++)   // 97-a 122-z  65 A 90-Z   97-65 = 32
    {
            if(word[i] >= 97 && word[i] <= 122)
            {
                changeWord += word[i];
            }
            else if (word[i] >= 65 && word[i] <= 90)
            {
                word[i] = word[i] + 32;
                changeWord += word[i];
            }
    }
    return changeWord;
}

void Income::enterItem()
{
    cout << "Podaj czego dotyczy przychod np. wyplata, odsetki z lokaty, sprzedaz na allegro" << endl;
    cin >> item;

    setItem(changeLargeLettersIntoSmallOnes(item));
}

void Income::enterAmount()
{
    Amount amount1;
    double amount;
    amount = amount1.enterAmount();

    setAmount(amount);
}
