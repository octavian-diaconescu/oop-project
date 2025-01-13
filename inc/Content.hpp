#pragma once
#include <string>

#include "Category.hpp"

class Content {
protected:
    std::string title;
    std::string rating; //out of 10
    std::string ageRating; //rated R, PG, etc.;
    bool progress; //0 for watched, 1 for want to watch
    bool inWatchlist{};
    std::string userRating;
    Category category;

public:
    Content() : title("empty"), rating("emtpy"), ageRating("empty"), progress(true), userRating("empty") {
    };

    // Content(std::string, const std::string&, std::string);

    explicit Content(std::string , const std::string&, std::string , bool, std::string , const Category&);

    // Content(const Content &) = default;

    // Content &operator=(const Content &) = default;

    [[nodiscard]] const std::string& getTitle() const;

    [[nodiscard]] const Category &getCategory() const;

    void userRates();

    void updateProgress();

    void IsinWatchlist();

    [[nodiscard]] bool getWatchlistStatus() const;

    virtual void printInfo() const = 0;

    virtual void saveInfo(std::ostream&) const;

    virtual ~Content() = default;
};

