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

// void Watchlist::setName(const string& n) {
//   name = n;
// }

void Watchlist::addContent(const shared_ptr<Content> &content) {
  contents.push_back(content);
}

Watchlist & Watchlist::operator+(const std::string &string) {
  name = string;
  return *this;
}


int Watchlist::getCnt() {
  return cnt;
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
    if (const auto *movie = dynamic_cast<Movie *>(content.get())) {
      movie->printInfo();
    }
  cout << "TV Shows in watchlist: " << endl;
  for (const auto& content: contents)
    if (const auto *tvs = dynamic_cast<TVShow *>(content.get())) {
      tvs->printInfo();
    }
}

const vector<shared_ptr<Content> >& Watchlist::getContents() const {
  return contents;
}

const string& Watchlist::getName() const {
  return name;
}


//Watchlist::~Watchlist() {
//  contents.clear();
//  name.clear();
//}


std::ostream &operator<<(std::ostream &os, const Watchlist &watchlist) {
  os << watchlist.id << " " << watchlist.name << endl;
  return  os;
}
