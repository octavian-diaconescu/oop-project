#pragma once

#include <string>

class Category
{
    std::string name;
public:
    explicit Category(std::string);
    Category& operator=(const Category&);
    Category(const Category&);
    ~Category();
};
