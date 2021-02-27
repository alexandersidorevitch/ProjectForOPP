#include "Menu.h"
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include "Member.h"
#include "FileWorker.h"
#include "Administrator.h"
using namespace std;

void Menu::RunMemberMenu()
{
	setlocale(0, "");

	string userFileName, memberFileName;
	cout << "������� ��� �����, ��� �������������� ������������ (�� ��������� members.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, userFileName);
	memberFileName = memberFileName.empty() ? "members.txt" : memberFileName;
	
	vector<Member> members = FileWorker::GetMembersFromFile(memberFileName);
	bool exitMenu = true;
	while (exitMenu)
	{
		system("cls");
		cout << "1. �������� ���� ������" << endl;
		cout << "2. ����� �� �.�.�." << endl;
		cout << "3. ����������" << endl;
		cout << "4. ������ �������������� �������" << endl;
		cout << "5. ������ �������������� �������" << endl;
		cout << "6. �����" << endl;
		int choose = GetNumber();
		system("cls");
		switch (choose)
		{
		case 1:
		{
			Member::PrintAsTable(members);
		}
		break;
		case 2:
		{
			cout << "������� ��� ��� ������: " << endl;
			string name;
			getline(cin, name);
			Member::FindByFIO(members, name);
		}
		break;
		case 3:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "���� ������������:" << endl;
				cout << "1. �� �����" << endl;
				cout << "2. �� �����" << endl;
				cout << "3. �� ���� ��������" << endl;
				cout << "4. �����" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
					cout << "�������������� �� �����;" << endl;
					Member::SortByFunc(members, [](Member memberFirst, Member memberSecond) {return memberFirst.GetFullName() < memberSecond.GetFullName(); });
					Member::PrintAsTable(members);
					break;
				case 2:
					cout << "�������������� �� �����;" << endl;
					Member::SortByFunc(members, [](Member memberFirst, Member memberSecond) {return memberFirst.GetPlaceByResults() < memberSecond.GetPlaceByResults(); });
					Member::PrintAsTable(members);
					break;
				case 3:
					cout << "�������������� �� ���� ��������;" << endl;
					Member::SortByFunc(members, [](Member memberFirst, Member memberSecond) {return memberFirst.GetDate() < memberSecond.GetDate(); });
					Member::PrintAsTable(members);
					break;
				case 4:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 4:
		{
			cout << "������ �������������� �������:" << endl << endl;
			Member::PrintFirstThreePlaceFrommAllInstrument(members);
		}
		break;
		case 5:
		{
			cout << "������ �������������� �������:" << endl << endl;
			Member::PrintYougestWinner(members);
		}
		break;
		case 6:
			exitMenu = false;
			break;
		default:
			cout << "������ ������ ���� - ���!" << endl;
			break;

		}
		system("pause");
	}
}

void Menu::RunAdminMenu()
{
	setlocale(0, "");
	string userFileName, memberFileName;
	cout << "������� ��� �����, ��� �������������� ������������ (�� ��������� users.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, userFileName);
	userFileName = userFileName.empty() ? "users.txt" : userFileName;
	cout << "������� ��� �����, ��� �������������� ��������� (�� ��������� members.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, memberFileName);
	memberFileName = memberFileName.empty() ? "members.txt" : memberFileName;

	Administrator admin(userFileName, memberFileName);
	bool exitMenu = true;
	while (exitMenu)
	{
		system("cls");
		cout << "1. ���������� �������� �������� ������������:" << endl;
		cout << "2. ������ � ������ ������:" << endl;
		cout << "3. ������ � �������:" << endl;
		cout << "4. �����" << endl;
		int choose = GetNumber();
		system("cls");
		switch (choose)
		{
		case 1:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "���������� �������� �������� ������������:" << endl;
				cout << "1. ����������� ��� ������� ������" << endl;
				cout << "2. �������� ������� ������" << endl;
				cout << "3. ��������������� ������� ������" << endl;
				cout << "4. ������� ������� ������" << endl;
				cout << "5. �����" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.ViewUsers();
				}
				break;
				case 2:
				{
					User user;
					user.Input();
					admin.AppendUser(user);
				}
				break;
				case 3:
				{
					cout << "������� ���������� ����� ������������:" << endl;
					int number = GetNumber() - 1;
					admin.EditUser(number);
				}
				break;
				case 4:
				{
					cout << "������� ���������� ����� ������������:" << endl;
					int number = GetNumber() - 1;
					admin.DeleteUser(number);
				}
				break;
				case 5:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 2:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "������ � �������:" << endl;
				cout << "1. ������� ����" << endl;
				cout << "2. ������� ����" << endl;
				cout << "3. ������� ����" << endl;
				cout << "4. �����" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.CreateFile(fileName);
				}
				break;
				case 2:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.OpenFile(fileName);
				}
				break;
				case 3:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.RemoveFile(fileName);
				}
				break;
				case 4:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 3:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "������ � �������: " << endl;
				cout << "1. �������� ���� ������" << endl;
				cout << "2. �������� ������" << endl;
				cout << "3. ������� ������" << endl;
				cout << "4. ������������� ������" << endl;
				cout << "5. �����" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.ViewMembers();
				}
				break;
				case 2:
				{
					Member member;
					member.Input();
					admin.AppendMember(member);
				}
				break;
				case 3:
				{
					cout << "������� ���������� ����� ������:" << endl;
					int number = GetNumber() - 1;
					admin.DeleteMember(number);
				}
				break;
				case 4:
				{
					cout << "������� ���������� ����� ������:" << endl;
					int number = GetNumber() - 1;
					admin.EditMember(number);
				}
				break;
				case 5:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 4:
			exitMenu = false;
			break;
		default:
			cout << "������ ������ ���� - ���!" << endl;
			break;

		}
		system("pause");
	}
}

void Menu::FirstMenu()
{
	setlocale(0, "");
	bool exitMenu = true;
	while (exitMenu)
	{
		cout << "�������� ����:" << endl;
		cout << "1. ������������" << endl;
		cout << "2. �������������" << endl;
		cout << "3. �����" << endl;
		int menuChoose = GetNumber();
		system("cls");
		switch (menuChoose)
		{
		case 1:
			RunMemberMenu();
			break;
		case 2:
			RunAdminMenu();
			break;
		case 3:
			exitMenu = false;
			break;
		default:
			cout << "������ ������ ���� ���!" << endl;
			break;
		}
		system("cls");
	}
}

int Menu::GetNumber()
{
	string num;
	int k;
	while (true)
	{
		getline(cin, num);
		try
		{
			k = stoi(num);
			break;
		}
		catch (const std::exception&)
		{
			cout << "������� ����� �����" << endl;
		}

	}
	return k;
}

bool Menu::isNumber(string s)
{
	for (int a = 0; a < s.length(); a++) {
		if (s[a] != 45) {
			if ((s[a] < 48) || (s[a] > 57))  return false;
		}
	}
	return true;
}


