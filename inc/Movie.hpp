#pragma once

#include <string>
#include <vector>
#include "Content.hpp"
#include "Actor.hpp"

class Movie : public Content{
    std::string runtime; //hh:mm
    std::vector<Actor> actors;
public:
    Movie();
    Movie(std::string, std::string, float, std::string);
    Movie(const Movie&);
    Movie& operator=(const Movie&);
    std::string getTitle() const override;
    void addActor(Actor);
    ~Movie() override;
    friend std::ifstream& operator>>(std::ifstream&, Movie&);
    friend std::ostream& operator<<(std::ostream&, const Movie&);
    static void readFile(std::ifstream&, std::vector<Movie>&);
};