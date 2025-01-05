#include <fstream>
#include "TVShow.hpp"
#include "Factory.hpp"
#include <iostream>

using namespace std;


istream &operator>>(istream &in, TVShow &tvshow) {
    in >> tvshow.title >> tvshow.rating >> tvshow.ageRating >> tvshow.category;
    return in;
}

ostream &operator<<(ostream &out, const TVShow &obj) {
    out << obj.title << "| " << obj.rating << "| " << obj.ageRating << "| " << obj.category;
    return out;
}

TVShow::TVShow(const std::string &Title, const std::string &ageR, const std::string& R, const Category & cat, const std::string & userR, const bool prog) : Content(Title, R, ageR, prog, userR, cat) {
}

void TVShow::printInfo() const {
    cout << "Title: " << title << '|' << "Age Rating: " << ageRating << '|' << "Rating: " << rating << "|Category: " <<
            category << "|Your Rating: "  << userRating;
    if (progress)
        cout << "|Progress: want to watch" << endl;
    else
        cout << "|Progress: watched" << endl;
}

void TVShow::populateEpisodes(istream &in) {
    const ShortContent factory;
    const auto content = factory.createShortContent();
    auto *eps = dynamic_cast<Episode*>(content.get());
    while (in >> *eps) {
        this->episodes.push_back(*eps);
    }
}

void TVShow::printEpisodes(const string &Title) const {
    if (title == Title) {
        for (const auto &episode: episodes)
            cout << episode;
    }
    cout << endl;
}

void TVShow::saveInfo(ostream & os) const {
    os << "Title: " << title << '|' << "Age Rating: " << ageRating << '|' << "Rating: " << rating << "|Category: " <<
            category << "|Your Rating: "  << userRating;
    if (progress)
        os << "|Progress: want to watch" << endl;
    else
        os << "|Progress: watched" << endl;
}

void TVShow::readFile(istream &sfin, vector<TVShow> &vector) {
    const LongContent factory;
    const auto content = factory.createLongContent();
    auto *tvshow = dynamic_cast<TVShow *>(content.get());
    while (sfin >> *tvshow)
        vector.push_back(*tvshow);
}


