#pragma once
#include <string>
#include "Content.hpp"

class Episode : public Content {
    std::string epS; //S01Ep01
    std::string runtime;

public:
    Episode() = default;

    // explicit Episode(const std::string &, std::string ,std::string, float);

    Episode(const Episode &) = default;

    Episode &operator=(const Episode &) = default;

    // Episode &operator+(const Episode &);

    void printInfo() const override;

    [[nodiscard]] std::string getTitle() const override;

    friend std::istream &operator>>(std::istream &, Episode &);

    friend std::ostream &operator<<(std::ostream &, const Episode &);

    ~Episode() override = default;
};
