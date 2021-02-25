
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User();
	User(string Login, string Password);

	string GetLogin() const;
	string GetPassword() const;
	void Input();
	static void Append(vector<User>& users, User user);
	static void Delete(vector<User>& users, int index);
	static void Edit(vector<User>& users, int index);
	static void PrintAsTable(vector<User>& members);
	static void PrintAsTable(vector<User>& members, char verticalDelemitr, char gorizontalDelemitr);

	friend ostream& operator<<(ostream& out, const User& user);
	friend istream& operator>>(istream& in, User& user);


private:
	string Login;
	string Password;
};

