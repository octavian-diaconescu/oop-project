#include "Menu.hpp"
#include <iostream>
using namespace std;

int main()
{
    Menu &menu = Menu::instance();
    menu.run();
    return 0;
}