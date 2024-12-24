#include "Watchlist.hpp"
#include <iostream>
#include <TVShow.hpp>
#include <utility>
#include <vector>

#include "Movie.hpp"
using namespace std;

int Watchlist::cnt = -1;

Watchlist::Watchlist() : name("watchlist"), id(++cnt) {
}

void Watchlist::setName(string n) {
  name = move(n);
}

void Watchlist::addContent(const shared_ptr<Content> &content) {
  contents.push_back(content);
}

// const std::vector<std::shared_ptr<Content> > &Watchlist::contentsReference() const {
//   return contents;
// }

int Watchlist::getID() const {
  return id;
}

void Watchlist::printContents() const {
  cout << "Movies in watchlist: " << endl;
  for (const auto &content: contents)
    if (dynamic_cast<Movie *>(content.get())) {
      const auto *movie = dynamic_cast<Movie *>(content.get());
      movie->printInfo();
    }
  cout << "TV Shows in watchlist: " << endl;
  for (auto content: contents)
    if (dynamic_cast<TVShow *>(content.get())) {
      const auto *tvs = dynamic_cast<TVShow *>(content.get());
      tvs->printInfo();
    }
}

vector<shared_ptr<Content> > Watchlist::getContents() const {
  return contents;
}

string Watchlist::getName() const {
  return name;
}


//Watchlist::~Watchlist() {
//  contents.clear();
//  name.clear();
//}


std::ostream &operator<<(std::ostream &os, const Watchlist &watchlist) {
  os << watchlist.id << " " << watchlist.name << endl;
}
