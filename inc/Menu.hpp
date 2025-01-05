#pragma once
#include "TVShow.hpp"
#include "Movie.hpp"
#include "User.hpp"

class Menu {
    int data;

    explicit Menu(const int d = 0) : data(d) {
    }

    static Menu uniqueInstance;

    Menu(const Menu &);

    Menu &operator=(const Menu &) = default;

    std::vector<User> users;

public:
    static Menu &instance();

    ~Menu() = default;

    void run();

    static void populateDB(std::vector<Movie> &, std::vector<TVShow> &);
};
