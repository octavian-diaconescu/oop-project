#include "Content.hpp"
#include <iostream>
#include <utility>

Content::Content(): title(" "), rating(0), ageRating(" "), progress(true), inWatchlist(false), userRating("undefined"), category("empty"){};

Content::Content(std::string  T, const float R, std::string  ageR) : title(std::move(T)), rating(R), ageRating(std::move(ageR)), progress(true), inWatchlist(false), userRating("undefined"), category("empty") {};

void Content::userRates() {
    std::string var;
    std::cout << "Your rating: ";
    std::cin >> var;
    userRating = var;
}

void Content::updateProgress() {
    progress = false;
}

void Content::IsinWatchlist() {
    inWatchlist = true;
}

bool Content::getWatchlistStatus() const {
    return inWatchlist;
}

//Content::~Content(){title.clear(), rating = 0, ageRating.clear();}
