#pragma once

#include <vector>
#include <time.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Date
{
public:
	Date(int day, int month, int year);
	Date();
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetDate(int day, int month, int year);
	int GetDifferenceInDays(Date otherDate);
	int GetDayCount();
	bool IsEearlier(Date otherDate);
	string ToString() const;
	friend istream& operator>>(istream& in, Date& p);
	friend ostream& operator<<(ostream& in,const Date& p);
	bool operator < (Date firstDate);
	bool operator > (Date firstDate);
private:
	bool IsLeapYear();
	int day;
	int month;
	int year;
};

