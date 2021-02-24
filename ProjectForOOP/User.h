
#include <string>
using namespace std;

class User
{
public:
	User();
	User(string Login, string Password);

	string GetLogin() const;
	string GetPassword() const;

	friend ostream& operator<<(ostream& out, const User& user);
	friend istream& operator>>(istream& in, User& user);


private:
	string Login;
	string Password;
};

