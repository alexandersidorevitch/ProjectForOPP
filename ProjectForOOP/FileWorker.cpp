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
		Member member("", "", Date(0, 0, 0), "", "", MusicalInstrument(""), 1);
		file_in >> member;
	}
	return members;
}

vector<User> FileWorker::GetUsersFromFile(ifstream file_in)
{
	vector<User> users;

	if (not file_in.is_open())
	{
		cout << "Такого файла не существует";
		return users;
	}
	int usersCount;
	string usersCountStr;
	getline(file_in, usersCountStr);
	usersCount = stoi(usersCountStr);
	for (size_t i = 0; i < usersCount; i++)
	{
		User user("","");
		file_in >> user;
	}
	return users;
}


void FileWorker::WriteMembersToFile(ofstream file_out, vector<Member> members)
{
	if (not file_out.is_open())
	{
		cout << "Такого файла не существует";
	}
	else
	{
		file_out << members.size()<<endl;
		for (auto member : members)
		{
			file_out << member<<endl;
		}
	}
}

void FileWorker::WriteUsersToFile(ofstream file_out, vector<User> users)
{
	if (not file_out.is_open())
	{
		cout << "Такого файла не существует";
	}
	else
	{
		file_out << users.size() << endl;
		for (auto user : users)
		{
			file_out << user<<endl;
		}
	}
}

