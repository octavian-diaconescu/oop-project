#include <iostream>
#include "User.hpp"

#include <fstream>
#include <utility>

using namespace std;
int User::cnt = 0;

User::User() : id(cnt), fullName(" "), birthDate(" "), preferedLanguage(" "){}

User::User(string name, string bdate, string lang): id(cnt), fullName(std::move(name)), birthDate(std::move(bdate)), preferedLanguage(std::move(lang)){}

User::User(const User& other)
{
        fullName = other.fullName;
        birthDate = other.birthDate;
        preferedLanguage = other.preferedLanguage;
        id = other.id;
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        fullName = other.fullName;
        birthDate = other.birthDate;
        preferedLanguage = other.preferedLanguage;
        id = other.id;
    }
    return *this;
}

void User::readFile(ifstream&fin, vector<User>& us)
{
    User user;
    while (fin >> user)
    {
        user.id = cnt++;
        us.push_back(user);
    }
}
ifstream& operator>>(ifstream& fin, User& users)
{
    fin >> users.fullName >> users.birthDate >> users.preferedLanguage;
    return fin;
}

ostream& operator<<(ostream& os, const User& user)
{
    os << user.id << " " << user.fullName << ' ' << user.birthDate << ' ' << user.preferedLanguage;
    return os;
}

string User::getFullName() const
{
    return fullName;
}
string User::getBirthDate() const
{
    return birthDate;
}
string User::getPreferedLanguage() const
{
    return preferedLanguage;
}
void User::setFullName(const string name)
{
    fullName = name;
}
void User::setBirthDate(const string bdate)
{
    birthDate = bdate;
}
void User::setPreferedLanguage(const string lang)
{
    preferedLanguage = lang;
}

User::~User()
{
    fullName.clear();
    birthDate.clear();
    preferedLanguage.clear();
}