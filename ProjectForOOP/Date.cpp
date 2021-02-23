#include "Date.h"
#include <vector>
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;
Date::Date(int day, int month, int year)
{
	vector<int> dayMonthly = { 31,29,31,30,31,30,31,31,30,31,30,31};
	this->month = (month - 1) % 12 + 1;
	this->day = day % dayMonthly[this->month];
	this->year = year;
}
Date::Date(int dayCount)
{
	Date::Date(0, 0, 0);
	
}
Date::Date()
{
	Date::Date(0, 0, 0);
}

const int Date::GetDay()
{
	return day;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetYear()
{
	return year;
}

int Date::GetDifferenceInDays(Date otherDate)
{
	return GetDayCount() - otherDate.GetDayCount();
}

int Date::GetDayCount()
{
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;
	return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

bool Date::IsEearlier(Date otherDate)
{
	return GetDayCount() < otherDate.GetDayCount();
}

void Date::GD(double jd)
{
	

}

bool Date::IsLeapYear()
{
	return year % 4 != 0 ? false : year % 100 == 0 ? year % 400 == 0 : true;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.GetDay() << '.' << date.GetMonth() << date.GetYear();
	return out;
}
