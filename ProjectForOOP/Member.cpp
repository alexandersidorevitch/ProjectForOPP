#include "Member.h"
#include "FileWorker.h"
Member::Member(string name, string sex, Date date, string city, MusicalInstrument musicalInstrument, int placeByResult)
{
	this->fullName = name;
	this->sex = sex;
	this->date = date;
	this->city = city;
	this->musicalInstrument = musicalInstrument;
	this->placeByResult = placeByResult;
}

string Member::GetFullName()
{
	return fullName;
}

string Member::GetSex()
{
	return sex;
}

Date Member::GetDate()
{
	return date;
}

string Member::GetCity()
{
	return city;
}

string Member::GetPhoneNumber()
{
	return phoneNumber;
}

MusicalInstrument Member::GetMusicalInstrument()
{
	return musicalInstrument;
}

int Member::GetPlaceByResults()
{
	return placeByResult;
}

ostream& operator<<(ostream& out, const Member& member)
{
	out << member.fullName << endl;
	out << member.sex << endl;
	out << member.date <<endl;
	out << member.city << endl;
	out << member.musicalInstrument << endl;
	out << member.placeByResult << endl;
	return out;
}

istream& operator>>(istream& in, Member& member)
{
	string placeByResultStr;
	getline(in, member.fullName);
	getline(in, member.sex);
	in >> member.date;
	getline(in, member.city);
	in >> member.musicalInstrument;
	getline(in, placeByResultStr);
	member.placeByResult = stoi(placeByResultStr);
	return in;
}
//ifstream& operator>>(ifstream& in, Member& member)
//{
//	string placeByResultStr;
//	getline(in, member.fullName);
//	getline(in, member.sex);
//	in >> member.date;
//	getline(in, member.city);
//	in >> member.musicalInstrument;
//	getline(in, placeByResultStr);
//	member.placeByResult = stoi(placeByResultStr);
//	return in;
//}
