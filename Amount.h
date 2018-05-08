#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>
#include "conversion.h"

using namespace std;


class Amount
{
    double amount;
    Conversion conversion;

public:
    Amount();
    virtual ~Amount();

    double enterAmount();

private:
    bool isCorrectAmount(string amount);
    bool doesItContainDigitsAndDots(string amount);
    string replaceCommaWithDot(string numberStr);
    bool doesItContainOneDot(string amount);
    double roundDownToTwoDigitsAfterDot(double number);
};

#endif // AMOUNT_H
