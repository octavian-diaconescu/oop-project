#pragma once
#include <string>

#include "Category.hpp"

class Content {
protected:
    std::string title;
    float rating; //out of 10
    std::string ageRating; //rated R, PG, etc.;
    bool progress; //0 for watched, 1 for want to watch
    bool inWatchlist;
    std::string userRating;
    Category category;

public:
    Content();

    Content(std::string, float, std::string);

    Content(const Content &) = default;

    Content &operator=(const Content &) = default;

    [[nodiscard]] virtual std::string getTitle() const = 0;

    void userRates();

    void updateProgress();

    void IsinWatchlist();

    [[nodiscard]] bool getWatchlistStatus() const;

    virtual void printInfo() const = 0;

    virtual ~Content() = default;
};

