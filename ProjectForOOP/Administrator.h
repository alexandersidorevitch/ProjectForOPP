#pragma once
#include "Member.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Administrator
{
public:
	Administrator();
	void CreateFile(string fileName);
	void OpenFile(string fileName);
	void RemoveFile(string fileName);
private:
	bool IsExists(string fileName);
	ifstream file_in;
	ofstream file_out;
	vector<Member> members;
	string fileName;
};

