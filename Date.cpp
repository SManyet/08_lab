//
// Created by Luke Cheng on 3/17/20.
//

#include "Date.h"

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

bool Date::operator < (Date const &obj)
{
    bool status;

    if (year < obj.year || year > obj.year){ // checks year
        if (year < obj.year) { // if year is less than
            status = true;
            return status;
        } else { //if year is greater than
            status = false;
            return status;
        }
    } else if(month < obj.month || month > obj.month){ //if year is equal, then check month
        if (month < obj.month) { // if month is less than
            status = true;
            return status;
        } else { //if month is greater than
            status = false;
            return status;
        }
    } else if(day < obj.day || day > obj.day) { //if month is equal, then check day
        if (day < obj.day) { // if month is less than
            status = true;
            return status;
        } else { //if month is greater than
            status = false;
            return status;
        }
    } else { //dates are equal, return false
        status = false;
        return status;
    }
}

bool Date::operator > (Date const &obj)
{
    bool status;

    if (year < obj.year || year > obj.year){ // checks year
        if (year > obj.year) { // if year is less than
            status = true;
            return status;
        } else { //if year is greater than
            status = false;
            return status;
        }
    } else if(month < obj.month || month > obj.month){ //if year is equal, then check month
        if (month > obj.month) { // if month is less than
            status = true;
            return status;
        } else { //if month is greater than
            status = false;
            return status;
        }
    } else if(day < obj.day || day > obj.day) { //if month is equal, then check day
        if (day > obj.day) { // if month is less than
            status = true;
            return status;
        } else { //if month is greater than
            status = false;
            return status;
        }
    } else { //dates are equal, return false
        status = false;
        return status;
    }
}

bool Date::operator == (Date const &obj){
    bool status;

    if ( (year == obj.year) && (year == obj.year) && (year == obj.year) ) {
        status = true;
        return status;
    } else {
        status = false;
        return status;
    }
}

