#include "Date.h"
using namespace std;

Date::Date(int day, int month, int year)
{
	this->month = month;
	this->day = day;
	this->year = year;
}
Date::Date()
{
	Date::Date(0, 0, 0);
}

int Date::GetDay() const
{
	return day;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetYear() const
{
	return year;
}

void Date::SetDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
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

string Date::ToString() const
{
	return to_string(GetDay()) + '.' + to_string(GetMonth()) + '.' + to_string(GetYear());
}




bool Date::operator<(Date firstDate)
{
	return year == firstDate.year ?
		month == firstDate.month ?
		day < firstDate.day : month < firstDate.month :
		year < firstDate.year;
}

bool Date::operator>(Date firstDate)
{

	return year == firstDate.year ?
		month == firstDate.month ?
		day > firstDate.day : month > firstDate.month :
		year > firstDate.year;

}

bool Date::IsLeapYear()
{
	return year % 4 != 0 ? false : year % 100 == 0 ? year % 400 == 0 : true;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.ToString();
	return out;
}

istream& operator>>(istream& in, Date& p)
{
	int day, month, year;
	string dayStr, monthStr, yearStr;
	getline(in, dayStr, '.');
	day = stoi(dayStr);
	getline(in, monthStr, '.');
	month = stoi(monthStr);
	getline(in, yearStr);
	year = stoi(yearStr);
	p.SetDate(day, month, year);
	return in;


}

//ofstream& operator<<(ofstream& out, const Date& date)
//{
//	out << date.GetDay() << '.' << date.GetMonth() << '.' << date.GetYear() << endl;
//	return out;
//}
//
//ifstream& operator>>(ifstream& in, Date& date)
//{
//	int day, month, year;
//	string dayStr, monthStr, yearStr;
//	getline(in, dayStr, '.');
//	day = stoi(dayStr);
//	getline(in, monthStr, '.');
//	month = stoi(monthStr);
//	getline(in, yearStr);
//	year = stoi(yearStr);
//	p.SetDate(day, month, year);
//	return in;
//}
