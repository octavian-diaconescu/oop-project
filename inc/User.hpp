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
  int data;

  explicit User(const int d = 0) : data(d) {
  }

  User &operator=(const User &);

  User(const User &);

public:
  static User &instance();

  friend std::istream &operator>>(std::istream &, User &);

  friend std::ostream &operator<<(std::ostream &, const User &);

  void printWatchlistContents() const;

  //static void registerUser(User &);

  void createWatchlist();

  void addMovie(std::vector<Movie> &);

  void addTVShow(std::vector<TVShow> &);

  void markAsWatched() const;

  // void removeFromWatchlist() const;

  void deleteWatchlist();

 // void printWatchlist() const;

  [[nodiscard]] int checkWatchlist() const;

  ~User();
};
