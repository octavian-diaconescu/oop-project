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

    friend std::ostream &operator<<(std::ostream &os, const Watchlist &watchlist);

    void addContent(const std::shared_ptr<Content>&);

    // const std::vector<std::shared_ptr<Content>>& contentsReference() const;

    void setName(std::string);

    [[nodiscard]] int getID() const;

    void printContents() const;

    [[nodiscard]] std::vector<std::shared_ptr<Content>> getContents() const;

    [[nodiscard]] std::string getName() const;

    ~Watchlist() = default;

};
