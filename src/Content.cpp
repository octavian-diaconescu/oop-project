#include "Content.hpp"
#include <iostream>
#include <utility>

Content::Content(): title("empty"), rating(0), ageRating("empty"), progress(true), inWatchlist(false), userRating("undefined"), category("empty"){};

Content::Content(std::string  T, const float R, std::string  ageR) : title(std::move(T)), rating(R), ageRating(std::move(ageR)), progress(true), inWatchlist(false), userRating("undefined"), category("empty") {};


const Category &Content::getCategory() const {
    return category;
}

void Content::userRates() {
    std::cin.ignore();
    std::string var;
    std::cout << "Your rating: ";
    getline(std::cin, var);
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
