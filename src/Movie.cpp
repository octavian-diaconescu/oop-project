#include "Movie.hpp"

#include <Exceptions.hpp>

#include "Factory.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

Movie::Movie(const std::string & Title, const std::string & ageR, const std::string& R, std::string  rt, const Category & cat,
    const std::string & userR, const bool prog) : Content(Title, R, ageR, prog, userR, cat), runtime(std::move(rt)) {
}

istream& operator>>(istream& in, Movie& movie)
{
    in >> movie.title >> movie.rating >> movie.ageRating >> movie.runtime >> movie.category;
    return in;
}

void Movie::readFile(istream& mfin, std::vector<Movie>& movies)
{
    const ShortContent factory;
    const auto content = factory.createLongContent();
    try {
        auto *movie = dynamic_cast<Movie *>(content.get());
        while (mfin >> *movie)
        movies.push_back(*movie);
    }
    catch (const UpcastError &e) {
        cerr << e.what() << endl;
    }
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


