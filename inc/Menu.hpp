#pragma once
class Menu
{
    int data;
    explicit Menu(const int d = 0) : data(d) {}
    static Menu uniqueInstance;
    Menu(const Menu&) = default;
    Menu& operator=(const Menu&) = default;
public:
    static Menu& instance();
    ~Menu() = default;
    static void run();
};