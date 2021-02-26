#pragma once
#include "Member.h"
#include "User.h"
#include <vector>
#include <fstream>
class FileWorker
{
public:
	static vector<Member> GetMembersFromFile(ifstream file_in);
	static vector<User> GetUsersFromFile(ifstream file_in);
	static void WriteMembersToFile(ofstream file_out, vector<Member> members);
	static void WriteUsersToFile(ofstream file_out, vector<User> users);
private:
	FileWorker() {}
	
};

