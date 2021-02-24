#include "Administrator.h"

Administrator::Administrator()
{

}
void Administrator::CreateFile(string fileName)
{
	if (IsExists(fileName))
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
void Administrator::OpenFile(string fileName)
{
	if (file_in.is_open())
	{
		file_in.close();
		file_out.close();
	}

	this->fileName = fileName;
	file_in.open(fileName);
	file_out.open(fileName, ios::app);
	members = FileWorker:: GetMembersFromFile(file_in);
	cout << "Файл открыт" << endl;
}
void Administrator::RemoveFile(string fileName)
{
	if (not IsExists(fileName))
	{
		cout << "Такого файла нет" << endl;
	}
	else
	{
		if (this->fileName == fileName)
		{
			file_in.close();
			file_out.close();
		}
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

void Administrator::ViewData()
{
	if (file_in.is_open())
	{
		Member::PrintAsTable(members);
	}
	else
	{
		cout << "Нужно открыть файл!" << endl;
	}
}

void Administrator::AppendMember(Member member)
{
	if (file_in.is_open())
	{
		Member::Append(members, member);
		FileWorker::Clear(file_out);
		FileWorker::WriteMembersToFile(file_out, members);
	}
	else
	{
		cout << "Нужно открыть файл!" << endl;
	}
}

void Administrator::DeleteMember(int index)
{
	if (file_in.is_open())
	{
		Member::Delete(members, index);
		FileWorker::Clear(file_out);
		FileWorker::WriteMembersToFile(file_out, members);
	}
	else
	{
		cout << "Нужно открыть файл!" << endl;
	}
}

void Administrator::EditMember(int index)
{
	if (file_in.is_open())
	{
		Member::Edit(members, index);
		FileWorker::Clear(file_out);
		FileWorker::WriteMembersToFile(file_out, members);

	}
	else
	{
		cout << "Нужно открыть файл!" << endl;
	}
}



bool Administrator::IsExists(string fileName)
{
	ifstream fin(fileName);
	bool isExists = fin.is_open();
	fin.close();
	return isExists;
}
