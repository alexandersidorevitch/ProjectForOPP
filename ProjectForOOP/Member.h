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
	static void PrintAsTable(vector<Member>& members);
	static void SortByFunc(vector<Member>& members, bool (*comp)(Member,Member));
	

	//friend ofstream& operator<<(ofstream& out, const Member& member);
	//friend ifstream& operator>>(ifstream& in, Member& member);
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

