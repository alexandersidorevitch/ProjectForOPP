#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "MusicalInstrument.h"
#include "Date.h"
using namespace std;

class Member
{
public:
	Member();
	Member(string name, string sex, Date date, string city,string phoneNumber, MusicalInstrument musicalInstrument, int placeByResult);
	string GetFullName();
	string GetSex();
	Date GetDate();
	string GetCity();
	string GetPhoneNumber();
	MusicalInstrument GetMusicalInstrument();
	int GetPlaceByResults();
	void Input();
	static void Append(vector<Member>& members, Member member);
	static void Remove(vector<Member>& members, int index);
	static void Edit(vector<Member>& members, int index);
	static void PrintAsTable(vector<Member>& members);
	static void PrintAsTable(vector<Member>& members, string verticalDelemitr, char gorizontalDelemitr);
	static void SortByFunc(vector<Member>& members, bool (*comp)(Member,Member));
	static void PrintYougestWinner(vector<Member>& members );
	static void PrintFirstThreePlaceFrommAllInstrument(vector<Member>& members );
	static void FindByFIO(vector<Member>& members , string NameToFind);
	static bool FindSubstring(string mainString, string subString);
	
	friend ostream& operator<<(ostream& out, const Member& member);
	friend istream& operator>>(istream& in, Member& member);
private:
	string fullName;
	string sex;
	Date date;
	string city;
	string phoneNumber;
	MusicalInstrument musicalInstrument;
	int placeByResult;
};

