#include "MusicalInstrument.h"
#include <string>
using namespace std;
MusicalInstrument::MusicalInstrument(string name)
{
	this->name = name;
}

string MusicalInstrument::GetName()
{
	return name;
}
