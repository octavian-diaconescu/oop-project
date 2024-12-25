#include "Category.hpp"
#include <iostream>
#include <string>
using namespace std;
Category::Category() : name("empty") {}

Category::Category(const std::string& Name): name(Name){}

// std::string Category::Name() const {
//   return name;
// }

// Category& Category::operator=(const Category& other){
//   if(this != &other){
//     this->name = other.name;
//   }
//   return *this;
// }
//
// Category::Category(const Category& other){
//   name = other.name;
// }

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
