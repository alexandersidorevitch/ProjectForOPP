#pragma once
#include "Member.h"
#include <vector>
class FileWorker
{
public:
	vector<Member> GetMembersFromFile(string fileName);
	void WriteMembersToFile(string fileName, vector<Member> members);
private:
	FileWorker() {}
	
};

