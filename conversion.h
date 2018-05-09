#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Conversion
{
   int number;
   double number2;
   string word;

   public:
   string conversionIntToString (int number);
   int conversionStringToInt (string word);
   string conversionDoubleToString (double number2);
   double conversionStringToDouble (string word);
};

#endif //CONVERSION_H

