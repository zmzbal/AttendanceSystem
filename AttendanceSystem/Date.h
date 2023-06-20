//
// Created by Zhiyu Zhang on 6/20/23.
//

#ifndef ATTENDANCESYSTEM_DATE_H
#define ATTENDANCESYSTEM_DATE_H


#include<iostream>

class Date {
private:
    int day;
    int month;
    int year;

    bool checkDay(int testDay) const;

public:
    Date(int d, int m, int y);

    void printDate() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

};


#endif //ATTENDANCESYSTEM_DATE_H
