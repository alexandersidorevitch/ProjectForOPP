#pragma once
class Date
{
public:
	Date(int day, int month, int year);
	Date();
	int GetDay();
	int GetMonth();
	int GetYear();
private:
	int day;
	int month;
	int year;
};

