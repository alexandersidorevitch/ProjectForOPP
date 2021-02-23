#pragma once
#include <string>
using namespace std;
class MusicalInstrument
{
public:
	MusicalInstrument(string name);
	string GetName();
private:
	string name;
};

