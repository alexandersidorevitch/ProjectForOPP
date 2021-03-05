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

	members = FileWorker::get_members_from_file(memberFileName);

}
void Administrator::create_file(string fileName)
{
	if (FileWorker::is_exists(fileName))
	{
		cout << "Файл уже существует" << endl;
	}
	else
	{
		ofstream fout(fileName);
		fout.close();
		cout << "Файл создан" << endl;
	}
}
void Administrator::open_file(string fileName)
{
	members = FileWorker::get_members_from_file(fileName);
	cout << "Файл открыт" << endl;
}
void Administrator::remove_file(string fileName)
{
	if (not FileWorker::is_exists(fileName))
	{
		cout << "Такого файла нет" << endl;
	}
	else
	{
		if (remove(fileName.c_str()) == -1)
		{
			cout << "Файл не получилось удалить" << endl;
		}
		else
		{
			cout << "Файл удален" << endl;
		}
	}
}

void Administrator::view_members()
{
	HostelResidents::print_as_table(members);
}

void Administrator::append_member(HostelResidents member)
{

	HostelResidents::append(members, member);
	FileWorker::write_members_to_file(memberFileName, members);

}

void Administrator::delete_member(int index)
{

	HostelResidents::Remove(members, index);
	FileWorker::write_members_to_file(memberFileName, members);


}

void Administrator::edit_member(int index)
{

	HostelResidents::Edit(members, index);
	FileWorker::write_members_to_file(memberFileName, members);


}

void Administrator::AppendUser(User user)
{

	User::Append(users, user);
	FileWorker::WriteUsersToFile(userFileName, users);
}

void Administrator::delete_user(int index)
{

	User::Remove(users, index);
	FileWorker::WriteUsersToFile(userFileName, users);
}

void Administrator::edit_user(int index)
{

	User::Edit(users, index);
	FileWorker::WriteUsersToFile(userFileName, users);
}

void Administrator::view_users()
{
	User::PrintAsTable(users);
}




