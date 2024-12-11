#pragma once
#include "Movie.hpp"
#include "TVShow.hpp"

#include <vector>

class Watchlist
{
    std::vector<Movie> movies;
    std::vector<TVShow> TVShows;
public:
    Watchlist(std::vector<Movie>, std::vector<TVShow>);
    void setMovies();
    void setTV_Shows();
    ~Watchlist() = default;
};