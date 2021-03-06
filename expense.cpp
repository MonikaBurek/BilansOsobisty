#include <iostream>
#include "expense.h"
#include "dateoperations.h"
#include "Amount.h"

using namespace std;

Expense::Expense()
{
    expenseId = 0;
    userId = 0;
    date = 0;
    item = "";
    amount = 0;
}

Expense::~Expense()
{
    ;
}

int Expense::getExpenseId()
{
    return expenseId;
}

int Expense::getUserId()
{
    return userId;
}

int Expense::getDate()
{
    return date;
}

string Expense::getItem()
{
    return item;
}

double Expense::getAmount()
{
    return amount;
}

void Expense::setExpenseId(int expenseId)
{
    this -> expenseId = expenseId;
}

void Expense::setUserId(int userId)
{
    this -> userId = userId;
}

void Expense::setDate(int date)
{
    this -> date = date;
}

void Expense::setItem(string item)
{
    this -> item = item;
}

void Expense::setAmount(double amount)
{
    this -> amount = amount;
}

void Expense::enterDate()
{
    char selectedMenuItem;
    DateOperations dateOperations;
    int date;
    cout << "Czy wydatek dotyczy dnia dziesiejszego czy innego dnia?" << endl;
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

string Expense::changeLargeLettersIntoSmallOnes(string word)
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

void Expense::enterItem()
{
    cout << "Podaj czego dotyczy wydatek np. jedzenie, restauracja, mieszkanie, transport." << endl;
    cin >> item;

    setItem(changeLargeLettersIntoSmallOnes(item));
}

void Expense::enterAmount()
{
    Amount amount1;
    double amount;
    amount = amount1.enterAmount();

    setAmount(amount);
}
