#pragma once
#include "Member.h"
#include <vector>
#include <fstream>
class FileWorker
{
public:
	static vector<Member> GetMembersFromFile(ifstream file_in);
	static void WriteMembersToFile(ofstream file_out, vector<Member> members);
private:
	FileWorker() {}
	
};

