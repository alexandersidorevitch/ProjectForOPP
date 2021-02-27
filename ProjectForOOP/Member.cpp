#include "Member.h"
#include "FileWorker.h"
#include "Menu.h"
Member::Member()
{
}
Member::Member(string name, string sex, Date date, string city, string phoneNumber, MusicalInstrument musicalInstrument, int placeByResult)
{
	this->fullName = name;
	this->sex = sex;
	this->date = date;
	this->city = city;
	this->musicalInstrument = musicalInstrument;
	this->placeByResult = placeByResult;
	this->phoneNumber = phoneNumber;
}

string Member::GetFullName()
{
	return fullName;
}

string Member::GetSex()
{
	return sex;
}

Date Member::GetDate()
{
	return date;
}

string Member::GetCity()
{
	return city;
}

string Member::GetPhoneNumber()
{
	return phoneNumber;
}

MusicalInstrument Member::GetMusicalInstrument()
{
	return musicalInstrument;
}

int Member::GetPlaceByResults()
{
	return placeByResult;
}

void Member::Input()
{
	cout << "Введите ФИО" << endl;
	getline(cin, fullName);
	cout << "Введите пол" << endl;
	getline(cin, sex);
	cout << "Введите дату в форме 01.01.2001" << endl;
	cin >> date;
	cout << "Введите город" << endl;
	getline(cin, city);
	cout << "Введите номер телефона" << endl;
	getline(cin, phoneNumber);
	cout << "Введите назвние муз.иструмента" << endl;
	cin >> musicalInstrument;
	cout << "Введите место:" << endl;
	placeByResult = Menu::GetNumber();
}

void Member::Append(vector<Member>& members, Member member)
{
	members.push_back(member);
}

void Member::Remove(vector<Member>& members, int index)
{
	if (index < 0 || index >= members.size())
	{
		cout << "Такого порядкого номера нет" << endl;
	}
	else {
		members.erase(members.begin() + index);
		cout << "Запись удалена" << endl;
	}
}

void Member::Edit(vector<Member>& members, int index)
{
	if (index < 0 || index >= members.size())
	{
		cout << "Такого порядкого номера нет" << endl;
	}
	else {
		members[index].Input();
	}

}

void Member::PrintAsTable(vector<Member>& members)
{
	PrintAsTable(members, " | ", '*');
}

void Member::PrintAsTable(vector<Member>& members, string verticalDelemitr, char gorizontalDelemitr)
{
	setlocale(0, "");
	int maxLenghtFullName = 6, maxLenghtSex = 3, maxLenghtDate = 4,
		maxLenghtCity = 5, maxLenghtInstrumentName = 16, maxLenghtPhoneNumber = 14, maxLenghtPlace = 5, maxLenghtIndex = __max(to_string(members.size()).length(), 5);
	for (auto member : members) {
		maxLenghtFullName = __max(member.fullName.length(), maxLenghtFullName);
		maxLenghtSex = __max(member.sex.length(), maxLenghtSex);
		maxLenghtDate = __max(member.date.ToString().length(), maxLenghtDate);
		maxLenghtCity = __max(member.city.length(), maxLenghtCity);
		maxLenghtInstrumentName = __max(member.musicalInstrument.GetName().length(), maxLenghtInstrumentName);
		maxLenghtPhoneNumber = __max(member.phoneNumber.length(), maxLenghtPhoneNumber);
		maxLenghtPlace = __max(to_string(member.placeByResult).length(), maxLenghtPlace);
	}

	int totalLenght = maxLenghtFullName + maxLenghtCity + maxLenghtSex + maxLenghtDate +
		maxLenghtInstrumentName + maxLenghtPhoneNumber + maxLenghtPlace + maxLenghtIndex;
	string line(totalLenght + 23, gorizontalDelemitr);
	cout << line << endl;
	cout << '|' << setw(maxLenghtIndex) << "Номер" << verticalDelemitr
		<< setw(maxLenghtFullName) << "Ф.И.О." << verticalDelemitr
		<< setw(maxLenghtSex) << "Пол" << verticalDelemitr
		<< setw(maxLenghtDate) << "Дата" << verticalDelemitr
		<< setw(maxLenghtCity) << "Город" << verticalDelemitr
		<< setw(maxLenghtInstrumentName) << "Имя инструмента" << verticalDelemitr
		<< setw(maxLenghtPhoneNumber) << "Номер телефона" << verticalDelemitr
		<< setw(maxLenghtPlace) << "Место" << '|' << endl;
	cout << line << endl << endl;
	int index = 1;
	for (auto member : members) {
		cout << '|' << setw(maxLenghtIndex) << index << verticalDelemitr << setw(maxLenghtFullName) << member.fullName << verticalDelemitr
			<< setw(maxLenghtSex) << member.sex << verticalDelemitr
			<< setw(maxLenghtDate) << member.date << verticalDelemitr
			<< setw(maxLenghtCity) << member.city << verticalDelemitr
			<< setw(maxLenghtInstrumentName) << member.musicalInstrument.GetName() << verticalDelemitr
			<< setw(maxLenghtPhoneNumber) << member.phoneNumber << verticalDelemitr
			<< setw(maxLenghtPlace) << member.placeByResult << '|' << endl;
		cout << line << endl;
		index++;
	}
}

