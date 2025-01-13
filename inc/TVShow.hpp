#pragma once
#include <string>
#include <vector>
#include "Category.hpp"
#include "Content.hpp"
#include "Episode.hpp"

class TVShow : public Content {
    std::vector<Episode> episodes;
public:
    TVShow() = default;

    TVShow(const std::string&, const std::string&, const std::string&, const Category&,  const std::string&, bool );

    // TVShow(const TVShow &) = default;

    // TVShow &operator=(const TVShow &) = default;

    friend std::istream &operator>>(std::istream &, TVShow &);

    // friend std::ostream &operator<<(std::ostream &, const TVShow &);

    void printInfo() const override;

    void populateEpisodes(std::istream &);

    void printEpisodes(const std::string&) const ;

    void saveInfo(std::ostream&) const override;

    // ~TVShow() override = default;

    static void readFile(std::istream &sfin, std::vector<TVShow> &vector);
};
