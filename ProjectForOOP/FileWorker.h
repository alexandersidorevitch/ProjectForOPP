#pragma once
#include "Member.h"
#include <vector>
#include <fstream>
class FileWorker
{
public:
	vector<Member> GetMembersFromFile(string fileName);
	void WriteMembersToFile(string fileName, vector<Member> members);
private:
	FileWorker() {}
	
};

