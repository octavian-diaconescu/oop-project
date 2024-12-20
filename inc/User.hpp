#pragma once
#include <string>
#include <vector>
#include "Watchlist.hpp"

class User{
  std::string fullName;// Last_name First_name
  std::string birthDate;//yyyy.mm.dd
  std::string preferedLanguage;//EN, FR, RO, etc
  std::string username;
  std::vector<Watchlist> watchlist;

  static User uniqueInstance;
  int data{};
  explicit User(const int d = 0) : data(d){}
  User& operator=(const User&);
  User(const User&);
public:
  static User& instance();
  friend std::istream& operator>>(std::istream&, User&);
  friend std::ostream& operator<<(std::ostream&, const User&);
  static void registerUser(User&);
  ~User();
};
