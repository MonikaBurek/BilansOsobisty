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
   int conversionStringToDouble (string word);
};



