#pragma once

#include <string>
#include <vector>
class Actor
{
    std::string name;
    std::string nationality;
    std::string birthDate;//yyyy.mm.ll
    std::string birthCity;
public:
    Actor();
    Actor(std::string, std::string, std::string, std::string);
    std::string getName();
    std::string getNationality();
    std::string getBirthDate();
    std::string getBirthCity();
    Actor(const Actor&);
    friend std::ifstream& operator>>(std::ifstream&, Actor&);
    friend std::ostream& operator<<(std::ostream&, const Actor&);
    static void readFile(std::ifstream&, std::vector<Actor>&);
    ~Actor();
};