void Member::SortByFunc(vector<Member>& members, bool (*comp)(Member, Member))
{
	//[](Member memberFirst, Member memberSecond) {return memberFirst.GetMusicalInstrument().GetName() < memberSecond.GetMusicalInstrument().GetName(); } //Компоратор для сортировки по инструментам
	//[](Member memberFirst, Member memberSecond) {return memberFirst.GetFullName() < memberSecond.GetFullName(); } //Компоратор для сортировки по алфавиту
	//[](Member memberFirst, Member memberSecond) {return memberFirst.GetDate() < memberSecond.GetDate(); } //Компоратор для сортировки по дате рождения
	//[](Member memberFirst, Member memberSecond) {return memberFirst.GetPlaceByResults() < memberSecond.GetPlaceByResults(); } //Компоратор для сортировки по местам
	sort(members.begin(), members.end(), comp);
}

void Member::PrintYougestWinner(vector<Member>& members)
{

	vector<Member> WinnersBeforTwelve;
	for (auto member : members)
	{
		if (member.placeByResult <= 3 and member.date.getDifferenceInDays(Date(24, 2, 2020)) / 365 >= -12)
		{
			WinnersBeforTwelve.push_back(member);
		}
	}
	if (WinnersBeforTwelve.size() == 0)
	{
		cout << "Нету победителей младше 12" << endl;
	}
	else
	{
		Member::SortByFunc(WinnersBeforTwelve, [](Member memberFirst, Member memberSecond) {return memberFirst.GetDate() > memberSecond.GetDate(); });
		Member::PrintAsTable(WinnersBeforTwelve);
	}
}

void Member::PrintFirstThreePlaceFrommAllInstrument(vector<Member>& members)
{
	vector<string> NamesOfInstrumaent;
	for (int i = 0; i < members.size(); i++)
	{
		if (find(NamesOfInstrumaent.begin(), NamesOfInstrumaent.end(), members[i].musicalInstrument.GetName()) == NamesOfInstrumaent.end())
		{
			NamesOfInstrumaent.push_back(members[i].musicalInstrument.GetName());
			vector<Member> WinnersByInstruments;
			for (int j = i; j < members.size(); j++)
			{
				if (members[i].musicalInstrument.GetName() == members[j].musicalInstrument.GetName())
				{
					WinnersByInstruments.push_back(members[j]);
				}
			}
			Member::SortByFunc(WinnersByInstruments, [](Member memberFirst, Member memberSecond) {return memberFirst.GetPlaceByResults() < memberSecond.GetPlaceByResults(); });
			if (WinnersByInstruments.size() > 3)
				WinnersByInstruments.erase(WinnersByInstruments.begin() + 3, WinnersByInstruments.end());
			cout << "Инструмент: " << members[i].musicalInstrument.GetName() << endl;
			Member::PrintAsTable(WinnersByInstruments);
		}
	}

}

void Member::FindByFIO(vector<Member>& members, string NameToFind)
{
	vector<Member> FoundByNameMembers;
	for (auto member : members)
	{
		if (FindSubstring(member.fullName, NameToFind))
			FoundByNameMembers.push_back(member);
	}
	if (FoundByNameMembers.size() == 0)
	{
		cout << "Участников с такими именами не найдено!" << endl;
	}
	else
	{
		Member::SortByFunc(FoundByNameMembers, [](Member memberFirst, Member memberSecond) {return memberFirst.GetFullName() < memberSecond.GetFullName(); });
		Member::PrintAsTable(FoundByNameMembers);
	}

}

bool Member::FindSubstring(string mainString, string subString)
{
	int size;
	if (mainString.size() > subString.size())
		size = subString.size();
	else
		size = mainString.size();
	for (int i = 0; i <= size - 1; i++)
	{
		if (mainString[i] != subString[i])
			return false;
	}
	return true;
}





ostream& operator<<(ostream& out, const Member& member)
{
	out << member.fullName << endl;
	out << member.sex << endl;
	out << member.date << endl;
	out << member.city << endl;
	out << member.phoneNumber << endl;
	out << member.musicalInstrument << endl;
	out << member.placeByResult;
	return out;
}

istream& operator>>(istream& in, Member& member)
{
	string placeByResultStr;
	getline(in, member.fullName);
	getline(in, member.sex);
	in >> member.date;
	getline(in, member.city);
	getline(in, member.phoneNumber);
	in >> member.musicalInstrument;
	getline(in, placeByResultStr);

	member.placeByResult = stoi(placeByResultStr);
	return in;
}

