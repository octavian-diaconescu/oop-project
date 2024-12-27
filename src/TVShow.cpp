#include <fstream>
#include "TVShow.hpp"
#include <iostream>

#include "Builder.hpp"
using namespace std;


istream &operator>>(istream &in, TVShow &tvshow) {
    in >> tvshow.title >> tvshow.rating >> tvshow.ageRating;
    in >> tvshow.category;
    return in;
}

ostream &operator<<(ostream &out, const TVShow &obj) {
    out << obj.title << "| " << obj.rating << "| " << obj.ageRating << "| " << obj.category;
    return out;
}

void TVShow::printInfo() const {
    cout << "Title: " << title << '|' << "Age Rating: " << ageRating << '|' << "Rating: " << rating << "|Category: " <<
            category;
    if (progress)
        cout << "|Progress: want to watch" << endl;
    else
        cout << "|Progress: watched" << endl;
    cout << endl;
}

std::string TVShow::getTitle() const {
    return title;
}

void TVShow::populateEpisodes(istream &in) {
    auto eps = Episode();
    while (in >> eps) {
        this->episodes.push_back(eps);
    }
}

void TVShow::printEpisodes(const string &Title) const {
    if (title == Title) {
        for (const auto &episode: episodes)
            cout << episode;
    }
    cout << endl;
}

void TVShow::readFile(istream &sfin, std::vector<TVShow> &vector) {
    // TVShowBuilder builder;
    // TVShow tvshow = builder.build();
    TVShow tvshow{};
    while (sfin >> tvshow)
        vector.push_back(tvshow);
}


