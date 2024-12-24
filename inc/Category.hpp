#pragma once
#include <string>

class Category {
    std::string name;

public:
    Category();

    explicit Category(const std::string &);

    friend std::istream &operator>>(std::istream &, Category &);

    friend std::ostream &operator<<(std::ostream &, const Category &);

    Category &operator=(const Category &);

    Category(const Category &);

    //[[nodiscard]] std::string Name() const;

    ~Category() = default;
};
