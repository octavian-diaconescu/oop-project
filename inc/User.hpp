#pragma once
#include <string>

class User{
  int id;
  std::string fullName;// Last_name First_name
  std::string birthDate;//yyyy.mm.dd
  std::string preferedLanguage;//En, Fr, Ro, etc
  static int cnt;
public:
  User();
  explicit User(std::string, std::string, std::string);
  User(const User&);
  User& operator=(const User&);
  friend std::ifstream& operator>>(std::ifstream&, User&);
  friend std::ostream& operator<<(std::ostream&, const User&);
  std::string getFullName() const;
  std::string getBirthDate() const;
  std::string getPreferedLanguage() const;
  void setFullName(const std::string);
  void setBirthDate(const std::string);
  void setPreferedLanguage(const std::string);
  static void readFile(std::ifstream&, std::vector<User>&);

  ~User();
};
