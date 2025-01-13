#include "Watchlist.hpp"
#include "TVShow.hpp"
#include "Movie.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <regex>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

int Watchlist::cnt = -1;

Watchlist::Watchlist() : name("watchlist"), id(++cnt) {
}

void Watchlist::addContent(const shared_ptr<Content> &content) {
  contents.push_back(content);
}

Watchlist &Watchlist::operator+(const string &string) {
  name = string;
  return *this;
}

Watchlist &Watchlist::operator<<=(ostream &os) const {
  os << endl;
  os << "Watchlist name: " << name << "|" << endl;
  os << "Movies in watchlist: " << endl;
  for (const auto &content: contents)
    if (const auto *movie = dynamic_cast<Movie *>(content.get())) {
      movie->saveInfo(os);
    }
  os << "TV Shows in watchlist: " << endl;
  for (const auto &content: contents)
    if (const auto *tvs = dynamic_cast<TVShow *>(content.get())) {
      tvs->saveInfo(os);
    }
  return const_cast<Watchlist &>(*this);
}

Watchlist &Watchlist::operator>>=(istream &is) {
  string line;
  string section;
  string wname;
  getline(is, wname, '|');
  wname = wname.substr(wname.find(':') + 2);
  name = wname;
  contents.clear();
  while (getline(is, line)) {
    if (line == "Movies in watchlist: ") {
      section = "movies";
      continue;
    }
    if (line == "TV Shows in watchlist: ") {
      section = "tvshows";
      continue;
    }
    if (line.empty()) {
      section.clear();
      continue;
    }

    istringstream lineStream(line);
    string title, ageRating, rating, category, userRating, progress;
    bool prog;

    getline(lineStream, title, '|');
    title = title.substr(title.find(':') + 2);

    getline(lineStream, ageRating, '|');
    ageRating = ageRating.substr(ageRating.find(':') + 2);

    getline(lineStream, rating, '|');
    rating = rating.substr(rating.find(':') + 2);

    if (section == "movies") {
      string runtime;

      getline(lineStream, runtime, '|');
      runtime = runtime.substr(runtime.find(':') + 2);

      getline(lineStream, category, '|');
      category = category.substr(category.find(':') + 2);

      getline(lineStream, userRating, '|');
      userRating = userRating.substr(userRating.find(':') + 2);

      getline(lineStream, progress, '|');
      progress = progress.substr(progress.find(':') + 2);

      if (progress == "watched")
        prog = false;
      else if (progress == "want to watch")
        prog = true;
      Category cat(category);
      auto movie = make_shared<Movie>(title, ageRating, rating, runtime, cat, userRating, prog);
      contents.push_back(movie);
    } else if (section == "tvshows") {
      getline(lineStream, category, '|');
      category = category.substr(category.find(':') + 2);

      getline(lineStream, userRating, '|');
      userRating = userRating.substr(userRating.find(':') + 2);

      getline(lineStream, progress, '|');
      progress = progress.substr(progress.find(':') + 2);
      if (progress == "watched")
        prog = false;
      else if (progress == "want to watch")
        prog = true;
      Category cat(category);
      auto tvShow = make_shared<TVShow>(title, ageRating, rating, cat, userRating, prog);
      contents.push_back(tvShow);
    }
  }

  return *this;
}

int Watchlist::getCnt() {
  return cnt;
}

int Watchlist::getID() const {
  return id;
}

void Watchlist::printContents() const {
  cout << "________________________________________________________________________" << endl;
  cout << "Movies in watchlist: " << endl;
  for (const auto &content: contents)
    if (const auto *movie = dynamic_cast<Movie *>(content.get())) {
      movie->printInfo();
    }
  cout << "________________________________________________________________________" << endl;
  cout << "TV Shows in watchlist: " << endl;
  for (const auto &content: contents)
    if (const auto *tvs = dynamic_cast<TVShow *>(content.get())) {
      tvs->printInfo();
    }
  cout << "________________________________________________________________________" << endl;
}

const vector<shared_ptr<Content> > &Watchlist::getContents() const {
  return contents;
}

const string &Watchlist::getName() const {
  return name;
}

void Watchlist::deleteContent(const std::string &title) {
  for (auto it = contents.begin(); it != contents.end(); ++it) {
    if ((*it)->getTitle() == title) {
      contents.erase(it);
      std::cout << "Content '" << title << "' has been removed from the watchlist.\n";
      return;
    }
  }
  std::cout << "Content '" << title << "' not found in the watchlist.\n";
}

void Watchlist::deleteWatchlist() {
  contents.clear();
  --cnt;
  cout << "Watchlist with id: " << id << " has been deleted" << endl;
}
