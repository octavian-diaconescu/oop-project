#pragma once
#include <vector>
#include "Content.hpp"

class Watchlist
{
    std::vector<std::shared_ptr<Content>> contents;
    std::string name;
    int id;
    static int cnt;
public:
    Watchlist();
    // void setMovies();
    // void setTV_Shows();
    //void setName();
    ~Watchlist() = default;
};
