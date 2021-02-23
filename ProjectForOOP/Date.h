#pragma once
class Date
{
public:
	Date(int day, int month, int year);
	Date();
	int GetDay();
	int GetMonth();
	int GetYear();
	Date GetDifference(Date otherDate);
	int GetDayCount();
	bool IsEearlier(Date otherDate);
private:
	int day;
	int month;
	int year;
};

