#pragma once

#include <string>
#include <vector>
#include "Category.hpp"
#include "Content.hpp"

class Movie : public Content {
    std::string runtime = "empty"; //hh:mm

public:
    friend class MovieBuilder;

    Movie() = default;

    explicit Movie(const std::string &, const std::string &, float);

    Movie(const Movie &) = default;

    Movie &operator=(const Movie &) = default;

    [[nodiscard]] std::string getTitle() const override;

    ~Movie() override = default;

    friend std::istream &operator>>(std::istream &, Movie &);

    friend std::ostream &operator<<(std::ostream &, const Movie &);

    static void readFile(std::istream &, std::vector<Movie> &);

    void printInfo() const override;
};
