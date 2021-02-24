#pragma once
#include "Member.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "FileWorker.h"
#include <fstream>
using namespace std;

class Administrator
{
public:
	Administrator();
	void CreateFile(string fileName);
	void OpenFile(string fileName);
	void RemoveFile(string fileName);
	void ViewData();
	void AppendMember(Member member);
	void DeleteMember(int index);
	void EditMember(int index);
private:
	
	bool IsExists(string fileName);
	ifstream file_in;
	ofstream file_out;
	vector<Member> members;
	string fileName;
};

