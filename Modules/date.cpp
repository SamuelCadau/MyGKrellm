/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** date
*/

#include "date.hpp"

Date::Date()
{
    _display = true;
}

void Date::setDate()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    _date = dt;
}