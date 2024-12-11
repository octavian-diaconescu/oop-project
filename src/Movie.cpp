#include "Movie.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

Movie::Movie() : runtime(" "), actors(__null)
{
};

Movie::Movie(string rt, string Title, float R, string ageR) : Content(Title, R, ageR), runtime(rt), actors(__null)
{
};

Movie::Movie(const Movie& other) : Content(other), runtime(other.runtime)
{
};

Movie& Movie::operator=(const Movie& other)
{
    if (this != &other)
        this->runtime = other.runtime;
    return *this;
}

std::string Movie::getTitle() const
{
    return title;
}

ifstream& operator>>(ifstream& fin, Movie& movie)
{
    fin >> movie.title >> movie.rating >> movie.ageRating >> movie.runtime;
    return fin;
}

ostream& operator<<(ostream& out, const Movie& movie)
{
    out << "Title: " << movie.title << '|' << "Age Rating: " << movie.ageRating << '|' << "Rating: " << movie.rating <<
        '|' << "Total runtime: " << movie.runtime ;
    return out;
}

void Movie::addActor(Actor* actor)
{
    actors.push_back(actor);
}

Movie::~Movie()
{
    runtime.clear();
}

void Movie::readFile(ifstream& mfin, std::vector<Movie>& movies)
{
    Movie movie;
    while (mfin>>movie)
        movies.push_back(movie);
}
