#pragma once
#include "Member.h"
#include "User.h"
#include <vector>
#include <fstream>
class FileWorker
{
public:
	//static vector<Member> GetMembersFromFile(ifstream& file_in);
	static vector<HostelResidents> get_members_from_file(string fileName);
	static vector<User> GetUsersFromFile(string fileName);
	static void write_members_to_file(string fileName, vector<HostelResidents> members);
	static void WriteUsersToFile(string fileName, vector<User> users);
	static bool is_exists(string fileName);
private:
	FileWorker() {}
	
};

