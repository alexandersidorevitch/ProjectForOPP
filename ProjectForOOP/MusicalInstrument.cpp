#include "MusicalInstrument.h"
#include <string>
using namespace std;
MusicalInstrument::MusicalInstrument(string name)
{
	this->name = name;
}

MusicalInstrument::MusicalInstrument()
{
	MusicalInstrument::MusicalInstrument("");
}

string MusicalInstrument::GetName()
{
	return name;
}
