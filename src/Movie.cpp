#include "Movie.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include "Abstract Factory.hpp"
using namespace std;

Movie::Movie(const std::string &title, const std::string &ageRating, const float R) : Content(title, R, ageRating) {
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


void Movie::readFile(istream& mfin, std::vector<Movie>& movies)
{
    const MovieFactory factory;
    const auto content = factory.createContent();
    auto* movie = dynamic_cast<Movie*>(content.get());
    while (mfin >> *movie)
        movies.push_back(*movie);
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


