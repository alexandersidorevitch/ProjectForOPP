#include "Administrator.h"

Administrator::Administrator()
{
	file_in.open("asn.txt");
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
	if (file_in.is_open())
	{
		file_in.close();
		file_out.close();
	}

	file_in.open(fileName);
	file_out.open(fileName);

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
		if (this->fileName == fileName)
		{
			file_in.close();
			file_out.close();
		}
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

bool Administrator::IsExists(string fileName)
{
	ifstream fin(fileName);
	bool isExists = fin.is_open();
	fin.close();
	return isExists;
}
