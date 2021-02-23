#include "Member.h"

Member::Member(string name, string sex, Date date, string city, MusicalInstrument musicalInstrument, int placeByResult)
{
	this->name = name;
	this->sex = sex;
	this->date = date;
	this->city = city;
	this->musicalInstrument = musicalInstrument;
	this->placeByResult = placeByResult;
}
