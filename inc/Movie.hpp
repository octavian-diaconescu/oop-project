#pragma once

#include <string>
#include <vector>
#include "Category.hpp"
#include "Content.hpp"

class Movie : public Content {
    std::string runtime = "empty"; //hh:mm

public:
    Movie() = default;

    explicit Movie(const std::string &, const std::string &, const std::string &);

    explicit Movie(const std::string&, const std::string&,const std::string &, std::string , const Category&, const std::string&, bool);

    Movie(const Movie &) = default;

    Movie &operator=(const Movie &) = default;

    ~Movie() override = default;

    friend std::istream &operator>>(std::istream &, Movie &);

    friend std::ostream &operator<<(std::ostream &, const Movie &);

    static void readFile(std::istream &, std::vector<Movie> &);

    void printInfo() const override;

    void saveInfo( std::ostream & os) const;
};
