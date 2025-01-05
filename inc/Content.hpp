#pragma once
#include <string>

#include "Category.hpp"

class Content {
protected:
    std::string title;
    std::string rating = "empty"; //out of 10
    std::string ageRating = "empty"; //rated R, PG, etc.;
    bool progress = true; //0 for watched, 1 for want to watch
    bool inWatchlist = false;
    std::string userRating = "empty";
    Category category;

public:
    Content() = default;

    Content(std::string, const std::string&, std::string);

    Content(std::string , const std::string&, std::string , bool, std::string , const Category&);

    Content(const Content &) = default;

    Content &operator=(const Content &) = default;

    [[nodiscard]] const std::string& getTitle() const;

    [[nodiscard]] const Category &getCategory() const;

    void userRates();

    void updateProgress();

    void IsinWatchlist();

    [[nodiscard]] bool getWatchlistStatus() const;

    virtual void printInfo() const = 0;

    virtual ~Content() = default;
};

