#include "Category.hpp"
#include <iostream>
#include <string>

Category::Category(std::string Name): name(Name){};
Category& Category::operator=(const Category& other){
  if(this != &other){
    this->name = other.name;
  }
};

Category::Category(const Category& other){
  name = other.name;
}

Category::~Category(){
  name.clear();
}