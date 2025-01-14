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

    friend std::istream &operator>>(std::istream &, TVShow &);

    void printInfo() const override;

    void populateEpisodes(std::istream &);

    void printEpisodes(const std::string&) const ;

    void saveInfo(std::ostream&) const override;

    static void readFile(std::istream &sfin, std::vector<TVShow> &vector);
};
