//
// Created by Zhiyu Zhang on 6/20/23.
//

#include "Date.h"
void Date::printDate() const {
    std::cout << day << '/' << month << '/' << year << std::endl;
}

bool Date::checkDay(int testDay) const {
    static const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(testDay > 0 && testDay <= daysPerMonth[month])
        return true;
    if(month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return true; // leap year
    return false;
}
Date::Date(int d, int m, int y) {
    if(m > 0 && m <= 12)
        month = m;
    else
        throw std::invalid_argument("Month must be 1-12");

    year = y;
    if(checkDay(d))
        day = d;
    else
        throw std::invalid_argument("Day is out of range for current month and year");
}
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }