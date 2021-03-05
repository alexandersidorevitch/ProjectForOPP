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
	void create_file(string fileName);
	void open_file(string fileName);
	void remove_file(string fileName);
	void view_members();
	void append_member(HostelResidents member);
	void delete_member(int index);
	void edit_member(int index);
	void AppendUser(User member);
	void delete_user(int index);
	void edit_user(int index);
	void view_users();
private:
	
	vector<HostelResidents> members;
	vector<User> users;
	string memberFileName;
	string userFileName;
};

