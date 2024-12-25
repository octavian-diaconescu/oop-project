#include "Movie.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Movie::Movie() : Content(), runtime(" ")
// {
// }

// Movie::Movie(string  rt, const string& Title, const float R, const string& ageR) : Content(Title, R, ageR), runtime(std::move(rt))
// {
// }

// Movie::Movie(const Movie & other)  : Content(other) {
//     this->runtime = other.runtime;
// }


// Movie& Movie::operator=(const Movie& other)
// {
//     if (this != &other) {
//         this->runtime = other.runtime;
//     }
//     return *this;
// }

Movie::Movie() : Content(), runtime("empty"){
}

std::string Movie::getTitle() const
{
    return title;
}

istream& operator>>(istream& in, Movie& movie)
{
    in >> movie.title >> movie.rating >> movie.ageRating >> movie.runtime >> movie.category;
    return in;
}


ostream& operator<<(ostream& out, const Movie& movie)
{
    out << "Title: " << movie.title << '|' << "Age Rating: " << movie.ageRating << '|' << "Rating: " << movie.rating <<
        '|' << "Total runtime: " << movie.runtime << "|" << "Category: " << movie.category;
    return out;
}

// void Movie::addActor(Actor* actor)
// {
//     actors.push_back(actor);
// }

// Movie::~Movie()
// {
//     runtime.clear();
// }

void Movie::readFile(istream& mfin, std::vector<Movie>& movies)
{
    Movie movie;
    while (mfin >> movie)
        movies.push_back(movie);
}

void Movie::printInfo() const
{
    cout << "Title: " << title << '|' << "Age Rating: " << ageRating << '|' << "Rating: " << rating <<
            '|' << "Total runtime: " << runtime << '|' << "Category: " << category << "|Your Rating: "  << userRating << endl;
    if (progress)
        cout << "|Progress: want to watch" << endl;
    else
        cout << "|Progress: watched" << endl;
}


