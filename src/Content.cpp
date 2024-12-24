#include "Content.hpp"
#include <iostream>

Content::Content(): title(" "), rating(0), ageRating(" "){};

Content::Content(std::string T, float R, std::string ageR) : title(T), rating(R), ageRating(ageR) {};

Content::Content(const Content& other) : title(other.title), rating(other.rating), ageRating(other.ageRating) {};

std::string Content::getTitle() const {return title;}

Content::~Content(){title.clear(), rating = 0, ageRating.clear();};