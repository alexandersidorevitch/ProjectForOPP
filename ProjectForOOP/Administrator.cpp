#include "Administrator.h"

Administrator::Administrator()
{

}
Administrator::Administrator(string userFileName, string memberFileName)
{
	this->memberFileName = memberFileName;
	this->userFileName = userFileName;
}
void Administrator::CreateFile(string fileName)
{
	if (IsExists(fileName))
	{
		cout << "���� ��� ����������" << endl;
	}
	else
	{
		ofstream fout(fileName);
		fout.close();
		cout << "���� ������" << endl;
	}
}
void Administrator::OpenFile(string fileName)
{
	ifstream file_in(fileName);
	members = FileWorker::GetMembersFromFile(file_in);
	cout << "���� ������" << endl;
}
void Administrator::RemoveFile(string fileName)
{
	if (not IsExists(fileName))
	{
		cout << "������ ����� ���" << endl;
	}
	else
	{
		if (remove(fileName.c_str()) == -1)
		{
			cout << "���� �� ���������� �������" << endl;
		}
		else
		{
			cout << "���� ������" << endl;
		}
	}
}

void Administrator::ViewData()
{
		Member::PrintAsTable(members);
}

void Administrator::AppendMember(Member member)
{
	ofstream file_out(memberFileName);

	Member::Append(members, member);
	FileWorker::Clear(file_out);
	FileWorker::WriteMembersToFile(file_out, members);

}

void Administrator::DeleteMember(int index)
{
	ofstream file_out(memberFileName);

	Member::Remove(members, index);
	FileWorker::Clear(file_out);
	FileWorker::WriteMembersToFile(file_out, members);


}

void Administrator::EditMember(int index)
{
	ofstream file_out(memberFileName);
	
	Member::Edit(members, index);
	FileWorker::Clear(file_out);
	FileWorker::WriteMembersToFile(file_out, members);


}

void Administrator::AppendUser(User user)
{
	ofstream file_out(userFileName);

	User::Append(users, user);
	FileWorker::Clear(file_out);
	FileWorker::WriteUsersToFile(file_out, users);
}

void Administrator::DeleteUser(int index)
{
	ofstream file_out(userFileName);

	User::Remove(users, index);
	FileWorker::Clear(file_out);
	FileWorker::WriteUsersToFile(file_out, users);
}

void Administrator::EditUser(int index)
{
	ofstream file_out(userFileName);

	User::Edit(users, index);
	FileWorker::Clear(file_out);
	FileWorker::WriteUsersToFile(file_out, users);
}



bool Administrator::IsExists(string fileName)
{
	ifstream fin(fileName);
	bool isExists = fin.is_open();
	fin.close();
	return isExists;
}
