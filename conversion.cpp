#include <iostream>
#include "Conversion.h"

using namespace std;

string Conversion::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string stringOut = ss.str();
    return stringOut;
}
