#include "FileWorker.h"

vector<Member> FileWorker::GetMembersFromFile(ifstream& file_in)
{
	vector<Member> members;

	if (not file_in.is_open())
	{
		cout << "������ ����� �� ����������";
		return members;
	}
	while (!file_in.eof())
	{
		Member member;
		file_in >> member;
		members.push_back(member);
	}
	return members;
}

vector<User> FileWorker::GetUsersFromFile(ifstream& file_in)
{
	vector<User> users;

	if (not file_in.is_open())
	{
		cout << "������ ����� �� ����������";
		return users;
	}
	int usersCount;
	string usersCountStr;
	while(!file_in.eof())
	{
		User user;
		file_in >> user;
	}
	return users;
}


void FileWorker::WriteMembersToFile(ofstream& file_out, vector<Member> members)
{
	
	if (not file_out.is_open())
	{
		cout << "������ ����� �� ����������";
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

void FileWorker::WriteUsersToFile(ofstream& file_out, vector<User> users)
{
	if (not file_out.is_open())
	{
		cout << "������ ����� �� ����������";
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

void FileWorker::Clear(ofstream& file_out)
{
	file_out.clear();
}



