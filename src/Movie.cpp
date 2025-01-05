#include "Movie.hpp"
#include "Factory.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

Movie::Movie(const std::string &title, const std::string &ageRating, const std::string& R) : Content(title, R, ageRating) {
}

Movie::Movie(const std::string & Title, const std::string & ageR, const std::string& R, std::string  rt, const Category & cat,
    const std::string & userR, const bool prog) : Content(Title, R, ageR, prog, userR, cat), runtime(std::move(rt)) {
}

istream& operator>>(istream& in, Movie& movie)
{
    in >> movie.title >> movie.rating >> movie.ageRating >> movie.runtime >> movie.category;
    return in;
}


ostream& operator<<(ostream& out, const Movie& movie)
{
    out << "Title: " << movie.title << '|' << "Age Rating: " << movie.ageRating << '|' << "Rating: " << movie.rating << '|' << "Total runtime: " << movie.runtime << "|" << "Category: " << movie.category;
    return out;
}


void Movie::readFile(istream& mfin, std::vector<Movie>& movies)
{
    const ShortContent factory;
    const auto content = factory.createLongContent();
    auto *movie = dynamic_cast<Movie *>(content.get());
    while (mfin >> *movie)
        movies.push_back(*movie);
}

void Movie::saveInfo(ostream& os) const {
    os << "Title: " << title << '|' << "Age Rating: " << ageRating << '|' << "Rating: " << rating << '|' << "Total runtime: " << runtime << '|' << "Category: " << category << "|Your Rating: "  << userRating;
    if (progress)
        os << "|Progress: want to watch" << endl;
    else
        os << "|Progress: watched" << endl;
}

void Movie::printInfo() const
{
    cout << "Title: " << title << '|' << "Age Rating: " << ageRating << '|' << "Rating: " << rating << '|' << "Total runtime: " << runtime << '|' << "Category: " << category << "|Your Rating: "  << userRating;
    if (progress)
        cout << "|Progress: want to watch" << endl;
    else
        cout << "|Progress: watched" << endl;
}


