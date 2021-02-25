#include "User.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

User::User()
{
}

User::User(string Login, string Password)
{
	this->Login = Login;
	this->Password = Password;
}

string User::GetLogin() const
{
	return this->Login;
}

string User::GetPassword() const
{
	return this->Password;
}

void User::Input()
{
	cout << "Введите Логин" << endl;
	getline(cin, Login);
	cout << "Введите Пароль" << endl;
	getline(cin, Password);
}

void User::Append(vector<User>& users, User user)
{
	users.push_back(user);
}

void User::Delete(vector<User>& users, int index)
{
	if (index < 0 || index >= users.size())
	{
		cout << "Такого порядкого номера нет" << endl;
	}
	else {
		users.erase(users.begin() + index);
		cout << "Запись удалена" << endl;
	}
}

void User::Edit(vector<User>& users, int index)
{
	if (index < 0 || index >= users.size())
	{
		cout << "Такого порядкого номера нет" << endl;
	}
	else {
		users[index].Input();
	}
}

void User::PrintAsTable(vector<User>& users)
{
	PrintAsTable(users, '|', '_');
}

void User::PrintAsTable(vector<User>& users, char verticalDelemitr, char gorizontalDelemitr)
{
	setlocale(0, "");
	int maxLenghtLogin = 5, maxLenghtPassword = 6;
	for (auto user : users) {
		maxLenghtLogin = __max(user.Login.length(), maxLenghtLogin);
		maxLenghtPassword = __max(user.Password.length(), maxLenghtPassword);
	}
	int totalLenght = maxLenghtLogin + maxLenghtPassword ;
	string line(totalLenght + 3, gorizontalDelemitr);
	cout << line << endl;
	cout << verticalDelemitr << setw(maxLenghtLogin) << "Логин" << verticalDelemitr
		<< setw(maxLenghtPassword) << "Пароль" << verticalDelemitr;
	cout << line << endl;
	for (auto user : users) {
		cout << verticalDelemitr << setw(maxLenghtLogin) << user.Login << verticalDelemitr
			<< setw(maxLenghtPassword) << user.Password << verticalDelemitr;
		cout << line << endl;
	}
}


ostream& operator<<(ostream& out, const User& user)
{
	out << user.GetLogin() << endl;
	out << user.GetPassword() << endl;
	return out;
}

istream& operator>>(istream& in, User& user)
{
	string placeByResultStr;
	getline(in, user.Login);
	getline(in, user.Password);
	return in;
}
