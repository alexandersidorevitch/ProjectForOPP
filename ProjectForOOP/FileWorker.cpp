#include "FileWorker.h"
#define cin file_in
vector<Member> FileWorker::GetMembersFromFile(string fileName)
{
    vector<Member> members;
    ifstream cin(fileName);
    if (not cin.is_open())
    {
        cout << "Такого файла не существует";
        return vector<Member>();
    }

    int memberCount;
    cin >> memberCount;
    string name, sex, city;
    int placeByResult;
    int day, month, year;
    string musicalInstrumentName;

    for (size_t i = 0; i < memberCount; i++)
    {
        getline(cin, name);
        getline(cin, sex);
        cin >> day >> month >> year;
        cin.ignore();
        getline(cin, city);
        getline(cin, musicalInstrumentName);
        cin >> placeByResult;

        Date date(day, month, year);
        MusicalInstrument musicalInstrument(musicalInstrumentName);
        Member member(name, sex, date, city, musicalInstrument, placeByResult);
        members.push_back(member);
    }

    return members;
}
