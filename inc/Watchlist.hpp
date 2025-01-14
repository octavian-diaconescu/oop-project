#pragma once
#include <memory>
#include "Content.hpp"
#include <vector>

class Watchlist {
    std::vector<std::shared_ptr<Content>> contents;
    std::string name;
    int id;
    static int cnt;

public:
    Watchlist();

    void addContent(const std::shared_ptr<Content>&);

    Watchlist &operator+(const std::string &);

    Watchlist &operator<<=( std::ostream &) const;

    Watchlist &operator>>=( std::istream &);

    static int getCnt() ;

    void deleteContent(const std::string &title);

    void deleteWatchlist();

    [[nodiscard]] int getID() const;

    void printContents() const;

    [[nodiscard]] const std::vector<std::shared_ptr<Content>>& getContents() const;

    [[nodiscard]] const std::string& getName() const;

};
