#pragma once
#include <string>
#include "Content.hpp"

class Episode : public Content {
    std::string epS; //S01Ep01
    std::string runtime;
public:
    Episode()  : epS("empty"), runtime("empty") {};

    Episode(const Episode &);

    Episode &operator=(const Episode &);

    void printInfo() const override;

    friend std::istream &operator>>(std::istream &, Episode &);

    // friend std::ostream &operator<<(std::ostream &, const Episode &);

    ~Episode() override = default;
};
