#include <fstream>
#include <TVShow.hpp>
#include <iostream>
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

// vector<Episode> *TVShow::getEpisodes() {
//     return &episodes;
// }

std::string TVShow::getTitle() const {
    return title;
}

void TVShow::populateEpisodes(istream &in) {
    Episode eps;
    //int j = 0, size = 0;
    while (in >> eps) {
        // show.episodes.resize(++size);
        // show.episodes[j++] + eps;
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
    TVShow tvshow;
    while (sfin >> tvshow)
        vector.push_back(tvshow);
}


