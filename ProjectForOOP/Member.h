#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "MusicalInstrument.h"
#include "Date.h"
using namespace std;

class HostelResidents
{
public:
	HostelResidents();
	~HostelResidents();
	HostelResidents(string name, string sex, Date date, string city,string phoneNumber, MusicalInstrument musicalInstrument, int placeByResult);
	string GetFullName();
	string GetSex();
	Date GetDate();
	string GetCity();
	string GetPhoneNumber();
	MusicalInstrument GetMusicalInstrument();
	int GetPlaceByResults();
	void Input();
	static void append(vector<HostelResidents>& members, HostelResidents member);
	static void Remove(vector<HostelResidents>& members, int index);
	static void Edit(vector<HostelResidents>& members, int index);
	static void print_as_table(vector<HostelResidents>& members);
	static void print_as_table(vector<HostelResidents>& members, string verticalDelemitr, char gorizontalDelemitr);
	static void SortByFunc(vector<HostelResidents>& members, bool (*comp)(HostelResidents,HostelResidents));
	static void PrintYougestWinner(vector<HostelResidents>& members );
	static void PrintFirstThreePlaceFrommAllInstrument(vector<HostelResidents>& members );
	static void FindByFIO(vector<HostelResidents>& members , string NameToFind);
	static bool FindSubstring(string mainString, string subString);
	
	friend ostream& operator<<(ostream& out, const HostelResidents& member);
	friend istream& operator>>(istream& in, HostelResidents& member);
private:
	string full_name;
	int settlement_year;
	int room;
	string feedback;
	int entertainment_year;
	string eviction_reason;
	string residence_mark;
};

