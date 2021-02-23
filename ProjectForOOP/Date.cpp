#include "Date.h"
#include <vector>
using namespace std;
Date::Date(int day, int month, int year)
{
	vector<int> dayMonthly = { 21,29,};
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date()
{
	Date::Date(0, 0, 0);
}

int Date::GetDay()
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

Date Date::GetDifference(Date otherDate)
{
	return Date()
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
