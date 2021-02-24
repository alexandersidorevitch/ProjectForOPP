#pragma once
#include <string>
using namespace std;
class MusicalInstrument
{
public:
	MusicalInstrument(string name);
	MusicalInstrument();
	string GetName() const;

	friend ostream& operator<<(ostream& out, const MusicalInstrument& instrument);
	friend istream& operator>>(istream& in, MusicalInstrument& instrument);
private:
	string name;
};

