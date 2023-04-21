#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
struct Date
{
	int day;
	int month;
	int year;
	friend bool operator==(const Date& date1, const Date& date2)
	{
		return (date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year);
	}
	friend std::ostream& operator << (std::ostream& out, const Date& date)
	{
		out << "(" << date.day << "." << date.month << "." << date.year << ")";
		return out;
	}
};
#endif