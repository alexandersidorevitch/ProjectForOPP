#include <iostream>
#include <vector>
#include <time.h>
#include "Administrator.h"
#include "Date.h"
#include "Member.h"
using namespace std;


int main()
{
	Member s("asalos", "1", Date(1, 2, 2012), "qw","+375292502017", MusicalInstrument("sosi"), 4);
	vector<Member> members;
	members.push_back(s);
	members.push_back(Member("ttttttt", "женский", Date(1, 2, 2012), "qhfgsdhghsdw", "+375292502017", MusicalInstrument("sosi"), 2));
	members.push_back(Member("asalo", "мужской", Date(1, 2, 2000), "qw", "+375292502017",MusicalInstrument("sosi"), 1));
	members.push_back(Member("d", "1", Date(22, 2, 2012), "qw", "+375292502017",MusicalInstrument("sosi"), 3));
	Member::PrintYougestWinner(members);
	cout << endl;
	Member::PrintAsTable(members);
	cout << endl;
	Member::PrintFirstThreePlaceFrommAllInstrument(members);
	cout << endl;
	Member::FindByFIO(members, "укенгшщшорпа");
}
