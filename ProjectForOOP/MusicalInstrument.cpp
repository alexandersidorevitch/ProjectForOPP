#include "MusicalInstrument.h"
#include <string>
#include <iostream>
using namespace std;
MusicalInstrument::MusicalInstrument(string name)
{
	this->name = name;
}

MusicalInstrument::MusicalInstrument()
{
	MusicalInstrument::MusicalInstrument("\0");
}

string MusicalInstrument::GetName() const
{
	return name;
}

ostream& operator<<(ostream& out, const MusicalInstrument& instrument)
{
	out << instrument.GetName();
	return out;
}

istream& operator>>(istream& in, MusicalInstrument& instrument)
{
	getline(in, instrument.name);
	return in;
}
