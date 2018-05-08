#include <iostream>
#include "dateoperations.h"
#include <windows.h>
#include <string>


using namespace std;

DateOperations::DateOperations()
{

}

DateOperations::~DateOperations()
{
    ;
}

Date DateOperations::getCurrentDay()
{
    int year,month, day;

    Date currentDate;
    SYSTEMTIME st;
    GetLocalTime(&st);

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    currentDate.setYear(year);
    currentDate.setMonth(month);
    currentDate.setDay(day);

    return currentDate;

}

int DateOperations::howManyDaysHaveMonth(int year, int month, int day) //ileDniMaDanyMiesiac()  how many days have a given month
{
    int numberOfDaysInMonth = 0; //iloscDniWMiesiacu; number of Days in a month
    bool leapYear; //rokPrzestepny;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leapYear = true;
    else
        leapYear = false;

    if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        numberOfDaysInMonth = 30;
    }
    else if(month == 2)
    {
        if(leapYear == true)
        {
            numberOfDaysInMonth = 29;
        }
        else
        {
            numberOfDaysInMonth = 28;
        }
    }
    else
    {
        numberOfDaysInMonth = 31;
    }
    cout << endl;
    cout << month << " iloscDniWMiesiacu: " <<  numberOfDaysInMonth << endl;

    return numberOfDaysInMonth;
}

int DateOperations::daysFromBeginningOfYear(int year, int month, int day)
{
    int sumDaysFromBeginningOfYear = 0;

    for (int i = 1; i < month; i++)
    {
        sumDaysFromBeginningOfYear += howManyDaysHaveMonth(year,month - i,day);
    }
    sumDaysFromBeginningOfYear += day;
    cout << "sumDaysFromBeginningOfYear" << sumDaysFromBeginningOfYear << endl;

    return sumDaysFromBeginningOfYear;
}

Date DateOperations::setVariableUserDate(string dateProvidedByUser)
{
    Date userDate;
    string yearStr, monthStr, dayStr;
    int year, month, day;

    Conversion conversion1;

    yearStr = dateProvidedByUser.substr(0,4);
    monthStr = dateProvidedByUser.substr(5,2);
    dayStr = dateProvidedByUser.substr(8,2);

    year = conversion1.conversionStringToInt(yearStr);
    month = conversion1.conversionStringToInt(monthStr);
    day = conversion1.conversionStringToInt(dayStr);

    userDate.setYear(year);
    userDate.setMonth(month);
    userDate.setDay(day);

    return userDate;
}

bool DateOperations::ComparisonOfDateInRange(string dateProvidedByUser) //Range: 2000-01-01 to the current date
{
    int sumDaysUser, sumDaysCurrentDay;
    bool returnValue;

    Date userDate = setVariableUserDate(dateProvidedByUser);
    Date currentDate = getCurrentDay();


    if ((userDate.getMonth() < 1 || userDate.getMonth() > 12) || (userDate.getDay() < 1 || userDate.getDay() > howManyDaysHaveMonth(userDate.getYear(), userDate.getMonth(), userDate.getDay())) || (userDate.getYear() < 2000 || userDate.getYear() > currentDate.getYear()))
    {
        cout << "((month < 1 || month > 12) || (day < 1 || day > howManyDaysHaveMonth(year, month, day)) || (year > 2000 || year <= currentYear))" << endl;
        returnValue = false;
        return returnValue;
    }

    if (userDate.getYear() == currentDate.getYear() )
    {
        cout << "(year == currentYear )" << endl;

        if (userDate.getMonth() == currentDate.getMonth() && userDate.getDay() <= currentDate.getDay())
        {
            cout << "(month == currentMonth && day <= currentDay)" << endl;
            returnValue = true;
        }
        else if (userDate.getMonth() < currentDate.getMonth())
        {
            cout << "(month < currentMonth)" << endl;
            sumDaysUser = daysFromBeginningOfYear(userDate.getYear(), userDate.getMonth(), userDate.getDay());
            sumDaysCurrentDay = daysFromBeginningOfYear(currentDate.getYear(), currentDate.getMonth(), currentDate.getDay());
            if (sumDaysUser <= sumDaysCurrentDay)
            {
                cout << "(sumDaysUser <= sumDaysCurrentDay)" << endl;
                returnValue = true;
                return returnValue;
            }
            else
            {
                cout << "(sumDaysUser <= sumDaysCurrentDay)" << endl;
                returnValue = false;
                return returnValue;
            }
        }
    }
    else if (userDate.getYear() < currentDate.getYear())
    {
        cout << "(year < currentYear)" << endl;

        returnValue = true;
        return returnValue;
    }

    return returnValue;
}


bool DateOperations::isDateCorrect(string dateProvidedByUser)
{
    bool returnValue;

    if (dateProvidedByUser.length() > 10 || dateProvidedByUser.length() < 10)
    {
        returnValue = false;
        return returnValue;
    }
    else if (dateProvidedByUser.length() == 10)
    {
        for (int i = 0; i < dateProvidedByUser.length(); i++ )
        {
            if ( dateProvidedByUser[i] > 57 || dateProvidedByUser[i] < 48 && dateProvidedByUser[i] != 45 )
            {
                return returnValue;
            }
        }
    }

    returnValue = ComparisonOfDateInRange(dateProvidedByUser);

    return  returnValue;
}


void DateOperations::loadDateFromUser()
{
    string dateProvidedByUser;
    bool replay;

    cout << "Podaj date w formacie rrrr-mm-dd np. 2017-11-01. Z zakresu od 2000-01-01 do dzis : " << endl;
    cin >> dateProvidedByUser;

    replay = isDateCorrect(dateProvidedByUser);//sprawdz czy data jest poprawna

    if (replay == true)
    {
        cout << "Data jest poprawna." << endl;
        convertDateFromStringWithDashTolnt(dateProvidedByUser);
    }
    else if (replay == false)
    {
        cout << "Data jest niepoprawna." << endl;
    }
}

int DateOperations::convertDateFromStringWithDashTolnt(string dateStr)
{
    int dateInt;

    dateStr.erase(4,1);
    dateStr.erase(6,1);

    dateInt = conversion.conversionStringToInt(dateStr);

    return dateInt;
}

string DateOperations::convertDateFromIntToStringWithDash(int dateInt)
{
    string dateStr = "";
    string date = "";

    date = conversion.conversionIntToString(dateInt);

    dateStr = date.insert(4,"-");
    dateStr = date.insert(7,"-");

    return dateStr;
}


