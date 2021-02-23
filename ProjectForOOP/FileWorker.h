#pragma once
#include "Member.h"
#include <vector>
#include <fstream>
class FileWorker
{
public:
	static vector<Member> GetMembersFromFile(string fileName);
	static void WriteMembersToFile(string fileName, vector<Member> members);
private:
	FileWorker() {}
	
};

