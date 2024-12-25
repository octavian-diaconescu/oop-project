#pragma once
#include <TVShow.hpp>
#include "Actor.hpp"
#include "Movie.hpp"

class Menu {
    int data;

    explicit Menu(const int d = 0) : data(d) {
    }

    static Menu uniqueInstance;

    Menu(const Menu &);

    Menu &operator=(const Menu &) = default;

public:
    static Menu &instance();

    ~Menu() = default;

    static void run();

    static void populateDB(std::vector<Movie> &, std::vector<TVShow> &);
};
