#include "Category.hpp"
#include <iostream>
#include <string>
#include <utility>
using namespace std;
Category::Category() : name("empty") {}

Category::Category(std::string  Name): name(std::move(Name)){}

istream& operator>>(istream& in, Category& cat) {
  in >> cat.name;
  return in;
}

ostream& operator<<(ostream& out, const Category& cat) {
  out << cat.name;
  return out;
}

bool operator<(const Category &obj1, const Category &obj2) {
  return obj1.name < obj2.name;
}
