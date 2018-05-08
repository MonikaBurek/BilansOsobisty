#include <iostream>
#include "Date.h"

using namespace std;

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
}

Date::~Date()
{
    ;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::setYear(int year)
{
    this -> year = year;
}

void Date::setMonth(int month)
{
    this -> month = month;
}

void Date::setDay(int day)
{
    this -> day = day;
}
