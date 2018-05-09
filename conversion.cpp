#include <iostream>
#include "Conversion.h"
#include <cstdlib>

using namespace std;

string Conversion::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string stringOut = ss.str();
    return stringOut;
}

int Conversion::conversionStringToInt (string word)
{
    int variable;
    variable = atoi(word.c_str());
    return variable;
}

string Conversion::conversionDoubleToString (double number2)
{
    ostringstream os;
    os << number2;
    string stringOut = os.str();
    return stringOut;
}

double Conversion::conversionStringToDouble (string word)
{
    double variable;
    variable = atof(word.c_str());
    return variable;
}
