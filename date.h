#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

/*
The class based on which the Date is created (getters and setters)
*/

class Date
{
    int year;
    int month;
    int day;

public:
    Date();
    virtual ~Date();

    int getYear();
    int getMonth();
    int getDay();

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
};

#endif // Date_H
