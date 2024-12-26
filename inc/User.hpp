#pragma once
#include <string>
#include <vector>

#include "Movie.hpp"
#include "TVShow.hpp"
#include "Watchlist.hpp"

class User {
  std::string fullName; // Lastname Firstname
  std::string birthDate; //yyyy.mm.dd
  std::string preferredLanguage; //EN, FR, RO, etc
  std::string username;
  std::vector<Watchlist> watchlist;
  static User uniqueInstance;
  [[maybe_unused]] int data;

  explicit User(int d = 0);

  User &operator=(const User &) = default;

  User(const User &) = default;

public:
  static User &instance();

  friend std::istream &operator>>(std::istream &, User &);

  friend std::ostream &operator<<(std::ostream &, const User &);

  void printWatchlistContents() const;

  //static void registerUser(User&);

  void createWatchlist();

  void addMovie(std::vector<Movie> &);

  void addTVShow(std::vector<TVShow> &);

  void markAsWatched() const;

  void listSorted() const;

  [[nodiscard]] int checkWatchlist() const;

  ~User() = default;
};
