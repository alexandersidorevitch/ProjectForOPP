#pragma once
class Date
{
public:
	Date(int day, int month, int year);
	Date(int dayCount);
	Date();
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	int GetDifferenceInDays(Date otherDate);
	int GetDayCount();
	bool IsEearlier(Date otherDate);
	friend ostream& operator<<(ostream& out, const Date& p);
	int day;
private:
	void GD(double jd);
	bool IsLeapYear();
	int month;
	int year;
};

