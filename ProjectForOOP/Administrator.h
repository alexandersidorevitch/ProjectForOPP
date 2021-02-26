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
	Administrator(string userFileName, string memberFileName);
	void CreateFile(string fileName);
	void OpenFile(string fileName);
	void RemoveFile(string fileName);
	void ViewData();
	void AppendMember(Member member);
	void DeleteMember(int index);
	void EditMember(int index);
	void AppendUser(User member);
	void DeleteUser(int index);
	void EditUser(int index);
private:
	
	bool IsExists(string fileName);
	vector<Member> members;
	vector<User> users;
	string memberFileName;
	string userFileName;
};

