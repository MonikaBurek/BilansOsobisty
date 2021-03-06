#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include <iostream>
#include <vector>
#include "Date.h"
#include <string>
#include "conversion.h"

using namespace std;

/*
The class responsible for operations on dates.
*/

class DateOperations
{
    Date userDate;
    Conversion conversion;
    public:
    DateOperations();
    virtual ~DateOperations();

    int loadDateFromUser();
    bool isDateCorrect(string dateProvidedByUser);
    Date getCurrentDay();
    int getCurrentDayInt();
    int howManyDaysHaveMonth(int year, int month, int day);
    bool ComparisonOfDateInRange(string dateProvidedByUser);
    int daysFromBeginningOfYear(int year, int month, int day);
    Date setVariableUserDate(string dateProvidedByUser);

    int convertDateFromStringWithDashToInt(string dateStr);
    string convertDateFromIntToStringWithDash(int dateInt);

    int getFistDateInCurrentMonth();
    int getFistDateInPreviousMonth();
    int getLastDateInPreviousMonth();

};
#endif // DATEOPERATIONS_H
