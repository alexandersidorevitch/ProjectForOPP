#include "Administrator.h"

Administrator::Administrator()
{

}
Administrator::Administrator(string userFileName, string memberFileName)
{
	this->memberFileName = memberFileName;
	this->userFileName = userFileName;

	//file_in.open(userFileName);
	users = FileWorker::GetUsersFromFile(userFileName);

	members = FileWorker::GetMembersFromFile(memberFileName);

}
void Administrator::CreateFile(string fileName)
{
	if (FileWorker::IsExists(fileName))
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
	members = FileWorker::GetMembersFromFile(fileName);
	cout << "���� ������" << endl;
}
void Administrator::RemoveFile(string fileName)
{
	if (not FileWorker::IsExists(fileName))
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

void Administrator::ViewMembers()
{
	Member::PrintAsTable(members);
}

void Administrator::AppendMember(Member member)
{

	Member::Append(members, member);
	FileWorker::WriteMembersToFile(memberFileName, members);

}

void Administrator::DeleteMember(int index)
{

	Member::Remove(members, index);
	FileWorker::WriteMembersToFile(memberFileName, members);


}

void Administrator::EditMember(int index)
{

	Member::Edit(members, index);
	FileWorker::WriteMembersToFile(memberFileName, members);


}

void Administrator::AppendUser(User user)
{

	User::Append(users, user);
	FileWorker::WriteUsersToFile(userFileName, users);
}

void Administrator::DeleteUser(int index)
{

	User::Remove(users, index);
	FileWorker::WriteUsersToFile(userFileName, users);
}

void Administrator::EditUser(int index)
{

	User::Edit(users, index);
	FileWorker::WriteUsersToFile(userFileName, users);
}

void Administrator::ViewUsers()
{
	User::PrintAsTable(users);
}




