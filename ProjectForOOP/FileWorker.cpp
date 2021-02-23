#include "FileWorker.h"

vector<Member> FileWorker::GetMembersFromFile(string fileName)
{
    vector<Member> members;
    ifstream file_in(fileName);

    if (not file_in.is_open())
    {
        cout << "Такого файла не существует";
        return vector<Member>();
    }

    int memberCount;
    file_in >> memberCount;
    string name, sex, city;
    int placeByResult;
    int day, month, year;
    string musicalInstrumentName;

    for (size_t i = 0; i < memberCount; i++)
    {
        getline(file_in, name);
        getline(file_in, sex);
        file_in >> day >> month >> year;
        file_in.ignore();
        getline(file_in, city);
        getline(file_in, musicalInstrumentName);
        file_in >> placeByResult;

        Date date;
        MusicalInstrument musicalInstrument(musicalInstrumentName);
        Member member(name, sex, date, city, musicalInstrument, placeByResult);
        members.push_back(member);
    }
    file_in.close();
    return members;
}

void FileWorker::WriteMembersToFile(string fileName, vector<Member> members)
{
    ofstream file_out(fileName);
    for (size_t i = 0; i < members.size(); i++)
    {
        file_out << members[i].GetFullName() << endl;
        file_out << members[i].GetSex() << endl;
        file_out << members[i].GetDate(). ;
    }
}
