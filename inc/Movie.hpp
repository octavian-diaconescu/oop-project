#pragma once
#include <string>
#include <vector>
#include "Category.hpp"
#include "Content.hpp"

class Movie : public Content {
    std::string runtime; //hh:mm

public:
    Movie() : runtime("empty") {}

    explicit Movie(const std::string&, const std::string&,const std::string &, std::string , const Category&, const std::string&, bool);

    friend std::istream &operator>>(std::istream &, Movie &);

    static void readFile(std::istream &, std::vector<Movie> &);

    void printInfo() const override;

    void saveInfo( std::ostream & os) const override;
};
