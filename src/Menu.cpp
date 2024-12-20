#include <Menu.hpp>
#include <User.hpp>
#include <iostream>
Menu Menu::uniqueInstance(0);
using namespace std;
Menu& Menu::instance(){return uniqueInstance;}

void Menu::run(){
    User& user = User::instance();
    User::registerUser(user);
    cout << user;
    cout << "Menu::run()" << endl;
}