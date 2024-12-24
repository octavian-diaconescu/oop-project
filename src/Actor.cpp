#include <Actor.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


Actor::Actor() : name(" "), nationality(" "), birthDate(" "), birthCity(" ") {};

Actor::Actor(std::string Name, std::string Nationality, std::string bdate, std::string bcity) : name(Name), nationality(Nationality), birthDate(bdate), birthCity(bcity){};

std::ifstream& operator>>(std::ifstream& fin, Actor& act)
{
  fin >> act.name >> act.nationality >> act.birthDate >> act.birthCity;
  return fin;
}

void Actor::readFile(std::ifstream& fin, std::vector<Actor>& act)
{
  Actor temp;
  while(fin >> temp)
     act.push_back(temp);
}

std::ostream& operator<<(std::ostream& out, const Actor& act)
{
  out << "Name: " << act.name << "|" << "Nationality: " << act.nationality << "|" << "Birth date: " << act.birthDate << "|" << "Birth city: " << act.birthCity;
  return out;
}

std::string Actor::getName(){
  return name;
}
std::string Actor::getNationality(){
  return nationality;
}
std::string Actor::getBirthDate(){
  return birthDate;
}
std::string Actor::getBirthCity(){
  return birthCity;
}
Actor::Actor(const Actor& other){
     this->name = other.name;
     this->nationality = other.nationality;
     this->birthDate = other.birthDate;
     this->birthCity = other.birthCity;
}

Actor::~Actor(){
  name.clear();
  nationality.clear();
  birthDate.clear();
  birthCity.clear();
}