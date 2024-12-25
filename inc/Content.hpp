#pragma once
#include <string>

#include "Category.hpp"

class Content {
protected:
    std::string title;
    float rating = 0.0; //out of 10
    std::string ageRating = "empty"; //rated R, PG, etc.;
    bool progress = true; //0 for watched, 1 for want to watch
    bool inWatchlist = false;
    std::string userRating = "empty";
    Category category = Category();

public:
    Content() = default;

    Content(std::string, float, std::string);

    Content(const Content &) = default;

    Content &operator=(const Content &) = default;

    [[nodiscard]] virtual std::string getTitle() const = 0;

    [[nodiscard]] const Category &getCategory() const;

    void userRates();

    void updateProgress();

    void IsinWatchlist();

    [[nodiscard]] bool getWatchlistStatus() const;

    virtual void printInfo() const = 0;

    virtual ~Content() = default;
};

