#pragma once
class Date
{
public:
	Date(int day, int month, int year);
	int GetDay();
	int GetMonth();
	int GetYear();
private:
	int day;
	int month;
	int year;
};

