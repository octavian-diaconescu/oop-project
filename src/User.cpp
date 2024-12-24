#include <iostream>
#include <Watchlist.hpp>
#include "User.hpp"
using namespace std;


User::User(const User& other)
{
        fullName = other.fullName;
        birthDate = other.birthDate;
        preferedLanguage = other.preferedLanguage;
        watchlist = other.watchlist;
}

User& User::instance()
{
    return uniqueInstance;
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        fullName = other.fullName;
        birthDate = other.birthDate;
        preferedLanguage = other.preferedLanguage;
        watchlist = other.watchlist;
    }
    return *this;
}
void User::registerUser(User& other)
{
    cout << "Please enter your full name: ";
    getline(cin, other.fullName);
    cout << "Please enter your birth date:(yyyy.mm.dd) ";
    cin >> other.birthDate;
    cout << "Please enter your prefered language:(EN, FR, RO, etc.) ";
    cin >> other.preferedLanguage;
    cout << "Please choose a username:(must not incluse spaces) ";
    cin >> other.username;
}
// void User::readFile(ifstream&fin, vector<User>& us)
// {
//     User user;
//     while (fin >> user)
//     {
//         user.id = cnt++;
//         us.push_back(user);
//     }
// }

// ifstream& operator>>(ifstream& fin, User& users)
// {
//     fin >> users.fullName >> users.birthDate >> users.preferedLanguage;
//     return fin;
// }
//
istream& operator>>(istream& is, User& user)
{
    is >> user.fullName >> user.birthDate >> user.preferedLanguage;
    return is;
}
ostream& operator<<(ostream& os, const User& user)
{
    os << user.fullName << " " <<  user.birthDate << " " << user.preferedLanguage << " " << user.username << endl;
    return os;
}
User User::uniqueInstance(0);

User::~User()
{
    fullName.clear();
    birthDate.clear();
    preferedLanguage.clear();
    watchlist.clear();
}