#include <iostream>
#include "amount.h"
#include <cstdlib>
#include <math.h>


using namespace std;

Amount::Amount()
{
    amount = 0;
}

Amount:: ~Amount()
{
    ;
}

double Amount::enterAmount()
{
    string amount,amount2;
    bool result;
    double amountDouble,amountRoundToTwoDigitsAfterDot ;
    bool wrongAmount;

    do
    {
    cout << "Podaj wysokosc wydatku: "; ;
    cin >> amount;

    amount2 = replaceCommaWithDot(amount);
    result = isCorrectAmount(amount2);

    if (result == true)
    {
        amountDouble = conversion.conversionStringToDouble(amount2);
        amountRoundToTwoDigitsAfterDot = roundDownToTwoDigitsAfterDot(amountDouble);
        wrongAmount = false;
    }
    else if (result == false)
    {
        cout << "Podano nie wlasciwie wysokosc wydatku." << endl;
        wrongAmount = true;

    }
    }while (wrongAmount == true );


    return amountRoundToTwoDigitsAfterDot;
}

string Amount::replaceCommaWithDot(string numberStr)
{
    for (int i = 0; i < numberStr.length(); i++)
    {
        if(numberStr[i] == 44)  // 44 - ,
        {
            numberStr = numberStr.replace(i,1,".");
        }
    }
    return numberStr;
}

bool Amount::doesItContainDigitsAndDots(string amount)
{
    bool digitsAndDots;
    for (int i = 0; i < amount.length(); i++)
    {
        if(amount[i] > 57 || amount[i] < 48 && amount[i] != 46)
        {
            digitsAndDots = false;
            return digitsAndDots;
        }
    }
    digitsAndDots = true;

    return digitsAndDots;
}

bool Amount::doesItContainOneDot(string amount)
{
    int numberOfDots = 0;
    bool result;
    for (int i = 0; i < amount.length(); i++)
    {
        if (amount[i] == 46 )
        {
            numberOfDots += 1;
        }
    }

    if ( numberOfDots <= 1)
    {
        result = true;
    }
    else if (numberOfDots > 1)
    {
        result = false;
    }

    return result;
}


bool Amount::isCorrectAmount(string amount)
{
    bool result;
    bool digitsAndDots;

    digitsAndDots = doesItContainDigitsAndDots(amount);

    if (digitsAndDots == true)
    {
        result = doesItContainOneDot(amount);
    }
    else if (digitsAndDots == false)
    {
        result = false;
    }
    return result;

}

double Amount::roundDownToTwoDigitsAfterDot(double number)
{
    double numberTwoDigtsAfterDot;

    numberTwoDigtsAfterDot = round (number*100)/100;

    return numberTwoDigtsAfterDot;
}

