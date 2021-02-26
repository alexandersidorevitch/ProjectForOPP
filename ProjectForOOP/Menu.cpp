#include "Menu.h"
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include "Member.h"
#include "FileWorker.h"
#include "Administrator.h"
using namespace std;

void Menu::RunUserMenu()
{
	setlocale(0, "");
	ifstream reader("1.txt");
	vector<Member> members = FileWorker::GetMembersFromFile(reader);
	bool exitMenu = true;
	while (exitMenu)
	{
		system("cls");
		cout << "1. Просмотр всех данных" << endl;
		cout << "2. Поиск по Ф.И.О." << endl;
		cout << "3. Сортировка" << endl;
		cout << "4. Первое индивидуальное задание" << endl;
		cout << "5. Второе индивидуальное задание" << endl;
		cout << "6. Выход" << endl;
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
			cout << "Введите имя для поиска: " << endl;
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
				cout << "Меню пользователя:" << endl;
				cout << "1. По имени" << endl;
				cout << "2. По месту" << endl;
				cout << "3. По дате рождения" << endl;
				cout << "4. Назад" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
					cout << "Отсоритрованно по имени;" << endl;
					Member::SortByFunc(members, [](Member memberFirst, Member memberSecond) {return memberFirst.GetFullName() < memberSecond.GetFullName(); });
					Member::PrintAsTable(members);
					break;
				case 2:
					cout << "Отсоритрованно по месту;" << endl;
					Member::SortByFunc(members, [](Member memberFirst, Member memberSecond) {return memberFirst.GetPlaceByResults() < memberSecond.GetPlaceByResults(); });
					Member::PrintAsTable(members);
					break;
				case 3:
					cout << "Отсоритрованно по дате рождения;" << endl;
					Member::SortByFunc(members, [](Member memberFirst, Member memberSecond) {return memberFirst.GetDate() < memberSecond.GetDate(); });
					Member::PrintAsTable(members);
					break;
				case 4:
					exitSubMenu = false;
					break;
				default:
					cout << "Такого пункта меню - нет!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 4:
		{
			cout << "Первое индивидуальное задание:" << endl << endl;
			Member::PrintFirstThreePlaceFrommAllInstrument(members);
		}
		break;
		case 5:
		{
			cout << "Второе индивидуальное задание:" << endl << endl;
			Member::PrintYougestWinner(members);
		}
		break;
		case 6:
			exitMenu = false;
			break;
		default:
			cout << "Такого пункта меню - нет!" << endl;
			break;

		}
		system("pause");
	}
}

void Menu::RunAdminMenu()
{
	setlocale(0, "");
	string userFileName, memberFileName;
	cout << "Введите имя файла, где распологаються пользователи (по умолчанию user.txt)" << endl;
	getline(cin, userFileName);
	cout << "Введите имя файла, где распологаються участники (по умолчанию member.txt)" << endl;
	getline(cin, memberFileName);

	Administrator admin(userFileName, memberFileName);
	bool exitMenu = true;
	while (exitMenu)
	{
		system("cls");
		cout << "1. Управление учетными записями пользователя:" << endl;
		cout << "2. Работа с файлом данных:" << endl;
		cout << "3. Работа с данными:" << endl;
		cout << "4. Выход" << endl;
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
				cout << "Управление учетными записями пользователя:" << endl;
				cout << "1. Просмотреть все учетные записи" << endl;
				cout << "2. Добавить учетную запись" << endl;
				cout << "3. Отредактировать учетную запись" << endl;
				cout << "4. Удалить учетную запись" << endl;
				cout << "5. Назад" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.ViewData();
				}
				break;
				case 2:
				{
					User user;
					user.Input();
					admin.AppendUser(user);
				}
				case 3:
				{
					cout << "Введите порядковый номер пользователя:" << endl;
					int number = GetNumber();
					admin.EditUser(number);
				}
				break;
				case 4:
				{
					cout << "Введите порядковый номер пользователя:" << endl;
					int number = GetNumber();
					admin.DeleteUser(number);
				}
				break;
				case 5:
					exitSubMenu = false;
					break;
				default:
					cout << "Такого пункта меню - нет!" << endl;
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
				cout << "Работа с файлами:" << endl;
				cout << "1. Создать файл" << endl;
				cout << "2. Открыть файл" << endl;
				cout << "3. Удалить файл" << endl;
				cout << "4. Назад" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					cout << "Введите имя файла:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.CreateFile(fileName);
				}
				break;
				case 2:
				{
					cout << "Введите имя файла:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.OpenFile(fileName);
				}
				case 3:
				{
					cout << "Введите имя файла:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.RemoveFile(fileName);
				}
				break;
				case 4:
					exitSubMenu = false;
					break;
				default:
					cout << "Такого пункта меню - нет!" << endl;
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
				cout << "Работа с данными: " << endl;
				cout << "1. Просмотр всех данных" << endl;
				cout << "2. Добавить запись" << endl;
				cout << "3. Удалить запись" << endl;
				cout << "4. Редактировать запись" << endl;
				cout << "5. Назад" << endl;
				int SubChoose = GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.ViewData();
				}
				break;
				case 2:
				{
					Member member;
					member.Input();
					admin.AppendMember(member);
				}
				case 3:
				{
					cout << "Введите порядковый номер записи:" << endl;
					int number = GetNumber();
					admin.DeleteMember(number);
				}
				case 4:
				{
					cout << "Введите порядковый номер записи:" << endl;
					int number = GetNumber();
					admin.EditMember(number);
				}
				break;
				case 5:
					exitSubMenu = false;
					break;
				default:
					cout << "Такого пункта меню - нет!" << endl;
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
			cout << "Такого пункта меню - нет!" << endl;
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
		cout << "Выберите роль:" << endl;
		cout << "1. Пользователь" << endl;
		cout << "2. Администратор" << endl;
		cout << "3. Выход" << endl;
		int menuChoose = GetNumber();
		system("cls");
		switch (menuChoose)
		{
		case 1:
			RunUserMenu();
			break;
		case 2:
			RunAdminMenu();
			break;
		case 3:
			exitMenu = false;
			break;
		default:
			cout << "Такого пункта меню нет!" << endl;
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
			cout << "Введите целое число" << endl;
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


