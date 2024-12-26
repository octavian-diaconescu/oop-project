#pragma once
#include "Content.hpp"
#include "Movie.hpp"
#include "TVShow.hpp"
using namespace std;
class MovieBuilder {
    Movie movie;

public:
   const Movie& build();

    // MovieBuilder& setTitle(const string& t);
    //
    // MovieBuilder& setRating(const float r) {
    //     movie.rating = r;
    //     return *this;
    // }
    //
    // MovieBuilder& setRuntime(const string& rt) {
    //     movie.runtime = rt;
    //     return *this;
    // }
    //
    // MovieBuilder& setCategory(const string& c) {
    //     movie.category = c;
    //     return *this;
    // }
};
class TVShowBuilder {
    TVShow tvshow;

public:
    const TVShow& build();
    // TVShowBuilder& setTitle(const string& t) {
    //     tvshow.title = t;
    //     return *this;
    // }
    //
    // TVShowBuilder& setRating(float r) {
    //     tvshow.rating = r;
    //     return *this;
    // }
    //
    // TVShowBuilder& setCategory(const string& c) {
    //     tvshow.category = c;
    //     return *this;
    // }
    //
    // TVShowBuilder& addEpisode(const Episode& ep) {
    //     tvshow.episodes.push_back(ep);
    //     return *this;
    // }
};


