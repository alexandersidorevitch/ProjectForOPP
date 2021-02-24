#include "Administrator.h"

Administrator::Administrator()
{
	file_in.open("asn.txt");
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

	file_in.open(fileName);
	file_out.open(fileName);

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
void Administrator::PrintTable()
{
	int maxLenghtFullName = 0, maxLenghtSex = 0, maxLenght;
	for (auto member : members) {
		if (maxLenghtFullName < member.GetFullName().length())
		{
			maxLenghtFullName = member.GetFullName().length();
		}
	}
}
bool Administrator::IsExists(string fileName)
{
	ifstream fin(fileName);
	bool isExists = fin.is_open();
	fin.close();
	return isExists;
}
