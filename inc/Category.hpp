#pragma once
#include <string>

class Category {
    std::string name;

public:
    Category();

    explicit Category(std::string);

    friend std::istream &operator>>(std::istream &, Category &);

    friend std::ostream &operator<<(std::ostream &, const Category &);

    friend bool operator<(const Category &, const Category &);

    Category &operator=(const Category &) = default;

    Category(const Category &) = default;

    ~Category() = default;
};
