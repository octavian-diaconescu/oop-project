#include "Content.hpp"
#include <iostream>
#include <utility>


Content::Content(std::string  T, const std::string& R, std::string  ageR) : title(std::move(T)), rating(R), ageRating(std::move(ageR)), userRating("undefined"), category("empty") {}

Content::Content(std::string  Title, const std::string& R, std::string  ageR, const bool prog, std::string  userR, const Category & cat) : title(std::move(Title)), rating(R), ageRating(std::move(ageR)), progress(prog), userRating(std::move(userR)), category(cat) {
};


const std::string& Content::getTitle() const{
    return title;
}

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

