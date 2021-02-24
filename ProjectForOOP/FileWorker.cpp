#include "FileWorker.h"

vector<Member> FileWorker::GetMembersFromFile(ifstream file_in)
{
	vector<Member> members;

	if (not file_in.is_open())
	{
		cout << "Такого файла не существует";
		return members;
	}
	int memberCount;
	string memberCountStr;
	getline(file_in, memberCountStr);
	memberCount = stoi(memberCountStr);
	for (size_t i = 0; i < memberCount; i++)
	{
		Member member("", "", Date(0, 0, 0), "", MusicalInstrument(""), 1);
		file_in >> member;
	}
	return members;
}


void FileWorker::WriteMembersToFile(ofstream file_out, vector<Member> members)
{
	for (auto member : members)
	{
		file_out << member;
	}
}

void FileWorker::WriteMembersToFile(string fileName, vector<Member> members)
{
	
}
