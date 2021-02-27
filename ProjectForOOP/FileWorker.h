#pragma once
#include "Member.h"
#include "User.h"
#include <vector>
#include <fstream>
class FileWorker
{
public:
	//static vector<Member> GetMembersFromFile(ifstream& file_in);
	static vector<Member> GetMembersFromFile(string fileName);
	static vector<User> GetUsersFromFile(string fileName);
	static void WriteMembersToFile(string fileName, vector<Member> members);
	static void WriteUsersToFile(string fileName, vector<User> users);
	static bool IsExists(string fileName);
private:
	FileWorker() {}
	
};

