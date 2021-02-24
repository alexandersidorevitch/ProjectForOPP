#include <iostream>
#include <vector>
#include <time.h>
#include "Administrator.h"
#include "Date.h"
#include "Member.h"
using namespace std;


int main()
{
	/*Member s("b", "1", Date(1, 2, 2012), "qw","+375292502017", MusicalInstrument("sosi"), 2);
	vector<Member> members;
	members.push_back(s);
	members.push_back(Member("Сидоревич Александр Юрьевич", "женский", Date(1, 2, 2012), "qhfgsdhghsdw", "+375292502017", MusicalInstrument("soававаsi"), 2));
	members.push_back(Member("a", "мужской", Date(1, 2, 2012), "qw", "+375292502017",MusicalInstrument("sosi"), 1));
	members.push_back(Member("d", "1", Date(1, 2, 2012), "qw", "+375292502017",MusicalInstrument("sosi"), 3));
	ifstream sr("");
	FileWorker::GetMembersFromFile(sr);
	Member::PrintAsTable(members);*/
	system("chcp 1251");
	system("cls");
	Administrator administartor;
	string fileName = "1.txt";
	//administartor.CreateFile(fileName);
	administartor.OpenFile(fileName);
	Member member;
	member.Input();
	//administartor.AppendMember(member);
	administartor.AppendMember(member);
	administartor.ViewData();
}
